/* Copyright (C) 2017-2018 CounterFlow AI, Inc.
 *
 * You can copy, redistribute or modify this Program under the terms of
 * the GNU General Public License version 2 as published by the Free
 * Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

/* 
 *
 * author Randy Caldejon <rc@counterflowai.com>
 *
 */

#define _GNU_SOURCE

#include <sys/un.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <stdint.h>
#include <unistd.h>
#include <signal.h>
#include <syslog.h>
#include <pthread.h>
#include <errno.h>
#include <sys/stat.h>
#include <linux/limits.h>

#include "analyzer-threads.h"

#define DRAGONFLY_ROOT "DRAGONFLY_ROOT"
#define DRAGONFLY_DIR "/opt/dragonfly"

int g_chroot = 0;
int g_verbose = 0;
int g_drop_priv = 0;

uint64_t g_msgSubscribed = 0;
uint64_t g_msgReceived = 0;
uint64_t g_running = 1;
char *g_dragonfly_root = DRAGONFLY_DIR;

/*
 * ---------------------------------------------------------------------------------------
 *
 * ---------------------------------------------------------------------------------------
 */

void print_usage()
{
	printf("Usage: dragonfly [ap] -c -p -v -r <root dir>\n");
}

/*
 * ---------------------------------------------------------------------------------------
 *
 * ---------------------------------------------------------------------------------------
 */

int main(int argc, char **argv)
{
	struct stat sb;

	int option = 0;
	while ((option = getopt(argc, argv, "cipr:v")) != -1)
	{
		switch (option)
		{
		case 'c':
			g_chroot = 1;
			break;;
		case 'p':
			g_drop_priv = 1;
			break;
		case 'r':
			g_dragonfly_root = strdup(optarg);
			break;
		case 'v':
			g_verbose = 1;
			break;
		default:
			print_usage();
			exit(EXIT_FAILURE);
		}
	}

	if ((lstat(g_dragonfly_root, &sb) < 0) || !S_ISDIR(sb.st_mode))
	{
		fprintf(stderr, "DRAGONFLY_ROOT %s does not exist\n", g_dragonfly_root);
		exit(EXIT_FAILURE);
	}

	signal(SIGPIPE, SIG_IGN);
	openlog("dragonfly", LOG_PERROR, LOG_USER);
	pthread_setname_np(pthread_self(), "dragonfly");

	launch_lua_analyzers(g_dragonfly_root);

	while (g_running)
	{
		sleep(1);
	}
	closelog();

	return (EXIT_SUCCESS);
}

/*
 * ---------------------------------------------------------------------------------------
 */
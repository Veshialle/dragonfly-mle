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

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <syslog.h>
#include <pthread.h>
#include <errno.h>

#include "config.h"
#include "test.h"

#include "dragonfly-lib.h"
#include "dragonfly-io.h"

#define WAIT_INTERVAL 1

/*
 * ---------------------------------------------------------------------------------------
 *
 * ---------------------------------------------------------------------------------------
 */
void dragonfly_mle_test(const char *dragonfly_root)
{
	fprintf(stderr, "Running unit tests\n");

	if (chdir(dragonfly_root) != 0)
	{
		syslog(LOG_ERR, "unable to chdir() to  %s", dragonfly_root);
		exit(EXIT_FAILURE);
	}
	char *path = getcwd(NULL, PATH_MAX);
	if (path == NULL)
	{
		syslog(LOG_ERR, "getcwd() error - %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	syslog(LOG_INFO, "DRAGONFLY_ROOT: %s\n", path);
	free(path);

	char analyzer_dir[PATH_MAX];
	snprintf(analyzer_dir, sizeof(analyzer_dir), "%s/%s", dragonfly_root, ANALYZER_DIR);
	mkdir(analyzer_dir, 0755);

	char filter_dir[PATH_MAX];
	snprintf(filter_dir, sizeof(filter_dir), "%s/%s", dragonfly_root, FILTER_DIR);
	mkdir(filter_dir, 0755);

	char config_dir[PATH_MAX];
	snprintf(config_dir, sizeof(config_dir), "%s/%s", dragonfly_root, CONFIG_DIR);
	mkdir(config_dir, 0755);

	SELF_TEST0(dragonfly_root);
	sleep(WAIT_INTERVAL);

	SELF_TEST1(dragonfly_root);
	sleep(WAIT_INTERVAL);

	SELF_TEST2(dragonfly_root);
	sleep(WAIT_INTERVAL);

	SELF_TEST3(dragonfly_root);
	sleep(WAIT_INTERVAL);

	SELF_TEST4(dragonfly_root);
	sleep(WAIT_INTERVAL);

	SELF_TEST5(dragonfly_root);
	sleep(WAIT_INTERVAL);

	SELF_TEST6(dragonfly_root);
	sleep(WAIT_INTERVAL);

	SELF_TEST7(dragonfly_root);
	sleep(WAIT_INTERVAL);

	SELF_TEST8(dragonfly_root);
	sleep(WAIT_INTERVAL);

	SELF_TEST9(dragonfly_root);
	sleep(WAIT_INTERVAL);

	SELF_TEST10(dragonfly_root);
	sleep(WAIT_INTERVAL);

	rmdir(analyzer_dir);
	rmdir(filter_dir);
	rmdir(config_dir);
	exit(EXIT_SUCCESS);
}
/*
 * ---------------------------------------------------------------------------------------
 */


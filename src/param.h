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

#ifndef __PARAM_H__
#define __PARAM_H__

#define MAX_IO_VECTOR 64
#define MAX_WORKER_THREADS 1
#define MAX_ANALYZER_STREAMS 4
#define MAX_INPUT_STREAMS (MAX_ANALYZER_STREAMS / 2)
#define MAX_OUTPUT_STREAMS (MAX_ANALYZER_STREAMS / 2)

#define MAX_PIPE_LENGTH (MAX_IO_VECTOR * 4)
#define MAX_DATA_BLOCKS (MAX_PIPE_LENGTH * ((MAX_ANALYZER_STREAMS + MAX_INPUT_STREAMS + MAX_OUTPUT_STREAMS) ) + MAX_IO_VECTOR)

#define _MAX_BUFFER_SIZE_ 4096


#endif

/*
 * find_color_task_thread.h
 *
 */

#ifndef FIND_COLOR_TASK_THREAD_H_
#define FIND_COLOR_TASK_THREAD_H_

/* For usleep() */
//#include <unistd.h>
//#include <stdint.h>
//#include <stddef.h>

// Include local files
#include "Board.h"

#include "my_debug_files/debug.h"
#include "my_debug_files/color_sensor_debug.h"
#include "my_queue_files/color_task_queue.h"
#include "my_driver_files/color_sensor_driver.h"
#include "main_thread.h"


void *findColorTaskThread(void *arg0);

#endif /* FIND_COLOR_TASK_THREAD_H_ */

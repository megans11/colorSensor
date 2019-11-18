/*
 * testThread.h
 *
 */

#ifndef TEST_THREAD_H_
#define TEST_THREAD_H_

/* For usleep() */
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

#include <ti/drivers/GPIO.h>

#include "Board.h"

#include "my_driver_files/color_sensor_driver.h"
#include "my_queue_files/color_task_queue.h"
#include "my_callback_files/color_sensor_timer.h"
#include "find_color_task_thread.h"

#define TEST_COLOR_QUEUE 0
#define TEST_COLOR_DRIVER 0
#define TEST_COLOR_THREAD 1
#define TEST_ALL_QUEUES 0

void *testThread(void *arg0);

#endif /* TEST_THREAD_H_ */

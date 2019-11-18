/*
 *  ======== test_thread.c ========
 */

/* Board Header file */
#include "test_thread.h"
#include <stdio.h>
/*
 *  ======== mainThread ========
 */
void *testThread(void *arg0)
{
    // let things settle
//    sleep(3);

    int ret_val;
    unsigned int amount;

    /* Call driver init functions */
    GPIO_init();
    Timer_init();

    /* Configure the LED pin */
    GPIO_setConfig(COLOR_LED, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    /* Turn off user LED */
    GPIO_write(COLOR_LED, Board_LED_OFF);

    /* Configure the LED pin */
    GPIO_setConfig(ERROR_LED, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
   /* Turn off user LED */
    GPIO_write(ERROR_LED, Board_LED_OFF);





    // Initiate for tests
    // TEST COLOR QUEUE
    // CREATE COLOR TASK QUEUE 0
    // CREATE QUEUE SUCCESS
    if (TEST_COLOR_QUEUE && (create_ColorTaskQueue() != CREATE_QUEUE_SUCCESS)) {
        //failed

        GPIO_clearInt(COLOR_LED);
        GPIO_write(COLOR_LED, Board_GPIO_LED_ON);
        GPIO_clearInt(ERROR_LED);
        GPIO_write(ERROR_LED, Board_GPIO_LED_ON);

//        while (1) {} // failed
    }

    if (TEST_COLOR_DRIVER && (init_color_sensor_I2C() != I2C_INIT_SUCCESS))
    {
        GPIO_clearInt(COLOR_LED);
        GPIO_write(COLOR_LED, Board_GPIO_LED_ON);
        GPIO_clearInt(ERROR_LED);
        GPIO_write(ERROR_LED, Board_GPIO_LED_ON);
    }

    if (TEST_COLOR_DRIVER && (init_color_sensor_UART() != I2C_INIT_SUCCESS))
    {
        GPIO_clearInt(COLOR_LED);
        GPIO_write(COLOR_LED, Board_GPIO_LED_ON);
        GPIO_clearInt(ERROR_LED);
        GPIO_write(ERROR_LED, Board_GPIO_LED_ON);
    }


    if (TEST_COLOR_THREAD)
    {
//        getColor_ColorTaskQueue(243, COLOR_VALUE_RED);
    }

    if (TEST_COLOR_QUEUE)
    {
        getRedColor_ColorTaskQueue(243);
        ret_val = readMsg_MotorControlQueue(&amount);
        if (ret_val != MSG_TYPE_GET_RED){
            GPIO_clearInt(COLOR_LED);
            GPIO_write(COLOR_LED, Board_GPIO_LED_ON);
            GPIO_clearInt(ERROR_LED);
            GPIO_write(ERROR_LED, Board_GPIO_LED_ON);

//            while (1) {}; // spin
        }

        getBlueColor_ColorTaskQueue(243);
        ret_val = readMsg_MotorControlQueue(&amount);
        if (ret_val != MSG_TYPE_GET_BLUE){
            GPIO_clearInt(COLOR_LED);
            GPIO_write(COLOR_LED, Board_GPIO_LED_ON);
            GPIO_clearInt(ERROR_LED);
            GPIO_write(ERROR_LED, Board_GPIO_LED_ON);
//            while (1) {}; // spin
        }

        getGreenColor_ColorTaskQueue(243);
        ret_val = readMsg_MotorControlQueue(&amount);
        if (ret_val != MSG_TYPE_GET_GREEN){
            GPIO_clearInt(COLOR_LED);
            GPIO_write(COLOR_LED, Board_GPIO_LED_ON);
            GPIO_clearInt(ERROR_LED);
            GPIO_write(ERROR_LED, Board_GPIO_LED_ON);

//            while (1) {}; // spin
        }

    }


//    return ret_val;
}

/*
 *  ======== find_color_task_thread.c ========
 */

#include "find_color_task_thread.h"

/*
 *  ======== findColorTaskThread ========
 */
void *findColorTaskThread(void *arg0)
{
    // turn on board leds that signal activity
    GPIO_init();
    GPIO_setConfig(COLOR_TASK_LED, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_HIGH);
    GPIO_setConfig(ERROR_LED, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_HIGH);
    GPIO_write(COLOR_TASK_LED, 0);
    GPIO_write(ERROR_LED, 0);

    GPIO_setConfig(SENSOR_LED0, GPIO_CFG_OUT_STD | GPIO_CFG_OUT_LOW);
    /* Turn of color sensor LED */
    GPIO_write(SENSOR_LED0, Board_GPIO_LED_OFF);
//
    if (create_ColorTaskQueue() == CREATE_QUEUE_FAILURE)
    {
//        errorRoutine(CONTROL_QUEUE_CREATE_FAILURE);
        printf("Queue creation failed.\n");
    }
    else
    {
        printf("Queue creation succeeded\n");
    }

    init_color_sensor_I2C();
    init_color_sensor_UART();
    init_colorSensorTimer();

    // Command variables
    int msg_type;
    unsigned int msg_buffer;

    while (1) {

        char UARTBuffer[20];
        //uint16_t *r, *g, *b, *c;

        // blocking read from queue
        msg_type = readMsg_ColorTaskQueue(&msg_buffer);

        if (msg_type != READ_FAILURE)
        {
            GPIO_toggle(COLOR_TASK_LED);
            getRGB();

        }

        //print to UART

    }
}

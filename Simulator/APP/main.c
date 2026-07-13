#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"
#include "semphr.h"

#include "battery_data.h"
#include "comm_task.h"
#include "sensor_task.h"
#include "logger_task.h"
#include "fault_task.h"
#include "fault_data.h"
#include "system_state.h"
#include "heartbeat.h"

QueueHandle_t LoggerQueue;
QueueHandle_t CommQueue;
QueueHandle_t FaultQueue;

SemaphoreHandle_t UARTMutex;

TimerHandle_t HeartbeatTimer;

TaskHandle_t FaultTaskHandle;

SystemState_t SystemState = NORMAL_STATE;

int main(void)
{
    LoggerQueue = xQueueCreate(
                    10,
                    sizeof(BatteryData_t)
                );

    CommQueue = xQueueCreate(
                    10,
                    sizeof(BatteryData_t)
                );

    FaultQueue = xQueueCreate(
                    10,
                    sizeof(FaultInfo_t)
                );

    if((LoggerQueue == NULL) ||
       (CommQueue == NULL) ||
       (FaultQueue == NULL))
    {
        printf("Queue Creation Failed\n");

        while(1);
    }

    HeartbeatTimer = xTimerCreate(
                        "Heartbeat",
                        pdMS_TO_TICKS(3000),
                        pdTRUE,
                        NULL,
                        HeartbeatTimerCallback
                     );

    if(HeartbeatTimer == NULL)
    {
        printf("Timer Creation Failed\n");

        while(1);
    }

    UARTMutex = xSemaphoreCreateMutex();

    if(UARTMutex == NULL)
    {
        printf("Mutex Creation Failed\n");

        while(1);
    }

    xTaskCreate(
        SensorTask,
        "Sensor",
        256,
        NULL,
        2,
        NULL
    );

    xTaskCreate(
        LoggerTask,
        "Logger",
        256,
        NULL,
        2,
        NULL
    );

    xTaskCreate(
        FaultTask,
        "Fault",
        256,
        NULL,
        3,
        &FaultTaskHandle
    );

    xTaskCreate(
        CommTask,
        "Comm",
        256,
        NULL,
        1,
        NULL
    );

    xTimerStart(
        HeartbeatTimer,
        0
    );

    vTaskStartScheduler();

    while(1);

    return 0;
}
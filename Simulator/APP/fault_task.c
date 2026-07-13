#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#include "fault_task.h"
#include "fault_data.h"
#include "system_state.h"
#include "semphr.h"

extern SemaphoreHandle_t UARTMutex;

extern QueueHandle_t FaultQueue;
extern SystemState_t SystemState;

void FaultTask(void *pvParameters)
{
    FaultInfo_t fault;

    while(1)
    {
        if(xQueueReceive(
        FaultQueue,
        &fault,
        portMAX_DELAY
    ) == pdPASS)
{
    SystemState = FAULT_STATE;

    if(xSemaphoreTake(UARTMutex,
                      portMAX_DELAY) == pdTRUE)
    {
        printf("\n");
        printf("************************\n");
        printf("FAULT DETECTED\n");

        if(fault.overVoltage)
        {
            printf("OVER VOLTAGE\n");
        }

        if(fault.overCurrent)
        {
            printf("OVER CURRENT\n");
        }

        if(fault.overTemperature)
        {
            printf("OVER TEMPERATURE\n");
        }

        printf("RELAY TRIPPED\n");
        printf("************************\n");

        xSemaphoreGive(UARTMutex);
    }
}
    }
}
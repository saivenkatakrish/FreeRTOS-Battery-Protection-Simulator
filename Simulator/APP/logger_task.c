#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

#include "battery_data.h"
#include "logger_task.h"
#include "system_state.h"

extern QueueHandle_t LoggerQueue;
extern SystemState_t SystemState;
extern SemaphoreHandle_t UARTMutex;

void LoggerTask(void *pvParameters)
{
    BatteryData_t data;

   while(1)
{
    if(xQueueReceive(LoggerQueue,
                     &data,
                     portMAX_DELAY) == pdPASS)
    {
        if(xSemaphoreTake(UARTMutex,
                          portMAX_DELAY) == pdTRUE)
        {
            printf("\n");

            if(SystemState == NORMAL_STATE)
            {
                printf("STATE       : NORMAL\n");
            }
            else if(SystemState == FAULT_STATE)
            {
                printf("STATE       : FAULT\n");
            }
            else if(SystemState == RESET_REQUIRED_STATE)
            {
                printf("STATE       : RESET REQUIRED\n");
            }

            printf("Voltage     : %.2f V\n", data.voltage);
            printf("Current     : %.2f A\n", data.current);
            printf("Temperature : %.2f C\n", data.temperature);

            xSemaphoreGive(UARTMutex);
        }
    }
}
}
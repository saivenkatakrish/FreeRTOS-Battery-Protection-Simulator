#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "comm_task.h"

extern SemaphoreHandle_t UARTMutex;

void CommTask(void *pvParameters)
{
    while(1)
    {
        if(xSemaphoreTake(UARTMutex,
                  portMAX_DELAY) == pdTRUE)
{
    printf("\n");
    printf("[COMM] Battery Controller Running\n");

    xSemaphoreGive(UARTMutex);
}
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}
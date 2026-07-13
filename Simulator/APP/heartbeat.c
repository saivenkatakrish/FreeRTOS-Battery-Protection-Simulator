#include <stdio.h>

#include "FreeRTOS.h"
#include "timers.h"

#include "heartbeat.h"
#include "semphr.h"

extern SemaphoreHandle_t UARTMutex;

void HeartbeatTimerCallback(TimerHandle_t xTimer)
{
    if(xSemaphoreTake(UARTMutex, 0) == pdTRUE)
{
    printf("\n");
    printf("[HEARTBEAT] System Alive\n");

    xSemaphoreGive(UARTMutex);
}
}
#include <stdio.h>

#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"


#include "battery_data.h"
#include "sensor_task.h"
#include "fault_task.h"
#include "fault_data.h"

extern QueueHandle_t LoggerQueue;
extern QueueHandle_t CommQueue;
extern QueueHandle_t FaultQueue;

void SensorTask(void *pvParameters)
{
    BatteryData_t data;
    FaultInfo_t fault;

    static int faultLatched = 0;

    float voltage = 12.0f;
    float current = 2.0f;
    float temperature = 30.0f;

    while(1)
    {
        data.voltage = voltage;
        data.current = current;
        data.temperature = temperature;

        fault.overVoltage = 0;
        fault.overCurrent = 0;
        fault.overTemperature = 0;

        xQueueSend(LoggerQueue, &data, 0);

        xQueueSend(CommQueue, &data, 0);
        
        

if(data.voltage > 14.0f)
{
    fault.overVoltage = 1;
}

if(data.current > 10.0f)
{
    fault.overCurrent = 1;
}
if(data.temperature > 60.0f)
{
    fault.overTemperature = 1;
}

if((fault.overVoltage ||
    fault.overCurrent ||
    fault.overTemperature)
    &&
    faultLatched == 0)
{
    xQueueSend(FaultQueue, &fault, 0);

    faultLatched = 1;
}
        voltage += 0.1f;
        current += 0.2f;
        temperature += 1.0f;

        if(temperature > 80.0f)
        {
            temperature = 30.0f;
        }

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
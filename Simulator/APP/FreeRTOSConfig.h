#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#define configUSE_PREEMPTION                    1
#define configUSE_IDLE_HOOK                     0
#define configUSE_TICK_HOOK                     0

#define configCPU_CLOCK_HZ                      1000000
#define configTICK_RATE_HZ                      1000
#define configTICK_TYPE_WIDTH_IN_BITS TICK_TYPE_WIDTH_32_BITS
#define configMAX_PRIORITIES                    5

#define configMINIMAL_STACK_SIZE                128

#define configTOTAL_HEAP_SIZE                   (20 * 1024)

#define configMAX_TASK_NAME_LEN                 16

#define configUSE_MUTEXES                       1
#define configUSE_COUNTING_SEMAPHORES           1

#define configUSE_TIMERS                        1
#define configTIMER_TASK_PRIORITY               2
#define configTIMER_QUEUE_LENGTH                10
#define configTIMER_TASK_STACK_DEPTH            256

#define INCLUDE_vTaskDelay                  1
#define INCLUDE_vTaskDelete                 1
#define INCLUDE_vTaskSuspend                1
#define INCLUDE_vTaskPrioritySet            1
#define INCLUDE_vTaskPriorityGet            1

#endif

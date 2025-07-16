// FreeRTOSConfig.h
#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#include <avr/io.h>

#define configUSE_PREEMPTION            1
#define configUSE_IDLE_HOOK             0
#define configUSE_TICK_HOOK             0
#define configCPU_CLOCK_HZ              (F_CPU)
#define configTICK_RATE_HZ              ((TickType_t)1000)
#define configMAX_PRIORITIES            4
#define configMINIMAL_STACK_SIZE        85
#define configTOTAL_HEAP_SIZE           ((size_t)(1024))
#define configMAX_TASK_NAME_LEN         8
#define configUSE_TRACE_FACILITY        0
#define configUSE_16_BIT_TICKS          1
#define configIDLE_SHOULD_YIELD         1

#define configUSE_MUTEXES               1
#define configCHECK_FOR_STACK_OVERFLOW  0
#define configQUEUE_REGISTRY_SIZE       0
#define configUSE_RECURSIVE_MUTEXES     0
#define configUSE_MALLOC_FAILED_HOOK    0

#define INCLUDE_vTaskPrioritySet        1
#define INCLUDE_uxTaskPriorityGet       1
#define INCLUDE_vTaskDelete             1
#define INCLUDE_vTaskCleanUpResources   0
#define INCLUDE_vTaskSuspend            1
#define INCLUDE_vTaskDelayUntil         1
#define INCLUDE_vTaskDelay              1

#endif /* FREERTOS_CONFIG_H */


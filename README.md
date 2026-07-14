# FreeRTOS Battery Protection Simulator

## Overview

The FreeRTOS Battery Protection Simulator is an embedded systems project developed using FreeRTOS on a Windows-based simulator.

The project simulates a Battery Protection Controller that monitors battery voltage, current, and temperature while demonstrating key RTOS concepts such as task scheduling, inter-task communication, synchronization, fault handling, and state-machine design.

---

## Features

- FreeRTOS Task Management
- Queue-Based Inter-Task Communication
- Mutex Synchronization
- Software Timers
- Battery Parameter Monitoring
- Fault Detection and Fault Latching
- State Machine Implementation
- Simulated Communication Interface
- Heartbeat Monitoring

---

## System Architecture

<img width="1536" height="1024" alt="ChatGPT Image Jul 14, 2026, 12_54_41 PM" src="https://github.com/user-attachments/assets/6b9091b4-b4e3-4f81-8b14-7bc320a01353" />



## Implemented Tasks

| Task | Description |
|--------|------------|
| Sensor Task | Simulates battery voltage, current, and temperature |
| Logger Task | Logs battery parameters and system status |
| Comm Task | Simulates communication output |
| Fault Task | Detects and handles fault conditions |
| Heartbeat Timer | Indicates system activity |

---

## Fault Conditions

The simulator detects the following battery fault conditions:

- Over Voltage
- Over Current
- Over Temperature

When a fault occurs:

- Fault is latched
- System state changes to FAULT
- Protection action is triggered
- Fault information is logged

---

## RTOS Concepts Demonstrated

- Tasks
- Scheduler
- Queues
- Mutexes
- Software Timers
- State Machine Design
- Fault Management
- Inter-Task Communication

---

## Current Status

### Completed

- FreeRTOS Windows Simulator Setup
- Sensor Task
- Logger Task
- Communication Task
- Fault Task
- Queue-Based Communication
- Mutex Protection
- Software Timer Heartbeat
- Fault Detection and Latching
- System State Management

---

## Future Enhancements

- STM32 Hardware Porting
- ADC-Based Sensor Integration
- UART Driver Integration
- GPIO Driver Development
- Watchdog Integration
- Relay Control Implementation

---

## Technologies Used

- C Programming
- FreeRTOS
- Windows FreeRTOS Port
- Embedded Systems Design

---

## Author

Sai Venkata Krishna

Embedded Systems | Firmware Development | FreeRTOS

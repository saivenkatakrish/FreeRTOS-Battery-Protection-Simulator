# RTOS Based Smart Battery Protection Controller

## Objective

Develop an industrial-style battery protection controller using FreeRTOS and STM32.

The system will monitor:

- Voltage
- Current
- Temperature

The system will detect:

- Over Voltage
- Under Voltage
- Over Current
- Over Temperature

The system will provide:

- UART Command Line Interface
- Fault Logging
- Watchdog Monitoring
- Real-Time Task Scheduling

## Development Phases

### Phase 1
Windows FreeRTOS Simulation

### Phase 2
STM32 Porting

### Phase 3
Hardware Integration

## Planned Tasks

- Sensor Task
- Fault Task
- Logger Task
- UART Task
- Watchdog Task
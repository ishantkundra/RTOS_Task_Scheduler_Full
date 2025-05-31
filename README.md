# RTOS Task Scheduler (STM32 + FreeRTOS)

This is a simple RTOS-based scheduler example using STM32 HAL and FreeRTOS.

## Tasks:
- LED Task: Toggles LED every 500ms
- Sensor Task: Reads ADC value every 1000ms
- UART Task: Transmits status every 2000ms

## Requirements:
- STM32 board (e.g., STM32F4 Discovery)
- STM32CubeMX to generate HAL
- FreeRTOS source files
- GCC ARM toolchain

## How to Use:
1. Generate base STM32 project using STM32CubeMX and copy this into it.
2. Include FreeRTOS and HAL libraries.
3. Compile using Makefile or STM32CubeIDE.
4. Flash to board using ST-Link or OpenOCD.
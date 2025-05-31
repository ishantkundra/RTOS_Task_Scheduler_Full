#include "FreeRTOS.h"
#include "task.h"
#include "stm32f4xx_hal.h"
#include <string.h>

UART_HandleTypeDef huart2;
ADC_HandleTypeDef hadc1;

void SystemClock_Config(void);
void MX_GPIO_Init(void);
void MX_USART2_UART_Init(void);
void MX_ADC1_Init(void);

// Tasks
void vLEDTask(void *pvParameters);
void vSensorTask(void *pvParameters);
void vUARTTask(void *pvParameters);

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART2_UART_Init();
    MX_ADC1_Init();

    xTaskCreate(vLEDTask, "LED", 128, NULL, 1, NULL);
    xTaskCreate(vSensorTask, "Sensor", 128, NULL, 2, NULL);
    xTaskCreate(vUARTTask, "UART", 128, NULL, 1, NULL);

    vTaskStartScheduler();

    while (1) {}
}

void vLEDTask(void *pvParameters)
{
    while (1)
    {
        HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void vSensorTask(void *pvParameters)
{
    while (1)
    {
        HAL_ADC_Start(&hadc1);
        if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
        {
            uint32_t value = HAL_ADC_GetValue(&hadc1);
        }
        HAL_ADC_Stop(&hadc1);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void vUARTTask(void *pvParameters)
{
    char msg[] = "System running...\r\n";
    while (1)
    {
        HAL_UART_Transmit(&huart2, (uint8_t *)msg, strlen(msg), HAL_MAX_DELAY);
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}
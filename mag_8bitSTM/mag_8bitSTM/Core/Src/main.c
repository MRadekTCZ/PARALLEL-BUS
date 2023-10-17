/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "BUS_8bit.h"


uint8 MEMORY_IN[256];
uint8 MEMORY_FROM[256];
uint8 MOMORY_IN_ADDRESS_ITERATION;
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */


/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */





/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	//DATABYTES_TO_SEND = 200;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM10_Init();
  MX_TIM11_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim10);
  HAL_TIM_Base_Start_IT(&htim11);

#ifndef BUS_RECEIVE
  DATA_TO_MEM_8bit(3,0x0F, &MEMORY_IN[0]);
  DATA_TO_MEM_16bit(17,0x0AAA, &MEMORY_IN[0]);
  DATA_TO_MEM_32bit(189,0xC33C0FFA, &MEMORY_IN[0]);
#endif
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {


	#ifndef BUS_RECEIVE
	  DATA_SEND_TO_FPGA(MOMORY_IN_ADDRESS_ITERATION, MEMORY_IN[MOMORY_IN_ADDRESS_ITERATION]);

	  HAL_GPIO_WritePin(GPIOC, (Data_to_Bus.Bit_field.hex1) , GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOA, (Data_to_Bus.Bit_field.byte2<<4), GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOB, (Data_to_Bus.Bit_field.hex3<<12), GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9,GPIO_PIN_SET);
	#endif

	#ifdef BUS_RECEIVE
		Bus_to_Data.Bit_field.hex1 = (GPIOC->IDR & 0x000F);
		Bus_to_Data.Bit_field.byte2 = ((GPIOA->IDR & 0x0FF0)>>4);
		Bus_to_Data.Bit_field.hex3 = ((GPIOB->IDR & 0xF000)>>12);
		//Bus_to_Data.DataAdd;
	#endif
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	/*testowanie lacznosci - miganie diody z roznymi czestotliwosciami */

	if(htim->Instance == TIM10)
	{
		#ifndef BUS_RECEIVE
		MOMORY_IN_ADDRESS_ITERATION = MOMORY_IN_ADDRESS_ITERATION+1;
		if (MOMORY_IN_ADDRESS_ITERATION>DATABYTES_TO_SEND) MOMORY_IN_ADDRESS_ITERATION=0;

		HAL_GPIO_WritePin(GPIOC, (0xFFFF) , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, (0xFFFF), GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, (0xFFFF), GPIO_PIN_RESET);

		//DATA_SEND_TO_FPGA();
		#endif



	}
	if(htim->Instance == TIM11)
	{
		#ifdef BUS_RECEIVE
		MEMORY_FROM[Bus_to_Data.DataAdd.address] = Bus_to_Data.DataAdd.data;
		#endif
	}

}





/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */

  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

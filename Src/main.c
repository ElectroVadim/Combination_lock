/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "tim.h"
#include "gpio.h"

/* USER CODE BEGIN Includes */
#define SERVO_180  800
#define SERVO_0  200

/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
int fScanButtons();
void zanulS();
void zanulK();
int simvoly[8];
int kod[8];


/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM1_Init();

  /* USER CODE BEGIN 2 */

  HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

     int servo = 0;

     void set_pos(int pos) {

     float tmp = (float)(SERVO_180 - SERVO_0) / 4093 ;

     TIM1 -> CCR1 = ((int) SERVO_0 + tmp * pos)*16;
     }


     int perebor;



         for(perebor = 0;perebor<9;perebor++){
         	simvoly[perebor]=0;
     		kod[perebor]=0;
         }
         int d , dd = 0 , ddd = 0;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(dd==0){
	  	    		d = fScanButtons();
	  	    		if(d==11){
	  	    			dd++;
	  	    		}

	  	    	}

	  	    	if(d == 11)
	  	    	{
	  	    		if(kod[0]==0)
	  	    			{
	  	    			  			 	 kod[0] = fScanButtons();

	  	    			  			 }else if(kod[1]==0)
	  	    			  				 	{
	  	    			  				HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
	  	    			  				 	 	 kod[1] = fScanButtons();

	  	    			  				 	}else if(kod[2]==0)
	  	    			  				 		{
	  	    			  				 	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
	  	    			  				 				kod[2] = fScanButtons();

	  	    			  				 		}else if(kod[3]==0)
	  	    			  				 			  	{
	  	    			  				 		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,GPIO_PIN_SET);
	  	    			  				 			  	kod[3] = fScanButtons();
	  	    			  				 			  	}else if(kod[4]==0)
	  	    			  				 			  		{
	  	    			  				 			  	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
	  	    			  				 		 				kod[4] = fScanButtons();

	  	    			  				 			  		}else if(kod[5]==0)
	  	    			  				 			  		{
	  	    			  				 			  		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_SET);
	  	    			  				 			  			kod[5] = fScanButtons();
	  	    			  				 			  		}else if(kod[6]==0)
	  	    			  				 			  		{
	  	    			  				 			  		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_SET);
	  	    			  				 			  			kod[6] = fScanButtons();
	  	    			  				 			  		}else if(kod[7]==0)
	  	    			  				 			  		{
	  	    			  				 			  		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);
	  	    			  				 			  			kod[7] = fScanButtons();

	  	    			  				 			  		}else if(kod[7]!=0)
	  	    			  				 			  		{
	  	    			  				 			  		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15,GPIO_PIN_SET);
	  	    			  				 			  		if(ddd==0){


	  	    			  				 			  		//HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);
	  	    			  				 			  		    kod[8] = fScanButtons();
	  	    			  				 			  		}else{if(){
		  	    			  				 			  		zanulK();
		  	    			  				 			  		}
	  	    			  				 			  		}
	  	    			  				 			  		    if(17 == fScanButtons()){
	  	    			  				 			  		   HAL_GPIO_WritePin(GPIOC,GPIO_PIN_15,GPIO_PIN_SET);
	  	    			  				 			  	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_0,GPIO_PIN_SET);
	  	    			  				 			  	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_10,GPIO_PIN_SET);
	  	    			  				 			  	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_14,GPIO_PIN_SET);
	  	    			  				 			  	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_6,GPIO_PIN_SET);
	  	    			  				 			  	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_7,GPIO_PIN_SET);
	  	    			  				 			  	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_11,GPIO_PIN_SET);
	  	    			  				 			  	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_15,GPIO_PIN_SET);

	  	    	  				 			  		    //kod[8] = fScanButtons();


	  	    	  				 			  		   while (dd==1)

	  	    	  				 			  		     {


	  	    	  				 			  			   set_pos(1500);





	  	    	  				 			  			HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_SET);
	  	    	  				 			  		    HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_SET);
	  	    	  				 			  			if(simvoly[0] == 0)
	  	    	  				 			  					 {
	  	    	  				 			  						 simvoly[0] = fScanButtons();
	  	    	  				 			  						 if(simvoly[0] == kod[0]){
	  	    	  				 			  							 HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_SET);
	  	    	  				 			  						 }else{
	  	    	  				 			  							// zanul();
	  	    	  				 			  						 }


	  	    	  				 			  					 }else if(simvoly[1]==0)
	  	    	  				 			  						 {
	  	    	  				 			  						     simvoly[1] = fScanButtons();
	  	    	  				 			  						     if(simvoly[1] == kod[1]){
	  	    	  				 			  							 HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_SET);
	  	    	  				 			  						     }else{
	  	    	  	  				 			  							 //zanul();
	  	    	  	  				 			  						 }
	  	    	  				 			  						 }else if(simvoly[2]==0)
	  	    	  				 			  							 	{
	  	    	  				 			  							        simvoly[2] = fScanButtons();
	  	    	  				 			  							        if(simvoly[2] == kod[2]){
	  	    	  				 			  							 		HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_RESET);
	  	    	  				 			  							        }else{
	  	    	  	  	  				 			  							 //zanul();
	  	    	  	  	  				 			  						 }
	  	    	  				 			  							 	}else if(simvoly[3]==0)
	  	    	  				 			  							 		{
	  	    	  				 			  							 		    simvoly[3] = fScanButtons();
	  	    	  				 			  							 		   if(simvoly[3] == kod[3]){
	  	    	  				 			  							 			HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_RESET);
	  	    	  				 			  							 		   }else{
	  	    	  		  	  				 			  							// zanul();
	  	    	  		  	  				 			  						 }
	  	    	  				 			  							 		}else if(simvoly[4] == 0)
	  	    	  				  				 			  					 {
	  	    	  				  				 			  						 simvoly[4] = fScanButtons();
	  	    	  				  				 			  						 if(simvoly[4] == kod[4]){
	  	    	  				  				 			  							 HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_RESET);
	  	    	  				  				 			  						 }else{
	  	    	  		  	  				 			  							 //zanul();
	  	    	  		  	  				 			  						 }
	  	    	  				  				 			  					 }else if(simvoly[5]==0)
	  	    	  				  				 			  						 {
	  	    	  				  				 			  						     simvoly[5] = fScanButtons();
	  	    	  				  				 			  						     if(simvoly[5] == kod[5]){
	  	    	  				  				 			  							 HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_RESET);
	  	    	  				  				 			  						     }else{
	  	    	  			  	  				 			  							 //zanul();
	  	    	  			  	  				 			  						 }
	  	    	  				  				 			  						 }else if(simvoly[6]==0)
	  	    	  				  				 			  							 	{
	  	    	  				  				 			  							        simvoly[6] = fScanButtons();
	  	    	  				  				 			  							        if(simvoly[6] == kod[6]){
	  	    	  				  				 			  							        HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_SET);
	  	    	  				  				 			  							        }else{
	  	    	  				  	  	  				 			  							// zanul();
	  	    	  				  	  	  				 			  						 }
	  	    	  				  				 			  							 	}else if(simvoly[7]== 0)
	  	    	  				  				 			  							 		{
	  	    	  				  				 			  							 		    simvoly[7] = fScanButtons();
	  	    	  				  				 			  							 		   if(simvoly[7] == kod[7]){
	  	    	  				  				 			  							 			HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_SET);
	  	    	  				  				 			  							 		   }else{
	  	    	  				  	  	  				 			  							// zanul();
	  	    	  				  	  	  				 			  						 }

	  	  //  	  				  				 			  							 		   }else if(simvoly[8]== 0)
	  	  //  	  				  				 			  							 		   {
	  	  //  	  				  				 			  							 			   	   simvoly[8] = fScanButtons();
	  	  //  	  				  				 			  							 			   if(simvoly[8] == kod[8]){
	  	  //  	  				  				 			  							 				HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_SET);



	  	    	  				 			  							 			//simvoly[8] = fScanButtons();
	  	    	  				 			  							 			//if(simvoly[8] == kod[8]){
	  	    	  				 			  							 				HAL_GPIO_WritePin(GPIOD,GPIO_PIN_14,GPIO_PIN_SET);
	  	    	  				 			  							 				HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12,GPIO_PIN_SET);
	  	    	  				 			  							 				HAL_GPIO_WritePin(GPIOD,GPIO_PIN_13,GPIO_PIN_SET);
	  	    	  				 			  							 				HAL_GPIO_WritePin(GPIOD,GPIO_PIN_15,GPIO_PIN_SET);

	  	    	  				 			  							 				//for(perebor =0;perebor< 5;perebor++){
	  	    	  				 			  							 				//	if(simvoly[perebor]==kod[perebor]){

	  	    	  				 			  							 					//}else{
	  	    	  				 			  							 						simvoly[0]= 0;
	  	    	  				 			  							 						simvoly[1]= 0;
	  	    	  				 			  							 						simvoly[2]= 0;
	  	    	  				 			  							 						simvoly[3]= 0;
	  	    	  				 			  							 						simvoly[4]= 0;
	  	    	  				 			  							 						simvoly[5]= 0;
	  	    	  				 			  							 						simvoly[6]= 0;
	  	    	  				 			  							 						simvoly[7]= 0;
	  	    	  				 			  							 						simvoly[8]= 0;

	  	    	  				 			  							 					     dd =0;
	  	    	  				 			  							 					//}
	  	    	  				 			  							 					//simvoly[perebor] = 0;

	  	    	  				 			  							 			//}
	  	    	  				 			  							 		//}
	  	    	  				  				 			  				//}
	  	    	  				  				 			  		}
	  	    	  				 			  		     	 }

	  	    	  				 			  		   }

	  	    	  				 			  	}

	  	    	  				 		}


	    /* USER CODE END WHILE */

	    /* USER CODE BEGIN 3 */

	  	      }
	    /* USER CODE END 3 */

	  }

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL5;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV8;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV8;
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0);

  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* USER CODE BEGIN 4 */ /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void zanulS(){
	int i;
	for(i = 0;i<8;i++){
	    	simvoly[i]=0;
	    }

}
void zanulK(){
	int i;
	for(i = 0;i<8;i++){
	    	kod[i]=0;
	    }
}


//функци§ сканировани§ клавиатуры

int fScanButtons()
{
	//unsigned char simvol;
	int i ,j;//объ§вл§ю переменные

	for(i=0; i<4; i++)//запускаю цикл дл§ установки выходов в нуль
	{
		//устанавливаем нужный выход
			if(i==0){
				HAL_GPIO_WritePin(GPIOA,Row4_Pin,GPIO_PIN_SET);
			}
			else {
				HAL_GPIO_WritePin(GPIOA,Row4_Pin,GPIO_PIN_RESET);
			}

			if(i==1){
				HAL_GPIO_WritePin(GPIOA,Row3_Pin,GPIO_PIN_SET);
			}
			else{
				HAL_GPIO_WritePin(GPIOA,Row3_Pin,GPIO_PIN_RESET);
			}

			if(i==2){
				HAL_GPIO_WritePin(GPIOA,Row2_Pin,GPIO_PIN_SET);
			}
			else{
				HAL_GPIO_WritePin(GPIOA,Row2_Pin,GPIO_PIN_RESET);
			}

			if(i==3){
				HAL_GPIO_WritePin(GPIOA,Row1_Pin,GPIO_PIN_SET);
			}
			else{
				HAL_GPIO_WritePin(GPIOA,Row1_Pin,GPIO_PIN_RESET);
			}

		//portd = PORTD;
		//portd = (clm ^ 0xFF);//исключающее или, т.е. там где соответствующие биты равны 1 будет 0.
                //Например, clm = 0b00000001, тогда portd = 0b11111110;
		//PORTD = portd;//записываем в PORTD полученное значение
			j=0;
		for(j=0; j<4; j++)//цикл проверки входов
		{
			switch (j) {
				case 0: if((HAL_GPIO_ReadPin(GPIOA,Clm4_Pin))==GPIO_PIN_SET){
					HAL_Delay(300);
					switch (i) {
							case 0:
								return 17;
								break;
							case 1:
								return 16;
								break;
							case 2:
								return 0;
								break;
							case 3:
								return 15;
								break;
							default:
								break;
						}

					}

					break;
				case 1:
					if((HAL_GPIO_ReadPin(GPIOA,Clm3_Pin))==GPIO_PIN_SET){
						HAL_Delay(300);
						switch (i) {
								case 0:
									return 14;
									break;
								case 1:
									return 9;
									break;
								case 2:
									return 8;
									break;
								case 3:
									return 7;
									break;
								default:
									break;
						}
					}

					break;
				case 2:
					if((HAL_GPIO_ReadPin(GPIOA,Clm2_Pin))==GPIO_PIN_SET){
						HAL_Delay(300);
						switch (i) {
								case 0:
									return 12;
									break;
								case 1:
									return 6;
									break;
								case 2:
									return 5;
									break;
								case 3:
									return 4;
									break;
								default:
									break;
						}
					}

					break;
				case 3:
					if((HAL_GPIO_ReadPin(GPIOA,Clm1_Pin))==GPIO_PIN_SET){
						HAL_Delay(300);
						switch (i) {
								case 0:
									return 11;
									break;
								case 1:
									return 3;
									break;
								case 2:
									return 2;
									break;
								case 3:
									return 1;
									break;
								default:
									break;
						}
					}
					break;
				default:
					break;
			}

			//row=(1<<j);//устанавливаем вход, который будем смотреть
			//portd = (clm | row)^0xFF;//получаем код конкретной кнопки
			//if(portd == PIND)//провер§ем наличие этого кода

				//return simvol;//если код присутствует, возвращаем его значение
		}
	}

	return 0;//если ничего не совпало, возвращаем 0
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* USER CODE END 4 */

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

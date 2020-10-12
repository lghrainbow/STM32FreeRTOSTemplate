/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-7      SummerGift   first version
 */

#include "drv_common.h"
#include "board.h"



///* SysTick configuration */
//void hw_systick_init(void)
//{
//#if defined (SOC_SERIES_STM32H7)
//    HAL_SYSTICK_Config((HAL_RCCEx_GetD1SysClockFreq()) / RT_TICK_PER_SECOND);
//#elif defined (SOC_SERIES_STM32MP1)
//	HAL_SYSTICK_Config(HAL_RCC_GetSystemCoreClockFreq() / RT_TICK_PER_SECOND);
//#else
//    HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq() / RT_TICK_PER_SECOND);
//#endif
//#if !defined (SOC_SERIES_STM32MP1)
//    HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);
//#endif
//    NVIC_SetPriority(SysTick_IRQn, 0xFF);
//}



void HAL_SuspendTick(void)
{
}

void HAL_ResumeTick(void)
{
}

void ums_hw_us_delay(uint32_t us)
{
    uint32_t start, now, delta, reload, us_tick;
    start = SysTick->VAL;
    reload = SysTick->LOAD;
    us_tick = SystemCoreClock / 1000000UL;
    do {
        now = SysTick->VAL;
        delta = start > now ? start - now : reload + start - now;
    } while(delta < us_tick * us);
}

///* re-implement tick interface for STM32 HAL */
//HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
//{
//    /* Return function status */
//    return HAL_OK;
//}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void _Error_Handler(char *s, int num)
{
    /* USER CODE BEGIN Error_Handler */
    /* User can add his own implementation to report the HAL error return state */
    while(1)
    {
    }
    /* USER CODE END Error_Handler */
}



void HAL_GetUID(uint32_t *UID)
{
  UID[0] = (uint32_t)(READ_REG(*((uint32_t *)UID_BASE)));
  UID[1] = (uint32_t)(READ_REG(*((uint32_t *)(UID_BASE + 4U))));
  UID[2] = (uint32_t)(READ_REG(*((uint32_t *)(UID_BASE + 8U))));
}



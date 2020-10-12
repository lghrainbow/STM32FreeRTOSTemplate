

#ifndef __BOARD_H__
#define __BOARD_H__

#include <stm32f1xx.h>
#include "drv_common.h"
//#include "stm32f1xx_hal.h"

#define SOC_FAMILY_STM32
#define SOC_SERIES_STM32F1

/* Hardware Drivers Config */

#define SOC_STM32F103ZE

void SystemClock_Config(void);

#endif /* __BOARD_H__ */

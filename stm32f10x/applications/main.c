#include "FreeRTOS.h"
#include "cmsis_os.h"
#include "task.h"
#include "board.h"
#include "usart.h"


int main(void)
{
	HAL_Init();
	SystemClock_Config();
	uart_init(115200);
	
	
	while(1);
	
	return 0;
}






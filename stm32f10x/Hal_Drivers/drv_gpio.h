
#ifndef __DRV_GPIO__
#define __DRV_GPIO__

#include "board.h"

#define PIN_LOW                 0x00
#define PIN_HIGH                0x01

#define PIN_MODE_OUTPUT         0x00
#define PIN_MODE_INPUT          0x01
#define PIN_MODE_INPUT_PULLUP   0x02
#define PIN_MODE_INPUT_PULLDOWN 0x03
#define PIN_MODE_OUTPUT_OD      0x04

#define PIN_IRQ_MODE_RISING             0x00
#define PIN_IRQ_MODE_FALLING            0x01
#define PIN_IRQ_MODE_RISING_FALLING     0x02
#define PIN_IRQ_MODE_HIGH_LEVEL         0x03
#define PIN_IRQ_MODE_LOW_LEVEL          0x04

#define PIN_IRQ_DISABLE                 0x00
#define PIN_IRQ_ENABLE                  0x01

#define PIN_IRQ_PIN_NONE                -1


#define __STM32_PORT(port)  GPIO##port##_BASE

#if defined(SOC_SERIES_STM32MP1)
#define GET_PIN(PORTx,PIN) (long)((16 * ( ((long)__STM32_PORT(PORTx) - (long)GPIOA_BASE)/(0x1000UL) )) + PIN)
#else
#define GET_PIN(PORTx,PIN) (long)((16 * ( ((long)__STM32_PORT(PORTx) - (long)GPIOA_BASE)/(0x0400UL) )) + PIN)
#endif

#define __STM32_PIN(index, gpio, gpio_index)                                \
    {                                                                       \
        index, GPIO##gpio, GPIO_PIN_##gpio_index                            \
    }


/* STM32 GPIO driver */
struct pin_index
{
    int index;
    GPIO_TypeDef *gpio;
    uint32_t pin;
};

struct pin_irq_map
{
    uint16_t pinbit;
    IRQn_Type irqno;
};

struct ums_pin_irq_hdr
{
    int16_t        pin;
    uint16_t       mode;
    void (*hdr)(void *args);
    void             *args;
};



void stm32_pin_write(long pin, long value);
int stm32_pin_read(long pin);
void stm32_pin_mode(long pin, long mode);

long stm32_pin_attach_irq(int32_t pin, uint32_t mode, void (*hdr)(void *args), void *args);
long stm32_pin_dettach_irq(int32_t pin);
long stm32_pin_irq_enable(long pin, uint32_t enabled);

void hw_pin_init(void);

#endif /* __DRV_GPIO__ */

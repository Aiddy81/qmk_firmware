#pragma once
#define RP2040_MCUCONF

// I²C: using I2C1 on GP26/GP27
#define RP_I2C_USE_I2C0   0
#define RP_I2C_USE_I2C1   1

// USB: enable USBD0 so USBD1 is declared
#define RP_USB_USE_USBD0   1
#define RP_IRQ_USB0_PRIORITY 2

// UART: IRQ priorities
#define RP_IRQ_UART0_PRIORITY 2
#define RP_IRQ_UART1_PRIORITY 2

// I²C: IRQ priorities
#define RP_IRQ_I2C0_PRIORITY 2
#define RP_IRQ_I2C1_PRIORITY 2

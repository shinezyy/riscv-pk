#include "uartlite.h"

volatile uint8_t* uartlite;

#define UART_LITE_RX_FIFO    0x0
#define UART_LITE_TX_FIFO    0x4
#define UART_LITE_STAT_REG   0x8
#define UART_LITE_CTRL_REG   0xc

#define UART_LITE_RST_FIFO   0x03
#define UART_LITE_INTR_EN    0x10
#define UART_LITE_TX_FULL    0x08
#define UART_LITE_TX_EMPTY   0x04
#define UART_LITE_RX_FULL    0x02
#define UART_LITE_RX_VALID   0x01

void uartlite_putchar(uint8_t ch) {
  if (ch == '\n') uartlite_putchar('\r');

  while (uartlite[UART_LITE_STAT_REG] & UART_LITE_TX_FULL);
  uartlite[UART_LITE_TX_FIFO] = ch;
}

int uartlite_getchar() {
  if (uartlite[UART_LITE_STAT_REG] & UART_LITE_RX_VALID)
    return uartlite[UART_LITE_RX_FIFO];
  return -1;
}

void query_uartlite(uintptr_t fdt) {
  // Enable Rx/Tx channels
  uartlite = (void*)0x60000000;

  // Disable interrupts, Reset Rx/Tx FIFO
  uartlite[UART_LITE_CTRL_REG] = UART_LITE_RST_FIFO;
}

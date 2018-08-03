// See LICENSE for license details.
#ifndef _RISCV_UART_H
#define _RISCV_UART_H

#include <stdint.h>

// UART APIs
extern void query_uart(uintptr_t);
extern void uart_send(uint8_t);
extern void uart_send_string(const char *str);
extern void uart_send_buf(const char *buf, const int32_t len);
extern int uart_recv();
extern uint8_t uart_read_irq();
extern uint8_t uart_check_read_irq();
extern void uart_enable_read_irq();
extern void uart_disable_read_irq();

#endif

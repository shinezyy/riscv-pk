// See LICENSE for license details.

#ifndef UART_HEADER_H
#define UART_HEADER_H

#include <stdint.h>

// UART APIs
extern void uart_init();
extern void uart_send(uint8_t);
extern void uart_send_string(const char *str);
extern void uart_send_buf(const char *buf, const int32_t len);
extern uint8_t uart_recv();
extern uint8_t uart_read_irq();
extern uint8_t uart_check_read_irq();
extern void uart_enable_read_irq();
extern void uart_disable_read_irq();

#endif

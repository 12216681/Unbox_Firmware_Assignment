#define F_CPU 16000000UL
#include <avr/io.h>

void UART_init() {
    unsigned int ubrr = 103;  // 9600 baud for 16MHz

    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;

    UCSR0B = (1 << TXEN0);  // Enable transmitter
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8-bit data
}

void UART_transmit(char data) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}

void UART_sendString(char* str) {
    while (*str) {
        UART_transmit(*str++);
    }
}

void setup() {
    UART_init();
}

void loop() {
    UART_sendString("Hello from UART\r\n");

    for(long i = 0; i < 1600000; i++);
}
void setup() {
    // Set Pin 13 (PB5) as output
    DDRB |= (1 << DDB5);
}

void loop() {
    // Toggle Pin 13
    PORTB ^= (1 << PORTB5);

    // Delay ~500ms (software delay)
    for(long i = 0; i < 800000; i++);
}
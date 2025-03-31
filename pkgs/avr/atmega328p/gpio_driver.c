/*
#define __AVR_ATmega328P__
#include <avr/io.h>
#include "hardware/gpio.h"

static const gpio_pin_t max_pin = 19;

#define PORTX_MODIFY(X, pin, state) (state == true) ? (X |= (1 << pin)) : (X &= ~(1 << pin))
#define PINX_READ(X, pin) (bool)(X & (1 << pin))


struct {
    uint8_t dir;
    uint8_t af;    
} gpio_conf;

static bool _gpio_pin_assert(gpio_pin_t pin) {
    return (bool)(pin <= 19);
}

bool gpio_write(gpio_pin_t pin, gpio_state_t state) {
    if (!_gpio_pin_assert(state)) return false;
    if (pin < 8) {
        PORTX_MODIFY(PORTD, pin, state);
    } else if (pin < 14) {
        PORTX_MODIFY(PORTB, pin, state);
    } else {
        PORTX_MODIFY(PORTC, pin, state);
    }
    return true;
}

gpio_state_t gpio_read(gpio_pin_t pin) {
    if (!_gpio_pin_assert(pin)) return GPIO_UNDEF;
    if (pin < 8) {
        return PINX_READ(PIND, pin);
    } else if (pin < 14) {
        return PINX_READ(PINB, pin);
    } else {
        return PINX_READ(PINC, pin);
    }
}

bool gpio_mode(gpio_pin_t pin, const gpio_conf_t* config) {
    return 
}

bool gpio_adc(adc_value_t* value, adc_channel_t channel, const adc_conf_t* config) {

}

bool gpio_pwm(gpio_pin_t pin, pwm_value_t value) {

}
*/
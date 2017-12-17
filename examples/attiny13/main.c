/**
 * Copyright (c) 2017, Łukasz Marcin Podkalicki <lpodkalicki@gmail.com>
 *
 * This is ATtiny13 "Running Digits & Dots" example using attiny-max7219-led-tube-library,
 * https://github.com/lpodkalicki/attiny-max7219-led-tube-display-library
 */

#include <stdint.h>
#include <util/delay.h>
#include "max7219.h"

int
main(void)
{
	uint8_t i, j = 0;

	/* setup */
	MAX7219_init();
	MAX7219_set_intensity(8);

	/* loop */
	while (1) {
		for (i = 0; i < 8; ++i) {
			MAX7219_display_digit(i, (i + j) % 10);
		}
		MAX7219_clear_dot(j % 8);
		MAX7219_display_dot(++j % 8);
		_delay_ms(200);
	}
}

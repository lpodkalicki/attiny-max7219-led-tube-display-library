# MAX7219/MAX7221 7-segment LED Tube Display Library
This is tinyAVR (ATtiny13, ATtiny25, ATtiny45, ATtiny85) library for 7-segment LED tube display modules based on MAX7219/MAX7221 chip.

Modules based on MAX7219/MAX7221 provide three signal connections (CLK, DIN and CS) and two power connections (VCC and GND). Signal pins can be connected to any of digital pins of the AVR chip. Signal pins configuration is defined at the top of library header file, where it can be modifed.

## Key Features
This lightweight library has the following features:
* display digits
* display dots
* clear display
* brightness control
* software SPI

## Example Code
This example project of "Running Digits & Dots" demonstrates basic usage of the library:

```c
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
```

## API Documentation (max7219.h)

```c
/**
 * Initialize display driver.
 * Clock pin, data pin and chip select pin
 * are defined at the top of this file.
 */
void MAX7219_init(void);

/**
 * Display single digit at position.
 * @param position: dot position from range <0, 7>
 * @param digit: value from range <0, 9>
 */
void MAX7219_display_digit(uint8_t position, uint8_t digit);

/**
 * Light up 'dot' at position.
 * @param position: dot position from range <0, 7>
 */
void MAX7219_display_dot(uint8_t position);

/**
 * Turn off 'dot' at position.
 * @param position: dot position from range <0, 7>
 */
void MAX7219_clear_dot(uint8_t position);

/**
 * Set brightness of the display.
 * @param value: intensity from range <0, 15>
 */
void MAX7219_set_intensity(uint8_t value);

/**
 * Clear display.
 */
void MAX7219_clear(void);
```

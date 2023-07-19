# nOWire

A fun, silly little project to convert an OWire LED to a normal LED, negating all of the benefits of using OWire and resulting in a product that is worse than a regular LED in just about every way.

## Premise


Recently, I found some neat little LEDs that one can select the color of programmatically despite their only having 2 pins.

While there are many obvious use cases for such LEDs, it struck me as sad that they do not have a default state, and thus cannot be used for LED throwies.

This project remedies this by pairing each LED with an ATTINY85. The result is worse than a normal LED in nearly every way (with the exception of cbat mode). Compared to a normal LED, nOWire LED is:

- more expensive
- more bulky
- less bright
- less efficient
- less reliable
- has noticeable boot time
- labor intensive

But it does work as an LED throwie, and by soldering each pin of the ATTINY85 high, low, or leaving it floating, one can select from up to 84 different combinations of color and pattern
## Hardware needed:
- OWire LED
- ATTINY85
## Dependancies
- [OWire Library](https://github.com/sparkfun/SparkFun_OWire_Arduino_Library/tree/main)

## Available Modes:
Nearly all of the modes and colors are simply the ones builtin to the LED, and use the nomenclature used in the OWire library.

The exception is cbat mode, a new mode that flashes the LED in the specified color to the rhythm of cbat
## Instructions:
After loading this firmware on the ATTINY85, solder the OWire according to the picture, and solder the remaining ATTINY85 pins according to the table [TODO: add table]

 0 = low, 1 = high, 2 = floating, blank = doesn't matter

| 4 | 3 | 2 | 1 | 0 | Mode |
| --- | --- | --- | --- | --- | --- |
|0|0||||Solid|
|0|1||||8 Second Fade|
|0|2||||White Sparkles Slow|
|1|0||||Wave Fade|
|1|1||||Color Sparkles Slow|
|1|2||||White Sparkles Fast|
|2|0||||Color Blinks|
|2|1||||Color Sparkles Fast|
|2|2||||Cbat|
|||0|0|1|Red|
|||0|0|2|Green|
|||0|1|1|Yellow|
|||0|1|2|Blue|
|||1|0|1|Violet|
|||1|0|2|Cyan|
|||1|1|1|White|
|||2|0|1|Full Color|
|||2|0|2|Red Green WHite|
|||2|1|1|Red Blue White|
|||2|1|2|Six Color|

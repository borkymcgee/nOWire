# nOWire
A fun, silly little project to convert an OWire LED to a normal LED, negating all of the benefits of using OWire and resulting in a product that is worse than a regular LED in just about every way.

## Premise

Recently, I found some neat little LEDs that one can select the color of programmatically despite their only having 2 pins.

While there are many obvious use cases for such LEDs, it struck me as sad that they do not have a default state, and thus cannot be used for LED throwies.

This project remedies this by pairing each LED with an ATTINY85. The result is worse than a normal LED in nearly every way (with the exception of cbat mode). Compared to a normal LED, nOWire LED is:

- more expensive
- more bulky
- less dim
- less efficient
- less reliable
- has noticeable boot time

But it does work as an LED throwie, and by soldering each pin of the ATTINY85 high, low, or leaving it floating, one can select from up to [TODO: count permutations] different colors and patterns
## Hardware needed:
- OWire LED
- ATTINY85
## Construction:
After loading this firmware on the ATTINY85, solder the OWire according to the picture [TODO: add picture], and solder the remaining ATTINY85 pins according to the table [TODO: add table]

FM4
===

![../../Images/TODO.png?raw=true](TODO)

**To be done - this synth has not yet been built.**

This is a simple 4-op FM synthesizer similar to the Yamaha DX9 (the small brother
of the DX7) and the other 4-op FM synthesizers of the 1980s. It is a more or less
direct port of [../../Csound/Schoko%20FM4](Schoko FM4) built with Csound.

Parameters and the sonic quality are comparable to the Yamaha FM synths due to
careful listening tests made with a real DX7 Mk1. There are differences, however,
as the DX7 DSP math is limited by what was feasible in the early 1980s -- using
fixed-point math with limited resolution and some other clever tricks, that I didn't
try to recreate here. There are already [Dexed](https://asb2m10.github.io/dexed/),
[VDX7](https://github.com/chiaccona/VDX7) and others, that exactly do this.
Besides, what's the point? Csound and Puredata are interpreted languages where
emulating the exact math would be rather expensive, just to bring back all the
artefacts that were necessary but unwanted at the time?

_Screenshots, Demos etc. to come, once the synth has been built._

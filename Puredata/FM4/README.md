FM4
===

![TODO](../../Images/TODO.png?raw=true)

**To be done - this synth has not yet been built.**

This is a simple 4-op FM synthesizer similar to the Yamaha DX9 (the small brother
of the DX7) and the other 4-op FM synthesizers of the 1980s. It is a more or less
direct port of [../../Csound/Schoko%20FM4](Schoko FM4) built with Csound.

The parameters and sonic characteristics are comparable to those of the Yamaha
FM synthesizers, based on listening tests conducted with a genuine DX7 Mk1. However,
there are notable differences. The DSP processing of the DX7 is constrained by the
limitations of early 1980s technology, which relied on fixed-point math with limited
resolution, along with several other techniques that were not replicated here.
There are already existing emulators, such as [Dexed](https://asb2m10.github.io/dexed/),
[VDX7](https://github.com/chiaccona/VDX7), and others, that precisely recreate
these aspects. Furthermore, emulating the exact mathematical processes would be
inefficient in interpreted environments like Csound and Puredata, as it would incur
significant computational costs, only to reproduce artifacts that were inherent
yet undesirable in the original hardware.

_Listening Test with a real DX7_

![DX7 Listening Test](../../Images/DX7%20Listening%20Test.jpg?raw=true)

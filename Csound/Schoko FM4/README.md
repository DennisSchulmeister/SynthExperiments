Schoko FM4
==========

<img src="Screenshots/Rhodes%201%20(Default%20Sound).png?raw=true" alt="Screenshot">

[Demos on Samply](https://samply.app/p/KCnei0x2nOEXpUBnqafz)
[Demos here on Github](Demos/)

<iframe src="https://samply.app/embed/KCnei0x2nOEXpUBnqafz" frameborder="0" allowtransparency="true" style="width: 100%; border-radius: 16px; border: 1px solid rgba(255, 255, 255, 0.12)"></iframe>

This is a simple 4-op FM synthesizer similar to the Yamaha DX9 (the small brother
of the DX7) and the other 4-op FM synthesizers of the 1980s. This is the original
Csound instrument used to build [FM4 (PD)](../../Puredata/FM4) with Puredata.

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

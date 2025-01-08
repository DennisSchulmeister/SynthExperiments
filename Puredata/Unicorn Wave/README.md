Unicorn Wave
============

<img src="Screenshots/String%20Section%20(Default%20Sound).png?raw=true" alt="Screenshot">

[Demos on Samply](https://samply.app/p/yHQ1sIZ8EadgZIwAfyuz)
[Demos here on Github](Demos/)

<iframe src="https://samply.app/embed/yHQ1sIZ8EadgZIwAfyuz" frameborder="0" allowtransparency="true" style="width: 100%; border-radius: 16px; border: 1px solid rgba(255, 255, 255, 0.12)"></iframe>

This is by all means a true unicorn. 🦄 At its heart a wavetable synthesizer
using band-limited wavetables (one per octave, similar in principle as the
Korg DW-8000) combined with frequency modulation, additive synthesizes (up
to 16 harmonics for carrier and modulator) and a sprinkle of subtractive synthesis
(just some basic filters).

That alone would only be half-way special. But this patch is really an exercise
in applying clean code principles to Puredata and complexity of some of its
implementations:

 * Custom built **voice allocator** that handles re-triggering, sustain and sustenuto.

 * **Envelopes** with an unlimited number of breakpoints (20 in practice due to the
   limited width of the UI editor).

 * Rather **complex UI** including the aforementioned graphical envelope editor.
   Draw envelopes by dragging lines on a canvas.

 * **Preset management** to save and restore configuration values from local files.

 * **Variable wavetable sizes** to adjust sound quality vs. quickness during sound
   design, as the recalculation of the wave tables is rather costly.

The sound can be hit and miss but at least basic analogue pads, as demoed in
the String Section demo, sound quite nice.

The synthesis algorithm itself has okay performance on an Intel i7 notebook
from 2018, considering that the Puredata DSP code runs on a single core (unless
you implement multi-processing yourself with the `[pd~]` object). Still the
synth needs a few seconds to "warm up" when it is loaded, especially when the
UI is loaded, because the UI really is a CPU hog. (Four times more CPU load
than the synthesizer without UI!) Also recalculation of the wavetables when
harmonics are changed can be quite slow, depending on the wavetable size.
Therefore, for "quick "editing (in the sense of waiting only 2 seconds after
a parameter change) choose a small wavetable size in the bottom left corner
and then go to maximum once the sound is ready.

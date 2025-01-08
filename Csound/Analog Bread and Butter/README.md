Analog Bread and Butter
=======================

<img src="Screenshots/PWM%20Pad%20(Default%20Sound).png?raw=true" alt="Screenshot">

[Demos on Samply](https://samply.app/p/jM1I6JruowcWRwDIbZ3r)

[Demos here on Github](Demos/)

This is a very basic 2-oscillator subtractive synthesizer. It quickly emerged out
of the [Beginnger Synth](https://cabbageaudio.com/docs/beginner_synth/) tutorial
for Cabbage to try out Csound and Cabbage. Therefore it doesn't seek to be "feature
complete" but rather good enough to produce some usable sounds.

Each oscillator features the following parameters:

 * __Waveform:__ Sine, Saw, Square, PWM and Ramp -- the last two with variable width (using Csound's `vco2` opcode)
 * __Tuning:__ Transpose in half-note steps, detune ± 100 cents
 * __Volume:__ Peak amplitude (volume know) in dB, ADSR envelope, stereo panning
 * __Filter:__ Low-Pass filter with cut-off, resonance and variable slope (-6 dB to -48 dB)

There is one LFO whose amplitude can optionally be controlled with the Mod. Wheel
(MIDI CC1) or mono-phonic aftertouch. It can modulate the following parameters
to variable degrees (though always both oscillators are affected)

 * PWM/Ramp Width
 * Volume
 * Panorama
 * Frequency
 * Filter Cut-Off

There are three different play modes, inspired by the unison mode if synths like
the Roland Jupiter 8:

 * Single: The default, each note is triggered exactly once
 * Double: Unison mode in some hardware synths, two notes slightly detuned
 * Triple: Three notes slightly detuned

Unlike the hardware originals the polyphony is only limited by CPU capabilities.
Double and triple mode don't necessarily reduce the polyphony. The second and
third note in double and triple mode can be detuned and panned to increase the
sonic depth.

Finally there is a small but unique sounding global reverb, courtesy of Csound's
`reverbsc` opcode.

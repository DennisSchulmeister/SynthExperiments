Band-limited Wave Table Generator
=================================

![Screenshot](Screenshots/Main%20View.png?raw=true "Screenshot of the wave table generator")

This directory contains a small Puredata program to calculate band-limited
wave tables for different wave tables and octaves. The following waveforms
are currently supported:

 * Sine
 * Sawtooth
 * Square
 * Triangle

The resulting wave files are meant to be used with PD's `[tabosc4~]` object
which uses four-point polynomial interpolation. This requires the wave tables
to be a power of two in size plus three guard points - one at the beginning
and two at the end. These minute details are of course automatically handled
by PD but must be taken into account when using the waveforms in other
environments.

The wave tables are generated with a simple fourier synthesis, where a harmonic
series is formed between the highest note of the target octave and the Nyquist
frequency (PD's currently active sample rate divided by two).

The directories below [Wavetables/](./Wavetables/) contain pre-computed wave tables
generated with the program. The wave tables span one octave each, starting from
MIDI note 0, minus the last note that would start the next octave:

 * Wave table 1: MIDI Note 0 - 11
 * Wave table 2: MIDI Note 12 - 23
 * Wave table 3: MIDI Note 24 - 35
 * And so on

If less wave tables shall be used, the number of octaves per wave table can
be changed in the program. e.g. by setting this value to 2, only six wave tables
will be calculated with each wave table spanning two octaves.

Using the input field and the bang buttons on the right, the wave tables can
be saved to WAVE files.

Puredata Instruments and Utilities
==================================

1. [Directory Content](#directory-content)
1. [How to Use](#how-to-use)
1. [Main, Main, Main1, Main2](#main-main1-main2)
1. [Instruments](#instruments)
1. [Utilities](#utilities)

Directory Content
-----------------

This directory contains a collection of virtual instruments and utility programs
built using Puredata. These resources demonstrate how Puredata can be employed to
program real-time MIDI synthesizers and serves as a starting point for exploring
Puredata's capabilities and challenges.

First some screenshots and demos. Find more detailed descriptions below.
For more demos please see the [Main README file](../README.md).

<table>
    <tr>
        <td>
            <img src="Tuning%20Fork/Screenshots/Tuning%20Fork.png" width="300">
        </td>
        <td>
            <img src="Vanilla%20Sustain%20Pedal/Screenshots/Main%20Patch.png" width="300">
        </td>
        <td>
            <img src="Wave%20Table%20Generator/Screenshots/Main View.png" width="300">
        </td>
    </tr>
    <tr>
        <td>Tuning Fork</td>
        <td>Vanilla Sustain Pedal</td>
        <td>Wavetable Generator</td>
    </tr>
    <tr>
        <td>
            <a href="Puredata/Tuning%20Fork/Demos/">Demos here on Github</a>
        </td>
        <td>
            <a href="Puredata/Vanilla%20Sustain%20Pedal/Demos/">Demos here on Github</a>
        </td>
        <td></td>
    </tr>
</table>

<table>
    <tr>
        <td>
            <img src="Unicorn%20Wave/Screenshots/String%20Section%20(Default%20Sound).png" width="300">
        </td>
        <td>
            <img src="Mini%20Clavier/Screenshots/Default%20Sound.png" width="300">
        </td>
        <td>
            <img src="../Images/TODO.png" width="300">
        </td>
    </tr>
    <tr>
        <td>Unicorn Wave</td>
        <td>Mini Clavier</td>
        <td>FM4</td>
    </tr>
    <tr>
        <td>
            <a href="https://samply.app/p/yHQ1sIZ8EadgZIwAfyuz" target="_blank">Demos on Samply</a>
            <br>
            <a href="Unicorn%20Wave/Demos/">Demos here on Github</a>
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

How to Use
----------

All patches have been built with [PD-L2Ork](http://l2ork.music.vt.edu/main/) –
the Puredata version built for the Linux Laptop Orchestra. Only objects from
[PD Vanilla](https://puredata.info/downloads/vanilla) are used, so the patches
usually work with that, too. But only without the UI because unfortunately there
are many incompatibilities between those two regarding the UI objects.

 * __PD-L2Ork:__ Works best for all patches.
 * __PD Vanilla:__ Works with limitations:
    * No GUI due to incompatibilities (start `main1.pd`, instead)
    * Multi-Processing causes more audio drop-outs
    * Sometimes I forget that PD Vanilla replaces $0 in message boxes with 0.
      Very annoying that the PD Vanilla developers are so stubborn about this!
 * __Plugdata:__ Should work in theory, but crashes with the large projects.

Main, Main1, Main2
------------------

The patch itself is always contained in `main.pd`. All other files are usually
abstractions (custom objects) or data files. There are different main files,
however:

 * `main.pd`: Full version including a user interface built with PD (wraps `main1.pd`)
 * `main1.pd`: The synthesizer without UI but with preset management (wraps `main2.pd`)
 * `main2.pd`: The core synthesizer engine without UI or preset management

On Desktop you usually want to run `main.pd` but on headless devices (e.g.
Raspberry Pi hidden in a custom case) running `main1.pd` may save CPU cycles.
`main2.pd` is meant for embedding in custom built applications with `libpd` where
PDs load and save dialogues usually don't work and presets are handled by the app,
instead.

Instruments
-----------

- **Tuning Fork**: A minimal synth producing a pure sine wave. Serves as a test bed
  for `libpd` on Android and MIDI message handling.

- **Vanilla Sustain Pedal:** Demonstrates the use of PD's `[poly]`, `[clone]`, and `[bag]`
  objects to handle sustain pedal (MIDI CC 64).

- **Unicorn Wave:** Wavetable synthesizer using band-limited wavetables (one per octave,
  similar is principle as the Korg DW-8000). Really a unicorn regarding clean-code principles
  and complexity in PD. Custom voice allocators and envelopes making full use of structures
  in PD. But the UI is **very** CPU intensive.

- **Mini Clavier**: Experimental implementation of the Synclavier FM algorithm, using an
  oscillator bank for the carrier and a single sine for the modulator.

- **FM4:** A 4-operator FM synth inspired by Yamaha 1980s hardware (e.g., DX9).
  It allows to recreate all 4-operator algorithms with a sound profile similar to
  the originals, while maintaining manageable complexity.

Utilities
---------

- **Wave Table Generator**: Creates band-limited wave tables for classic analogue
  waveforms (Sine, Triangle, Saw, Square) to be used with PD's `[tabosc4~]` object

- **Reusable Abstractions**: As the name implies, generic custom objects extracted
  from the other projects. Can simply be copied into other projects for different
  purposes like LFO, Equal-Power Panning, etc.

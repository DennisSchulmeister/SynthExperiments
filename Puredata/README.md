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
            <a href="Tuning%20Fork/Screenshots/Tuning%20Fork.png?raw=true">
                <img src="Tuning%20Fork/Screenshots/Tuning%20Fork.png?raw=true" width="300">
            </a>
            <br/>
            <a href="Tuning%20Fork/Demos/Tuning%20Fork.mp3?raw=true">Tuning Fork.mp3</a>
        </td>
        <td>
            <a href="Vanilla%20Sustain%20Pedal/Screenshots/Main%20Patch.png?raw=true">
                <img src="Vanilla%20Sustain%20Pedal/Screenshots/Main%20Patch.png?raw=true" width="300">
            </a>
            <br/>
            <a href="Vanilla%20Sustain%20Pedal/Demos/Sustain%20Pedal.mp3?raw=true">Sustain Pedal.mp3</a>
        </td>
        <td>
            <a href="Wave%20Table%20Generator/Screenshots/Main View.png?raw=true">
                <img src="Wave%20Table%20Generator/Screenshots/Main View.png?raw=true" width="300">
            </a>
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
            <a href="Unicorn%20Wave/Screenshots/Default%20Sound.png?raw=true">
                <img src="Unicorn%20Wave/Screenshots/String%20Section%20(Default%20Sound).png?raw=true" width="300">
            </a>
            <br/>
            <a href="Unicorn%20Wave/Demos/String%20Section%20(Default%20Sound).mp3?raw=true">String Section.mp3</a>
        </td>
        <td>
            <img src="../Images/TODO.png?raw=true" width="300">
        </td>
        <td>
            <img src="../Images/TODO.png?raw=true" width="300">
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
            <a href="Unicorn%20Wave/Demos/">Demos here on Github</a>
            <iframe src="https://samply.app/embed/yHQ1sIZ8EadgZIwAfyuz" frameborder="0" allowtransparency="true" style="width: 100%; border-radius: 16px; border: 1px solid rgba(255, 255, 255, 0.12)"></iframe>
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
should work with that, too. But some UI elements will be misaligned since PD
Vanilla places some elements differently and the overall look and UI performance
will be worse.

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

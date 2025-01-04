Puredata Instruments and Utilities
==================================

1. [Directory Content](#directory-content)
1. [Instruments](#instruments)
1. [Utilities](#utilities)

Directory Content
-----------------

This directory contains a collection of virtual instruments and utility programs
built using Puredata. These resources demonstrate how Puredata can be employed to
program real-time MIDI synthesizers and serves as a starting point for exploring
Puredata's capabilities and challenges.

This directory showcases Puredata's capability in programming real-time MIDI synthesizers
and investigates the feasibility of building portable virtual instruments using Android
and Puredata (via Java and libpd). The investigation focuses on determining the minimum
achievable latency on Android, the maximum polyphony Puredata can handle on mobile devices
with medium complexity synthesis (e.g., 4-operator FM), and evaluating the required programming
skills, DSP knowledge, and overall development effort.

First some screenshots and demos. Find more detailed descriptions below.
For more demos please see the [Main README file](../README.md).

<table>
    <tr>
        <td>
            <a href="Tuning%20Fork/Screenshots/Tuning%20Fork.png">
                <img src="Tuning%20Fork/Screenshots/Tuning%20Fork.png" width="300">
            </a>
            <br/>
            <audio src="Tuning%20Fork/Demos/Tuning%20Fork.mp3" type="audio/mpeg">
        </td>
        <td>
            <a href="Vanilla%20Sustain%20Pedal/Screenshots/Main%20Patch.png">
                <img src="Vanilla%20Sustain%20Pedal/Screenshots/Main%20Patch.png" width="300">
            </a>
            <br/>
            <audio src="Vanilla%20Sustain%20Pedal/Demos/Sustain%20Pedal.mp3" type="audio/mpeg">
        </td>
    </tr>
    <tr>
        <td>Tuning Fork</td>
        <td>Vanilla Sustain Pedal</td>
    </tr>
</table>

<table>
    <tr>
        <td>
            To be done ...
        </td>
        <td>
            <a href="Mini%20Clavier/Screenshots/Main%20View.png">
                <img src="Mini%20Clavier/Screenshots/Main%20View.png" width="300">
            </a>
            <br/>
            <audio src="Mini%20Clavier/Demos/Default%20Sound.mp3" type="audio/mpeg">
        </td>
    </tr>
    <tr>
        <td>FM4</td>
        <td>Mini Clavier</td>
    </tr>
</table>

<table>
    <tr>
        <td>
            <a href="Wave%20Table%20Generator/Screenshots/Main View.png">
                <img src="Wave%20Table%20Generator/Screenshots/Main View.png" width="300">
            </a>
        </td>
    </tr>
    <tr>
        <td>Wave Table Generator</td>
    </tr>
</table>

Instruments
-----------

- **Tuning Fork:** A minimal synth producing a pure sine wave. It serves as a testbed for
  `libpd` on Android and MIDI message handling.

- **Vanilla Sustain Pedal:**:Demonstrates the use of PD's `[poly]`, `[clone]`, and `[bag]`
  objects to handle sustain pedal (MIDI CC 64).

- **FM4:** A 4-operator FM synth inspired by Yamaha 1980s hardware (e.g., DX9). It implements
  4-operator algorithms with a sound profile similar to the originals, while maintaining manageable
  complexity.

- **Mini Clavier:** An experimental synth using band-limited wave tables and frequency modulation.
  - Features:
    - Full UI built in Puredata.
    - Custom voice allocator with improved voice stealing, sustain and sustenuto.
    - Preset loading and saving.
    - Additive synthesis for FM carriers and modulators.
    - Dynamic band-limited wave tables for aliasing reduction.
    - Custom chorus/flanger effect.
    - Visual GUI editor for arbitrary-length envelopes.
  - _Note:_ This project exceeds Puredata's limits even on desktop systems and remains incomplete.

Utilities
---------

- **Wave Table Generator**: Creates band-limited wave tables for classic analog waveforms
  (Sine, Triangle, Saw, Square) to be used with PD's `[tabosc4~]` object

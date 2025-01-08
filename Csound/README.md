Csound Instruments
==================

1. [Directory Content](#directory-content)
1. [How to Use](#how-to-use)
1. [Instruments](#instruments)

Directory Content
-----------------

This directory contains a collection of virtual instruments built with Csound.
These projects demonstrate how Csound can be employed to program real-time
MIDI synthesizers and serves as a starting point for exploring Csounds's
capabilities and challenges.

First some screenshots and demos. Find more detailed descriptions below.
For more demos please see the [Main README file](../README.md).

<table>
    <tr>
        <td>
            <a href="Analog%20Bread%20and%20Butter/Screenshots/PWM%20Pad%20(Default%20Sound).png?raw=true">
                <img src="Analog%20Bread%20and%20Butter/Screenshots/PWM%20Pad%20(Default%20Sound).png?raw=true" width="300">
            </a>
            <a href="Analog%20Bread%20and%20Butter/Demos/PWM%20Pad%20(Default%20Sound)%20I.mp3?raw=true">PWM Pad (Default Sound) I.mp3</a>
        </td>
        <td>
            <a href="Schoko%20FM4/Screenshots/Rhodes%201%20(Default%20Sound).png?raw=true">
                <img src="Schoko%20FM4/Screenshots/Rhodes%201%20(Default%20Sound).png?raw=true" width="300">
            </a>
            <a href="Csound/Schoko%20FM4/Demos/Rhodes%201%20(Default%20Sound).mp3?raw=true">Rhodes 1 (Default Sound).mp3</a>
        </td>
        <td>
            <a href="Tuning%20Fork/Screenshots/Tuning%20Fork.png?raw=true">
                <img src="Tuning%20Fork/Screenshots/Tuning%20Fork.png?raw=true" width="300">
            </a>
            <a href="Tuning%20Fork/Demos/Tuning%20Fork.mp3?raw=true">Tuning Fork.mp3</a>
        </td>
    </tr>
    <tr>
        <td>Analog Bread and Butter</td>
        <td>Schoko FM4</td>
        <td>Tuning Fork</td>
    </tr>
    <tr>
        <td>
            <a href="https://samply.app/p/jM1I6JruowcWRwDIbZ3r" target="_blank">Demos on Samply</a>
            <a href="Analog%20Bread%20and%20Butter/Demos/">Demos here on Github</a>
            <iframe
              src="https://samply.app/embed/jM1I6JruowcWRwDIbZ3r"
              frameborder="0"
              allowtransparency="true"
              style="width: 100%; border-radius: 16px; border: 1px solid rgba(255, 255, 255, 0.12)"
            ></iframe>
        </td>
        <td>
            <a href="https://samply.app/p/KCnei0x2nOEXpUBnqafz" target="_blank">Demos on Samply</a>
            <a href="Schoko%20FM4/Demos/">Demos here on Github</a>
            <iframe
              src="https://samply.app/embed/KCnei0x2nOEXpUBnqafz"
              frameborder="0"
              allowtransparency="true"
              style="width: 100%; border-radius: 16px; border: 1px solid rgba(255, 255, 255, 0.12)"
            ></iframe>
        </td>
        <td>
            <a href="Tuning%20Fork/Demos/">Demos here on Github</a>
        </td>
    </tr>
</table>

How to Use
----------

These patches have been built with the [Cabbage](https://cabbageaudio.com/)
frontend for [Csound](https://csound.com/). Simply open the `.csd` files in
Cabbage and press play to run. Alternatively you can export a standalone
executable from the file menu and run this, instead.

Instruments
-----------

* __Analog Bread and Butter:__ Plain and simple 2-oscillator subtractive synthesizer.
  It's not exactly a Minimoog but can produce some interesting sounds. Features two
  unison modes inspired by 1980s analogue synthesizers like the Roland Jupiter.

- **Schoko FM4:** A 4-operator FM synth inspired by Yamaha 1980s hardware (e.g., DX9).
  It allows to recreate all 4-operator algorithms with a sound profile similar to
  the originals, while maintaining manageable complexity. Looks and sounds like
  chocolate. 🍫

* __Tuning Fork:__ A minimal synth producing a pure sine wave. Serves as a test bed
  for `Csound` on Android and MIDI message handling.

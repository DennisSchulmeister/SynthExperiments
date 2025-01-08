Future Archive of Experimental Software Synthesizers
====================================================

----

[Zukunftsarchiv](https://www.youtube.com/watch?v=7dO9Lm_CXz0&pp=ygURcGFzc2llcnNjaGVpbiBhMzg%3D)
experimenteller Software-Synthesizer

----

1. [Overview, Screenshots and Demos](#overview-screenshots-and-demos)
1. [Running on Your Hardware](#running-on-your-hardware)
1. [Project Background](#project-background)
1. [Copyright](#copyright)

Overview, Screenshots and Demos
-------------------------------

<table>
    <tr>
        <td>
            <a href="Csound/Analog%20Bread%20and%20Butter/Screenshots/PWM%20Pad%20(Default%20Sound).png?raw=true">
                <img src="Csound/Analog%20Bread%20and%20Butter/Screenshots/PWM%20Pad%20(Default%20Sound).png?raw=true" width="300">
            </a>
        </td>
        <td>
            <a href="Csound/Schoko%20FM4/Screenshots/Rhodes%201%20(Default%20Sound).png?raw=true">
                <img src="Csound/Schoko%20FM4/Screenshots/Rhodes%201%20(Default%20Sound).png?raw=true" width="300">
            </a>
        </td>
        <td>
            <a href="Csound/Tuning%20Fork/Screenshots/Tuning%20Fork.png?raw=true">
                <img src="Csound/Tuning%20Fork/Screenshots/Tuning%20Fork.png?raw=true" width="300">
            </a>
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
            <br>
            <a href="Csound/Analog%20Bread%20and%20Butter/Demos/">Demos here on Github</a>
        </td>
        <td>
            <a href="https://samply.app/p/KCnei0x2nOEXpUBnqafz" target="_blank">Demos on Samply</a>
            <br>
            <a href="Csound/Schoko%20FM4/Demos/">Demos here on Github</a>
        </td>
        <td>
            <a href="Csound/Tuning%20Fork/Demos/">Demos here on Github</a>
        </td>
    </tr>
</table>

<table>
    <tr>
        <td>
            <a href="Puredata/Unicorn%20Wave/Screenshots/Default%20Sound.png?raw=true">
                <img src="Puredata/Unicorn%20Wave/Screenshots/String%20Section%20(Default%20Sound).png?raw=true" width="300">
            </a>
        </td>
        <td>
            <img src="Images/TODO.png?raw=true" width="300">
        </td>
        <td>
            <img src="Images/TODO.png?raw=true" width="300">
        </td>
    </tr>
    <tr>
        <td>Unicorn Wave</td>
        <td>Mini Clavier</td>
        <td>FM4 (Puredata)</td>
    </tr>
    <tr>
        <td>
            <a href="https://samply.app/p/yHQ1sIZ8EadgZIwAfyuz" target="_blank">Demos on Samply</a>
            <br>
            <a href="Puredata/Unicorn%20Wave/Demos/">Demos here on Github</a>
        </td>
        <td></td>
        <td></td>
    </tr>
</table>

Send me a link to your music if you are using one of these.

Running on Your Hardware
------------------------

While Csound and Puredata are interpreted languages (similar to Python or Lua
but without the byte-code) running these synthesizers on your own hardware
should be straight-forward. Depending on how the synthesizer was built you will
need one of those programs installed:

 * __Puredata Patches:__ [PD-L2Ork](http://l2ork.music.vt.edu/main/) –
   the Puredata version built for the Linux Laptop Orchestra.
   [Purr Data](https://www.purrdata.net/) should also work but I am not using
   it since it tends to crash on Fedora Linux.

 * __Csound Instruments:__ [Csound](https://csound.com/) and the [Cabbage](https://cabbageaudio.com/)
   frontend.

### For Puredata follow these steps:

1. Start `PD L2Ork` and make sure it connects to your audio hardware (via the
   audio settings found in __Edit → Preferences__).

   ![](Images/PD%20Audio%20Settings.png?raw=true)

1. Make sure that the DSP switch is on (green switch in the screenshot above).

1. If you are using the [Jack Audio Server](https://jackaudio.org/) (highly
   recommended on Linux but also on Windows and Mac), you need to manually
   connect your MIDI devices or automate this with a script.

   ![](Images/PD%20Connections.png?raw=true)

1. Last but not least in `PD L2Ork` load the patch you are interested it.
   Usually you want to run the `main.pd` file, which includes a full UI made
   with Puredata primitives. On headless devices you usually want `main1.pd`
   which includes everything minus the UI and for embedding in a custom
   application you may use `main2.pd` which is the same minus preset management.

Don't touch the mouse while you're playing on your MIDI devices when the Puredata
UI is visible. Complex user interfaces like for the `Unicorn Wave` synthesizer
draw considerable CPU power in Puredata. Oddly enough you may get audio drop-outs
just by moving the mouse cursor a few pixels. Other than that, if it doesn't stutter
(your CPU can handle the workload), it should run stable.

### For Csound follow these steps:

1. Start Cabbage and -- when running for the first time -- go to __Edit → Settings__,
   to configure your audio hardware. Unfortunately it seems that Cabbage doesn't
   support the [Jack Audio Server](https://jackaudio.org/) yet. But on Linux the
   ALSA backend works very well.

   ![](Images/Cabbage%20Settings.png?raw=true)

1. Load a Csound file and click on the "play" button to run it.

   ![](Images/Cabbage%20Play%20Button.png?raw=true)

   While running the button turns into a "stop" button. The other buttons
   next to the file name allow to open the UI window and the UI editor (don't
   use the last one, it tends to destroy the source code).

   ![](Images/Cabbage%20Stop%20Button.png?raw=true)

1. When loading another patch you need to stop the previously running patch
   via the stop button. Otherwise both will play at the same time, responding
   to all MIDI events.

   Note, that when you close a file, the patch might still be active in
   background. To be sure, go to __View → Show Cabbage Patcher__ to see which
   patches are active. Here you can remove unneeded instances via the right-click
   context menu of their nodes.

   ![](Images/Cabbage%20Patcher.png?raw=true)

1. That's basically it. But you might want to export a standalone executable and
   run this instead, if you want to save and load preset files. Unfortunately this
   feature is not available when running the patches from within Cabbage itself.
   Also this makes it easier to auto-start a synthesizer when the computer boots.

   You find the export option under __File → Export as Standalone Application__.
   Place the exported file in a new empty directory. There you will find the
   executable (targeted at your platform and computer architecture) and a copy
   of the `.csd` file. Always keep those two together!

   On Linux, Mac, Unix, … you need to manually set the executable flag for the
   executable file (`chmod +x`).

Project Background
------------------

This project is mainly a playground for me to learn cross-platform audio DSP
programming with Puredata and Csound. The synthesizers are meant to be somewhat
useful for keyboard players in music production or live performance.

Please don't expect something like the Arturia V Collection here. Commercial
software synthesizers are built by specialist teams within months or years to
accurately emulate the electrical circuit of yesteryear's hardware. I, on the
other hand, am just a random person on the Internet happening to be a software
developer and musician. Still I hope that the synthesizers I built for learning
can be useful for other people, too.

Besides that, this is also a research project to evaluate the modern Android
ecosystem (as of 2025) for real-time audio usage. Apple has been best in class
for low-latency audio even with the very first iPhone, achieving 7ms latency
with no problem. Android, in the early years, had a very basic audio server
that - if I dare say so - did everything wrong that could be done wrong, starting
with a blocking push model (similar to ancient Open Sound System on Unix) where
applications call blocking functions to "push" blocks of audio to the hardware,
rather than the hardware "pulling" new data when it is needed. The latter is
a pre-condition for reliable low latency, no matter the type of system.

Fortunately the situation has changed by now and at least in theory any stock
Android device should be low-latency capable. But is it really so? And can we
use languages like Csound and Puredata for rapidly building software synthesizers
for mobile devices? This is, what I want to find out.

Copyright
---------

© Dennis Schulmeister-Zimolong (github@windows3.de)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

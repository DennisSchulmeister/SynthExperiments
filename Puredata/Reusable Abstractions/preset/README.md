Preset Management
=================

1. [Working Examples](#working-examples)
1. [Usage](#usage)
1. [Multi-Processing](#multi-processing)

Unlike some Csound frontends Puredata unfortunately lacks a native mechanism
to save and load "preset" configurations for a patch, e.g. with pre-defined
sounds for a synthesizer or custom effect programs for an effects box. The
objects in this directories add this feature in a very straight-forward way,
though the native load and save dialogues from the OS are probably not available
in `libpd` on all platforms (need to check this).

Working Examples
----------------

The Puredata synthesizers in this repository all use the preset management
custom objects, usually in their `main1.pd` file. To this end, the patches
contain three "main" files to run them, depending on your planned usage:

 * `main.pd`: Full version including a user interface built with PD (wraps `main1.pd`)
 * `main1.pd`: The synthesizer without UI but with preset management (this is the
   file we are interested in, wraps `main2.pd`)
 * `main2.pd`: The core synthesizer engine without UI and no preset management

Usage
-----

First you need to make sure that your patch uses plain `[receive]` or `[r]`
objects to control its parameters. Usually you use them in combination with
some UI elements that act as the corresponding sender, like so:

_Some parameters controlled via a `[r]` object:_

![](Screenshots/Parameters.png?raw=true)

_Corresponding UI patch to set the parameter:_

![](Screenshots/UI%20Patch.png?raw=true)

_Properties of the slider object, note the "send symbol" field:_

![](Screenshots/Slider%20Properties.png?raw=true)

This arrangement makes sure that the parameters can be changed from the UI and
UI can be updates when some other source (e.g. an external device) sends a new
value on the same channel. At the same time the UI will not receive its own
value changes. (Technically it does but the `|set[` message is a no-op, if the
UI value is not changed).

Next you need to create a central `[preset-manager pm]` object in your patch,
usually in the `main1.pd` file. The object must only exist and have a unique name
in its first parameter. But usually it will also receive messages from the UI
to trigger its actions.

![](Screenshots/Preset%20Manager%20Instance.png?raw=true)

![](Screenshots/Preset%20Manager%20UI.png?raw=true)

Finally, at the same place where the `[preset-manager]` lives, add one
`[preset-value]` object for each parameter. This takes two arguments:

1. The name of the `[preset-manager]` object
1. The name of the send/receive channel for the parameter

![](Screenshots/Preset%20Values.png?raw=true)

That's it. With this in place, the `[preset-value]` objects will listen for
parameter changes and keep them in their internal memory for the `[preset-manager]`
to read when a preset file is written. When a preset file is read, the preset
manager simply sends the read values to the corresponding channels.

Multi-Processing
----------------

If you are using `[pd~]` to start multiple processes, you may use `[preset-value1]`
instead of `[preset-value]`. It takes an additional first parameter with the name
of a `[r]` object, where all parameter values are sent to. This `[r]` object simply
must be connected with the `[pd~]` object to forward all value changes to the
sub-processes (because sub-processes cannot use `[send]` and `[receive]` to exchange
data).

Additionally, once a sub-process has finished starting, send a bang to the global
receive "pd-ready" to ask for all preset parameters to be forwarded to the process.

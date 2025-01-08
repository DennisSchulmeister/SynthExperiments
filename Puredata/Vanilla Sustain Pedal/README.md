Vanilla Sustain Pedal
=====================

![Screenshot](Screenshots/Main%20Patch.png?raw=true)

[Demos here on Github](Demos/)

This is the patch that led to the `[poly-sustain]` abstraction in the
[Reusable Abstractions](../Reusable%20Abstractions) directory. It shows how
the PD Vanilla `[poly]`, `[bag]` and `[clone]` can be used to realize a basic
MIDI voice allocator that -- unlike `[poly]`, and `[clone]` alone -- can also
handle the sustain pedal:

When the sustain pedal is pressed all currently and future playing notes will
be held by collecting their note-offs in a `[bag]` and will only be released
once the pedal is released. This is indicated in the Puredata Quick Reference
for the `[bag]` object which simply says: "You can use `[bag]` to mimic a sustain
pedal, for example." Exactly how, it doesn't tell. :-) This patch here does.

Note that the generated sound is intentionally simple as the focus is not on
tone generation here. It is a very basic toy FM piano sound as it was also used
in cheaper FM children keyboards wide into the 1990s.

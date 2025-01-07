Luxurious Voice Allocator
=========================

![Screenshot of the voice status](Screenshots/Voice%20Status.png?raw=true)

This is a reimplementation of the built-in `[poly]` object from PD Vanilla
including additional features, that the original bitterly lacks:

 * Sustain pedal (hold all notes until released)
 * Sustenuto pedal (only hold notes that were already playing)
 * Re-triggering of double notes (instead of double triggering)
 * Voice stealing by amplitude (always steel the voice with the lowest amplitude)

It is a prime example of how complex algorithms can be "written" with Puredata,
though I find it a bit hard to express the same concepts as `if`, `while`, `for`
etc. from other languages as purely data streams. Also it makes heavy use of the
"data structures" language-feature to manage the voice state. Thus performance
is okayish for most use cases but not as fast as `[poly]` or purely native-code
implementations. On the other hand, PD's unique feature to "paint" data structures
on the canvas makes it super easy to see what is actually going on.

`[voice_allocator]` is the main object you need to use in your patch. All others
are internal abstractions (custom objects).

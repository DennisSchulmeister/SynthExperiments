Reusable Abstractions
=====================

The directory contains abstractions, that have been developed for the other
projects in this repository, but can actually be used in any PD project.
All reasonable effort has been done to make them as well-behaved and isolated
as possible (as far as this even a thing in Puredata).

 * `utils`: ([README](./utils/README.md)) Small utilities. Each file is separate
    from the others.

 * `chorus`: ([README](./chorus/README.md)) A simple stereo chorus/flanger effect

 * `envgen`: ([README](./envgen/README.md)) Envelope generator with unlimited
   breakpoints for attack and release

 * `pd~`: ([README](./pd~/README.md)) Utilities to simplify working with multiple
   processes and Puredata's `[pd~]` object

 * `preset`: ([README](./preset/README.md)) Simple mechanism to save and load
   parameters from preset files. Can also be used to save parameters in memory
   when the same user interface widgets are used to control different parts of
   a synthesizer, (e.g. the same controls are used to program partials 1, 2, 3,
   4 and you want a mechanism to switch the currently edited partial).

 * `voice_allocator`: ([README](./voice_allocator/README.md)) PD's `[poly]`
   on steroids. A proper voice allocator that is easy to use, easy to debug (look
   at the data sub-patch to see what's going on), and most importantly handles
   sustain and sustenuto pedals, and re-triggers already playing notes instead
   of doubling them. Might be a bit CPU intensive, though, due to the increased
   usage of Purdata data structures.

   See `util/poly-sustain.pd` for a light-weight alternative that only handles
   the sustain pedal, similar to the built-in voice allocator of Csound.

Documentation for each abstraction is contained in the top-left corner of each
`*.pd` file. Have fun and feel free to use anything you find useful in your own
projects. If you do, send me a link to your patch and/or music. :-)

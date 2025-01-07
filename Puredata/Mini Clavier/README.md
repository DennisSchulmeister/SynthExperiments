Mini Clavier
============

![../../Images/TODO.png?raw=true](TODO)

**To be done - this synth has not yet been built.**

The Mini Clavier is an experiment in recreating the core of the Synclavier
FM synthesis with Puredata (without the claim to be a faithful or even complete
recreation). It consists of a sine wave oscillator bank with 24 harmonics which
are frequency modulated by a single sine oscillator.

Note, that the original Synclavier features much more powerful synthesis
with at least (depending on the exact model and configuration as far as I
can tell):

 * The Synclavier has 32 carrier harmonics, that can only be sine waves.
 * The Synclavier can string together "timbre frames" to resynthesize complex waveforms.
 * The Synclavier has no built-in effects except for a simple chorus (voice doubler).
 * The Synclavier can layer up to four "partials" which are fully fledged FM
   sounds (timbres or voices) each.

Here only the core idea is recreated to see, if it is feasible with Puredata
at all or not. Considering that a lot of oscillators have to be effectively
run in parallel for this kind of synthesis.

_Screenshots, Demos etc. to come, once the synth has been built._

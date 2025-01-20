Harmonic Resynthesis for Mini Clavier
=====================================

<img src="Screenshots/Screenshot.png?raw=true" alt="Screenshot">

Mini Clavier is an experiment to recreate the basic FM synthesis algorithm of
the Synclavier in Puredata. But the result sounded rather uninteresting and
static, because with only one modulator the frequency spectrum is hardly
changing over time. This led to the idea of recreating the resynthesis
functionality, too. The general idea, that I lifted from the Synclavier, is
this:

 - Ordinary FM sounds consist of 16 sine harmonics (up to 36 on the Synclavier,
   although 25 to 36 can only be used with resynthesis, according to the
   [Manual Volume 2 - Sound Design Manual, p. 87ff](http://www.500sound.com/software/Volume%202%20-%20Sound%20Design.pdf)),
   which are modulated by a single sine wave. The Synclavier uses wavetable
   synthesis according to the manual and thus recomputes the waveform each time
   a value is changed. Since the wavetable contains exactly one wave cycle, only
   integer ratios are allowed.

   In Mini Clavier the harmonics are synthesized in real-time and thus can have
   any ratio. But this is not used by the resynthesis program as I found the
   resulting sounds to be unstable and bleepy with the simple algorithm I am
   using. Also Mini Clavier doesn't allow to change the harmonic phases.

 - Resynthesis creates multiple snapshots of a sound (called "timbre frames" on
   the Synclavier) in equal intervals that are played back in sequence, when a
   note is played.

   On the Synclavier that sound file must be manually labelled to define the
   start and end of each timbre frame. The timbre frames can be of different
   lengths and do not have to be in direct succession. Gaps between the frames
   are allowed. The Harmonic Resynthesized for Mini Clavier, however, simplifies
   the process by automatically slicing the whole sound into equal-length frames.

 - Timbre frames are created in an offline process where the original sample is
   sliced up and FFT-analysed to determine the harmonic amplitudes of each frame.
   The result is an array of 16 amplitude levels--one for each harmonic--for
   each frame.

   On the Synclavier, timbre frames require twice the polyphony, because two
   synthesizer notes are needed to cross-fade from one frame to the next.
   Cross-fades can be linear or exponential and their start time and duration
   can be freely changed. Mini Clavier doesn't cross-fade but rather lets the
   amplitude levels glide from the previous value to the next. Again, this is
   less flexible but easier on the CPU and requires no manual editing.

 - Once a resynthesized sound is loaded back into Mini Clavier, it can be modified
   like any other sound, e.g. by applying frequency modulation or changing the
   (relative) amplitude of the harmonics.

Es explained above, this is in no way an exact replica of what the Synclavier did.
But the idea should still come close.

So, how does it sound? To be honest, quite lo-fi and uninteresting. :-) Maybe
I should take the time to reimplement the Synclavier algorithm properly. Judging
from the example Sounds in the [Analysis Results/](Analysis%20Results/) directory,
there are some severe limitations:

 - The algorithm uses only 16 harmonics with integer ratios. The resynthesized sounds
   therefore lack many high frequencies and sound more dull and overall lo-fi. The
   base sound is recognizable, but lacks fidelity.

 - Sometimes frequencies come up that are not as present in the original, if at all.
   The reason for this is probably that the FFT algorithm in deed does detect non-integer
   harmonics, but they are rounded to the nearest integer and summed, because in most
   cases the resulting sound would be rather chaotic and bleepy otherwise.

 - Chorusy sounds like an accordion which contains two or three slightly detuned
   tines, come out not chorusy at all. Again this is due to the harmonic ratios
   being forced to integer values. Luckily the effect can easily be recreated
   by layering two or three instances or with a Chorus effect.

 - For the same reasons, noisy and breathy sounds don't work very well. Best results
   can be obtained with simple sounds that are very sine-like to begin with,
   like the Wine Glass example.

 - The usable playing range for a resynthesized sound is quite narrow, given that
   is based on a single sample. Multi-sampling would be nice, but algorithmic coding
   is not always easy in Puredata. So, if I ever rework this, I will probably rewrite
   the whole thing in Csound or C/C++.

On the pro-side the sound _is_ different from the original and can be further
processed in Mini Clavier, e.g. with FM. No one will throw away they hardware
samplers or VSTs for this, but once in a while a usable sound might appear.

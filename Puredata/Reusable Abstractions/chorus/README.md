Simple Chorus/Flanger Effect
============================

This is based on "The Csound book"; pp. 458-461, 586-589 and "Csound - A Sound and
Music Computing System"; pp. 271-274. It differs a little bit from the literature
references by using four individual voices and by combining chorus and flanger
into the same effect, since chorus is just a flanger without the feedback path
and slightly different settings:

Typical values for chorus:
  - Delay:       20…30 ms
  - Frequency:   < 30 Hz
  - Sweep Width: ~ 5 ms
  - Feedback:    None

Typical values for flanger:
  - Delay:       < 10 ms
  - Frequency:   ~ 10 Hz
  - Sweep Width: ~ 1 ms
  - Feedback:    Yes

It sounds particularly nice as a chorus effect. The flanger effect, probably due
to comb filtering of the four voices or some other differences between commercial
effects and these books doesn't sound as convincing, though.

`[chorus]` is the main object you need to use in your patch. `[chorus_voice]`
is an internal abstractions (custom object) used by `[chorus]` for the individual
chorus voices.

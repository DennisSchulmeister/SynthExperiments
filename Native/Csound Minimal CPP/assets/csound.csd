<CsoundSynthesizer>
<CsOptions>
    -odac --realtime --sched
</CsOptions>
<CsInstruments>
    sr     = 44100
    ksmps  = 256
    nchnls = 2
    0dbfs  = 1

    instr 1
        asig = linen(oscili(p4, p5), 0.1, p3, 0.1)
        out(asig, asig)
    endin
</CsInstruments>
<CsScore>
    t 0 60
    i1 0 5 .75 440
</CsScore>
</CsoundSynthesizer>

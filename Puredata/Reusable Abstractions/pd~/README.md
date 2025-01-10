Multi-Processing Utilities
==========================

Puredata has some basic support for multi-processing with `[pd~]` which allows
to run another patch in a separate process and exchange audio data in real-time.
This works sufficiently well, but there are a few limitations:

 * You cannot pass arguments (dollar-parameters) to the sub-patch, as you would
   with `[pd xyz]` or `[./my-object abc]`.

 * You cannot use `[send]` and `[receive]` to exchange data. You can send data
   to receive objects in the sub-patch, but you must to so by sending a message
   to the first inlet of the `[pd~]` object.

This directory contains two small wrapper to mitigate those limitations.

 * `[wrapper]`: Used to wrap the patch that should be running in its own process
   to be able to pass arguments. Instead of directly running your patch with `[pd~]`,
   run this instead and do the following:

     1. Wait, until PD_READY appears at the first outlet of `[pd~]`.

     2. Then send an `init` message to `[pd~]` with the relative path of the
        actual patch (relative to `wrapper.pd`!) and all its arguments. e.g.
        `[../my-sub-process 123 abc]`.

 * `[forward]`: Receive values with `[r …]` and forward them to a sub-process.
    Simply create object object of this for any value where you want, that
    values sent with `[s …]` shall also be received by sub-processes and connect
    its outlet to the first inlet of `[pd~]`.

There is no solution for receiving values from a sub-process, though. Instead,
inside the sub-process you must send values to standard output with `[stdout]`
and receive them from the first outlet of the `[pd~]` object. Also note, that
`[print]` in a sub-process always prints to the sub-processes GUI window, even
if you suppressed the GUI with `-nogui`. The parent process never sees or logs
the data that is printed in sub-processes.

See [../../Multi-Processing](../../Multi-Processing) for a working example.

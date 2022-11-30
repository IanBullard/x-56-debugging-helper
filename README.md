# x-56-debugging-helper
An SDL2-based input watcher to help track down ghost-inputs on the X-56 H.O.T.A.S.

If you want to skip the details, the tests are [here](tests.md).

## The problem
The Logitech's X-56 H.O.T.A.S. can sometimes tell the computer that an input has happened when actually it hasn't.  This is especially common with the switches on the throttle.  However, the ghost inputs don't happen at regular intervals.  Sometimes the inputs can be 20-60 minutes apart.  

## The Tester
This app will monitor the X-56 for inputs and log when and what input happened.  This will allow me to try out different solutions and test without waiting for ghost inputs to occur.  I can set up a test, plug in the throttle and/or stick, and walk away for hours.  

## Tests
There are several theories on the interet's forums, these are the tests I'll be trying:

### Get a baseline
I'll try to get a baseling test with no fixes first to see if how the X-56 is hooked up has any affect on the issue.

1. Just the throttle connected directly into my PC.
2. Throttle and stick connected directly into my PC.
3. Same as #1 but with an external powered hub.
4. Same as #2 but with an external powered hub.
5. The throttle connected to the PC and the stick connected to the hub
6. #5 but reversed.

All of these tests have a flaw in that no user input will be happening, which could be a factor of how often the bug occurs.  I have had the ghost input bug happen to me during Elite Dangerous while no user input is happening, so I hope these tests will be enough to get some data.

## Try fixes
I've seen the following suggested as fixes for the ghost input.  Depending on the baseline tests, I'll try them in order of how easy they are do do.

1. Change the LED brightness.  I know my own experience this doesn't fix the problem completely, but if it decreases the rate of the inputs it could point to a power problem.
2. Ferrite cores on the USB cable, one near the device and one near the plug.
3. Extra power cable cable (uses two USB male plugs and one female plug) to boost the power over the cable
4. Open the device and make sure there's no pinched cables
5. Place ferrite cores on the cables inside the device.

# License
All files in the repository are under the MIT license.  I don't really care what you do with this code, it's not meant for wide use or even use by anyone but me.  

# Notes
This app isn't for general consumption, it's only a helper to investigate a problem and possible solutions.  I don't recommend using any of this code in a shipping product, it's written to get to provide a solution as quickly as possible and not for safety, security, or any other -ity's.  It's not my best work, but it's also not my worst.

The code does translate input information from SDL2 to text that matches the labels on the devices, but not for all input.  I covered the main inputs and the switches on the throttle to cover common input and the input switches that are usually the source of the ghost input.  I'll fill out more input labels if needed.

# Building
I'm using xmake as a build system because it's the fastest way I know how to get an SDL2 console app up and running.  To build:

`xmake`

To run:

`./build/windows/x64/release/console.exe`


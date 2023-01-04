# x-56-debugging-helper
An SDL2-based input watcher to help track down ghost-inputs on the X-56 H.O.T.A.S.

## Current status
I'm running tests and [recording results](test_results.md) as time permits

## The problem
The Logitech's X-56 H.O.T.A.S. can sometimes tell the computer that an input has happened when actually it hasn't.  This is especially common with the switches on the throttle.  However, the ghost inputs don't happen at regular intervals.  Sometimes the inputs can be 20-60 minutes apart.  

## The Tester
This app will monitor the X-56 for inputs for four hours and log when and what input happened.  This will allow me to try out different solutions and test without waiting for ghost inputs to occur.  I can set up a test, plug in the throttle and/or stick, and walk away.  

## Tests
My first attempt at narrowing down the problem assumed that the ghost input was due to some sort of power/signal problem.  The test result suggested a different cause: which port the device is plugged into. The original test suite didn't take which USB port the device was plugged into consideration so I've reset my testing plans.

### Get a baseline
Testing matrix:

1. Throttle plugged into motherboard port 1/2
2. Stick plugged into motherboard port 1/2
3. Throttle + stick port combinations
4. 1-3 repeated with external powered hub.

All of these tests have a flaw in that no user input will be happening, which could be a factor of how often the bug occurs.  I have had the ghost input bug happen to me during Elite Dangerous while no user input is happening, so I hope these tests will be enough to get some data.

### Suggested fixes
I've seen the following suggested as fixes for the ghost input.  Depending on the baseline tests, I'll try them in order of how easy they are do do.

1. Change the LED brightness.  I know my own experience this doesn't fix the problem completely, but if it decreases the rate of the inputs it could point to a power problem.
2. Ferrite cores on the USB cable, one near the device and one near the plug.
3. Extra power cable cable (uses two USB male plugs and one female plug) to boost the power over the cable
4. Open the device and make sure there's no pinched cables
5. Place ferrite cores on the cables inside the device.

# License
All files in the repository are under the MIT license.

# Notes
This app isn't for general consumption, it's only a helper to investigate a problem and possible solutions.  I don't recommend using any of this code in a shipping product, it's written to get to provide a solution as quickly as possible and not for safety, security, or any other -ty's.  It's not my best work, but it's also not my worst.

The code does translate input information from SDL2 to text that matches the labels on the devices.

# Building
I'm using xmake as a build system because it's the fastest way I know how to get an SDL2 console app up and running.  To build:

`xmake`

To run:

`./build/windows/x64/release/console.exe`


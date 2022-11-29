# x-56-debugging-helper
An SDL2-based input watcher to help track down ghost-inputs on the X-56 H.O.T.A.S.

If you want to skip the details, the results of the tests are [here](#test-results).

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

# Try fixes
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

# To Do
* run tests

# Building
I'm using xmake as a build system because it's the fastest way I know how to get an SDL2 console app up and running.  To build:

`xmake`

To run:

`./build/windows/x64/release/console.exe`

# Test Results

## Notes
All tests are run with the throttle's axis-based inputs set to minimum (both throttles fully back, rotarys fully counter-clockwise, etc) to avoid bumping the device and creating non-ghost input. Unless otherwise stated, the LED lights are set to full white.

## Just the throttle connected directly into my PC

### 11/28/2022

Result:
```
Found throttle
0 events in 13 hours: 0 events/hour
```

This is unexpected because I've never seen zero events while developing this test program.

I moved all axis-based inputs to full and ran the test again:
```
Found throttle
0 events in 7.4 hours: 0 events/hour
```

From this result, I think it's safe to assume that the throttle alone isn't the problem.

## Throttle and stick connected directly into my PC

### 11/28/2022

Note: I had to make the deadzone significantly higher (8192, the previous value was 3072) for these tests.  The stick is clamped to my desk and apparently it's very easy to create inputs if I jostle my desk.  Since I'm looking for ghost input related to switches I don't think this is a problem.

Result:
```
Found joystick
Found throttle
22:11:00 - Throt : Mouse Ministick Y = 31987
1 events in 3.7 hours: 0.27 events/hour
```

That ministick event happened when I sat down at the computer after leaving it alone for 3 hours.  The value is large enough to make me think it could be a shadow input but the concern right now is I cannot reproduce the shadow input from the throttle switches.  I had shadow input while developing this app so I don't understand why it no longer happens.  

I'll try again, placing the throttle and stick in their normal positions attached to my desk.  There has to be some cause for the shadow inputs.

### 11/29/2022

Result:
```
Found joystick
Found throttle
10:49:37 - Stick : Twist = 8953
10:49:39 - Stick : C Stick X = -8704
10:49:41 - Stick : Twist = 8441
10:49:41 - Stick : Twist = 8457
13:33:45 - Stick : Twist = 10587
13:33:46 - Stick : Twist = 16128
13:33:47 - Stick : Twist = 9546
13:47:54 - Stick : Twist = 11051
14:20:49 - Stick : Twist = 9113
14:20:49 - Stick : C Stick X = -8192
14:20:50 - Stick : C Stick X = -8960
11 events in 4.3 hours: 2.6 events/hour
```

This are all axis inputs while I was at my desk.  It's hard to differentiate what input is caused by my desk movements (it's a standing desk that wobbles a bit) from ghost inputs, if any.  Also, I've never experienced ghost inputs from axis.

So far I'm not replicating the ghost inputs I've seen before "finishing" the test app.  I can come up with two possible causes:

1. I've changed something in my app that "fixes" the shadow inputs.
    a. For:
        1. I was getting ghost switch and toggle inputs just a couple of days ago during development of the test app.
        2. They aren't happening(?) since I switched from SDL_WaitEvent to SDL_WaitEventTimeout
    b. Against:
        1. Ghost input is still a possibility on the axis inputs. 
        2. I moved both devices when I "finished" the test app.
2. The ghost inputs are from cable interference.
    a. For:
        1. I moved both devices after making the SDL_WaitEventTimeout change.
        2. Difference ghost inputs appear to be happening.
    b. Against:
        1. It's a vague and hard-to-test situation

For now, I'll try to change the devices' setup to as closely match the last-known buggy input as I can and repeat the test.


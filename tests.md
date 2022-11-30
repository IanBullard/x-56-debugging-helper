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


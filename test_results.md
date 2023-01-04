# Test Results

The test application knows:

1. What devices are connected on startup.
2. How long the test will last (hard coded).
3. Any inputs that occur during the test.  For axis input, a hard-coded deadzone is assumed.

The result of the test is the number of ghost events/test time.

For these tests, the test length is four hours with a axis deadzone of 4096.

All tests are run with the throttle's axis-based inputs set to minimum (both throttles fully back, rotarys fully counter-clockwise, etc) to avoid bumping the device and creating non-ghost input. Unless otherwise stated, the LED lights are set to full white.

## Testing results

### Throttle only, motherboard USB port 1

```
20:06:43 - Test Throttle only, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Throttle only, motherboard USB port 2

```
08:05:28 - Test Throttle only, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Throttle only, Belkin F4U073 port 1

```
12:23:20 - Test Throttle only, 4.0 hours
13:23:16 - Throt : Rotary 1 = -9984
13:23:16 - Throt : Rotary 1 = -11776
13:23:16 - Throt : Rotary 1 = -12800
13:23:16 - Throt : Rotary 1 = -15104
13:23:16 - Throt : Rotary 1 = -16128
13:23:16 - Throt : Rotary 1 = -17920
13:23:16 - Throt : Rotary 1 = -18432
13:23:16 - Throt : Rotary 1 = -19968
13:23:16 - Throt : Rotary 1 = -20992
13:23:16 - Throt : Rotary 1 = -22784
13:23:16 - Throt : Rotary 1 = -23552
13:23:16 - Throt : Rotary 1 = -24320
13:23:16 - Throt : Rotary 1 = -26112
13:23:16 - Throt : Rotary 1 = -26624
14 events in 4.0 hours: 3.5 events/hour
```

### Throttle only, Belkin F4U073 USB port 2

```

```

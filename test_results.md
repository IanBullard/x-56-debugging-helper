# Test Results

The test application knows:

1. What devices are connected on startup.
2. How long the test will last (hard coded).
3. Any inputs that occur during the test.  For axis input, a hard-coded deadzone is assumed.

The result of the test is the number of ghost events/test time.

For these tests, the test length is four hours with a axis deadzone of 4096.

All tests are run with the throttle's axis-based inputs set to minimum (both throttles fully back, rotarys fully counter-clockwise, etc) to avoid bumping the device and creating non-ghost input. Unless otherwise stated, the LED lights are set to full white.

## Summary

USB port names are M for motherboard or E for external and the port number (1-4).  The first port is for the stick and the second is for the throttle.

| Test | Ports | Test # | Events/Hour |
| :-- | :-: | :-: | :-: |
| Throttle only | M1/- | 1 | 0.0 |
| Throttle only | M2/- | 1 | 0.0 |
| Throttle only | E1/- | 1 | 3.5 |
| Throttle only | E2/- | 1 | 0.0 |
| Throttle only | E3/- | 1 | 0.0 |
| Throttle only | E4/- | 1 | 6.5 |
| Stick only | M1/- | 1 | 15.2 |
| Stick only | M2/- | 1 | 0.5 |
| Stick only | E1/- | 1 | 0.0 |
| Stick only | E2/- | 1 | 0.0 |
| Stick only | E3/- | 1 | - |
| Stick only | E4/- | 1 | - |
| Both | M1/M2 | 1 | - |
| Both | E1/M1 | 1 | - |
| Both | M1/E1 | 1 | - |
| Both | E1/E2 | 1 | - |

## Individual Test Results
````md
<details>
  <summary>Throttle only, motherboard USB port 1</summary>

    ```
    20:06:43 - Test Throttle only, 4.0 hours
    0 events in 4.0 hours: 0.0 events/hour
    ```
</details>

````


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
17:00:45 - Test Throttle only, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Throttle only, Belkin F4U073 USB port 3

```
21:01:49 - Test Throttle only, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Throttle only, Belkin F4U073 USB port 4

```
07:58:37 - Test Throttle only, 4.0 hours 
09:11:50 - Throt : Rotary 1 = -26624     
09:11:50 - Throt : Rotary 1 = -25856     
09:11:50 - Throt : Rotary 1 = -25600     
09:11:50 - Throt : Rotary 1 = -24832     
09:11:50 - Throt : Rotary 1 = -24576     
09:11:50 - Throt : Rotary 1 = -24320     
09:12:56 - Throt : Rotary 1 = -23808     
09:12:56 - Throt : Rotary 1 = -23296     
09:12:56 - Throt : Rotary 1 = -23040     
09:12:56 - Throt : Rotary 1 = -22272     
09:12:56 - Throt : Rotary 1 = -21504     
09:12:56 - Throt : Rotary 1 = -21248     
09:12:56 - Throt : Rotary 1 = -20992     
09:12:56 - Throt : Rotary 1 = -20224     
09:12:56 - Throt : Rotary 1 = -19968     
09:12:56 - Throt : Rotary 1 = -19456     
09:12:56 - Throt : Rotary 1 = -19200     
09:12:56 - Throt : Rotary 1 = -18688     
09:12:56 - Throt : Rotary 1 = -18432     
09:12:56 - Throt : Rotary 1 = -18176     
09:12:56 - Throt : Rotary 1 = -18432     
09:12:56 - Throt : Rotary 1 = -18688     
09:12:56 - Throt : Rotary 1 = -18944     
09:12:56 - Throt : Rotary 1 = -19200     
09:12:56 - Throt : Rotary 1 = -18944     
09:12:56 - Throt : Rotary 1 = -19200     
26 events in 4.0 hours: 6.5 events/hour  
```

### Stick only, motherboard USB port 1

```
16:35:31 - Test Joystick only, 4.0 hours
16:35:40 - Stick : Twist = 5014
16:35:40 - Stick : Twist = 8040
16:35:40 - Stick : Twist = 4517
16:35:40 - Stick : C Stick X = -5632
16:35:42 - Stick : C Stick Y = -4352
17:17:51 - Stick : Twist = 8553
17:17:51 - Stick : Twist = 4533
17:17:51 - Stick : C Stick Y = -4096
17:17:51 - Stick : Twist = 10058
17:17:52 - Stick : Twist = 8056
17:17:53 - Stick : Twist = 6551
SIGINT received, it may take up 60.00 seconds to quit.
11 events in 0.7 hours: 15.2 events/hour
```

### Stick only, motherboard USB port 2

```
22:14:49 - Test Joystick only, 4.0 hours
22:17:49 - Stick : C Stick Y = -4352
22:22:03 - Stick : Twist = 4677
2 events in 4.0 hours: 0.5 events/hour
```

### Stick only, Belkin F4U073 port 1

```
08:11:54 - Test Joystick only, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```
### Stick only, Belkin F4U073 port 2

```
```

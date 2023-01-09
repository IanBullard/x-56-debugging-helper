# Test Results

The test application knows:

1. What devices are connected on startup.
2. How long the test will last (hard coded).
3. Any inputs that occur during the test.  For axis input, a hard-coded deadzone is assumed.

The result of the test is the number of ghost events/test time.

For these tests, the test length is four hours with a axis deadzone of 4096.

All tests are run with the throttle's axis-based inputs set to minimum (both throttles fully back, rotarys fully counter-clockwise, etc) to avoid bumping the device and creating non-ghost input. Unless otherwise stated, the LED lights are set to full white.

The external USB hug I'm using is a Belkin F4U073.

## Summary

USB port names are M for motherboard or E for external and the port number (1-4).  The first port is for the stick and the second is for the throttle.

| Test | Ports | Test # | Events/Hour |
| :-- | :-: | :-: | :-: |
| [Throttle only](#throttle-only-m1) | -/M1 | 1 | 0.0 |
| [Throttle only](#throttle-only-m2) | -/M2 | 1 | 0.0 |
| [Throttle only](#throttle-only-e1) | -/E1 | 1 | 3.5 |
| [Throttle only](#throttle-only-e2) | -/E2 | 1 | 0.0 |
| [Throttle only](#throttle-only-e3) | -/E3 | 1 | 0.0 |
| [Throttle only](#throttle-only-e4) | -/E4 | 1 | 6.5 |
| [Stick only](#stick-only-m1) | M1/- | 1 | 6.2 |
| [Stick only](#stick-only-m2) | M2/- | 1 | 0.5 |
| [Stick only](#stick-only-e1) | E1/- | 1 | 0.0 |
| [Stick only](#stick-only-e2) | E2/- | 1 | 0.0 |
| [Stick only](#stick-only-e3) | E3/- | 1 | 0.0 |
| [Stick only](#stick-only-e4) | E4/- | 1 | 0.0 |
| [Both](#both-m1m2) | M1/M2 | 1 | 0.5 |
| [Both](#both-e1m1) | E1/M1 | 1 | 0.0 |
| [Both](#both-m1e1) | M1/E1 | 1 | - |
| [Both](#both-e1e2) | E1/E2 | 1 | - |

## Individual Test Results

### Throttle only M1

```
20:06:43 - Test Throttle only, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Throttle only M2

```
08:05:28 - Test Throttle only, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Throttle only E1

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

### Throttle only E2

```
17:00:45 - Test Throttle only, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Throttle only E3

```
21:01:49 - Test Throttle only, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Throttle only E4

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

### Stick only M1

```
16:57:31 - Test Joystick only, 4.0 hour
17:17:51 - Stick : C Stick Y = -4096   
17:17:53 - Stick : Twist = 7880        
17:17:53 - Stick : C Stick X = -5120   
17:17:54 - Stick : Twist = 7384        
17:22:27 - Stick : C Stick X = -7168   
17:22:30 - Stick : Twist = 6583        
17:22:38 - Stick : Twist = 7047        
17:22:39 - Stick : Twist = 8072        
17:25:58 - Stick : C Stick X = -7168   
17:26:00 - Stick : Twist = 8072        
17:42:44 - Stick : Twist = 6519        
17:42:45 - Stick : Twist = 7047        
19:51:03 - Stick : Twist = 7400        
19:51:05 - Stick : C Stick Y = -4608   
19:52:06 - Stick : Twist = 7416        
19:55:27 - Stick : C Stick X = -7168   
19:55:31 - Stick : Twist = 5414        
19:55:32 - Stick : Twist = 7400        
19:55:40 - Stick : Twist = 8393        
20:05:41 - Stick : C Stick Y = -5632   
20:05:42 - Stick : Twist = 6887        
20:10:49 - Stick : Twist = 4901        
20:26:54 - Stick : C Stick X = -6144   
20:31:30 - Stick : C Stick X = -6912   
20:31:31 - Stick : C Stick X = -6144   
25 events in 4.0 hours: 6.2 events/hour
```

### Stick only M2

```
22:14:49 - Test Joystick only, 4.0 hours
22:17:49 - Stick : C Stick Y = -4352
22:22:03 - Stick : Twist = 4677
2 events in 4.0 hours: 0.5 events/hour
```

### Stick only E1

```
08:11:54 - Test Joystick only, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Stick only E2

```
15:07:14 - Test Joystick only, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Stick only E3

```
19:12:33 - Test Joystick only, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Stick only E4

```
10:58:52 - Test Joystick only, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Both M1/M2

```
09:59:05 - Test Joystick and throttle, 4.0 hours
12:16:14 - Stick : Twist = 4853
12:53:54 - Stick : Twist = 6935
2 events in 4.0 hours: 0.5 events/hour
```

### Both E1/M1

```
16:22:41 - Test Joystick and throttle, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Both M1/E1

```
```

### Both E1/E2

```
```
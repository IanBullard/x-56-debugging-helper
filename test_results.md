# Test Results

The test application knows:

1. What devices are connected on startup.
2. How long the test will last (hard coded).
3. Any inputs that occur during the test.  For axis input, a hard-coded deadzone is assumed.

The result of the test is the number of ghost events/test time.

For these tests, the test length is four hours with a axis deadzone of 4096.

All tests are run with the throttle's axis-based inputs set to minimum (both throttles fully back, rotarys fully counter-clockwise, etc) to avoid bumping the device and creating non-ghost input. Unless otherwise stated, the LED lights are set to full white.

The external USB hug I'm using is a Belkin F4U073.

All of these tests have a flaw in that no user input will be happening, which could be a factor of how often the bug occurs.  I have had the ghost input bug happen to me during Elite Dangerous while no user input is happening, so I hope these tests will be enough to get some data.

## Baseline

Testing matrix:

1. Throttle plugged into motherboard port 1/2
2. Stick plugged into motherboard port 1/2
3. Throttle + stick port combinations
4. 1-3 repeated with external powered hub.

USB port names are M for motherboard or E for external and the port number (1-4).  The first port is for the stick and the second is for the throttle.

| Test | Ports | Events/Hour |
| :-- | :-: | :-: |
| [Throttle only](#throttle-only-m1) | -/M1 | 0.0 |
| [Throttle only](#throttle-only-m2) | -/M2 | 0.0 |
| [Throttle only](#throttle-only-e1) | -/E1 | 3.5 |
| [Throttle only](#throttle-only-e2) | -/E2 | 0.0 |
| [Throttle only](#throttle-only-e3) | -/E3 | 0.0 |
| [Throttle only](#throttle-only-e4) | -/E4 | 6.5 |
| [Stick only](#stick-only-m1) | M1/- | 6.2 |
| [Stick only](#stick-only-m2) | M2/- | 0.5 |
| [Stick only](#stick-only-e1) | E1/- | 0.0 |
| [Stick only](#stick-only-e2) | E2/- | 0.0 |
| [Stick only](#stick-only-e3) | E3/- | 0.0 |
| [Stick only](#stick-only-e4) | E4/- | 0.0 |
| [Both](#both-m1m2) | M1/M2 | 0.5 |
| [Both](#both-e1m1) | E1/M1 | 0.0 |
| [Both](#both-m1e1) | M1/E1 | 2.0 |
| [Both](#both-e1e2) | E1/E2 | 0.0 |

Results:

I think we can rule out specific USB ports being the cause of ghost inputs.  There seems to be no pattern for the bug.  However, I wasn't careful about how cables were run to the USB port and one of the suggested solutions is to add ferrite cores to reduce noise, so that should be the focus of the next test

## Noise Test

All tests are going to be done with the external hub, using the first two ports.

Note: when I did the baseline test, both usb cables where looped about 6" in diameter to manage the extra cable length and then plugged them into the appropriate port.  For this test, the cables are unwound and routed as described.

Testing matrix:

1. Twist the two cables of the stick & throttle around each other.
2. Run the cables through other cables on my desk.
3. Keep the cables away from all other cables (as best as possible).

| Test | Ports | Events/Hour |
| :-- | :-: | :-: |
| [Cables twisted](#cables-twisted) | M1/M2 | 135.7 |
| [Through desk](#through-desk) | M1/M2 | 112.5 |
| [Cables separated](#cables-separated) | M1/M2 | 302.5 |

The results are interesting, the throttle has an incredible amount of ghost inputs when I unrolled the usb cable.  I think the ferrite core test is a good next step.

## Ferrite Test

This test is the same as the [line noise test](#noise-test) but I've added a 13mm (5 mm inner diameter) ferrite core to each end of the usb cables, about two inches from the device/plug. I've also added a test that mimics the old setup (usb cables coiled up).

Testing matrix:

1. Usb cables where looped about 6" in diameter
2. Twist the two cables of the stick & throttle around each other.
3. Run the cables through other cables on my desk.
4. Keep the cables away from all other cables (as best as possible).

| Test | Ports | Events/Hour |
| :-- | :-: | :-: |
| [Cables bundled](#ferrite-cables-bundled) | M1/M2 | 0.0 |
| [Cables twisted](#ferrite-cables-twisted) | M1/M2 | 0.0 |
| [Through desk](#ferrite-through-desk) | M1/M2 | 0.0 |
| [Cables separated](#ferrite-cables-separated) | M1/M2 | 0.0 |

I think the problem is solved at this point.

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
20:29:09 - Test Joystick and throttle, 4.0 hours
20:42:14 - Stick : C Stick X = -7168
20:42:18 - Stick : Twist = 4581
20:43:14 - Stick : Twist = 6103
21:10:02 - Stick : Twist = 8681
21:17:16 - Stick : Twist = 7608
21:17:17 - Stick : Twist = 7095
00:01:39 - Stick : C Stick X = -6400
00:01:41 - Stick : C Stick Y = -4608
8 events in 4.0 hours: 2.0 events/hour
```

### Both E1/E2

```
07:46:09 - Test Joystick and throttle, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Cables twisted

```
16:15:28 - Test Joystick and throttle, 4.0 hours
16:16:56 - Throt : Rotary 3 = 4942
16:16:56 - Throt : Rotary 3 = -31488
16:16:56 - Throt : Rotary 3 = 4942
16:16:56 - Throt : Rotary 4 = -12288
16:16:56 - Throt : Rotary 4 = -31744
16:16:56 - Throt : Rotary 4 = -12288
16:18:16 - Throt : Rotary 1 = -32768
16:18:16 - Throt : Rotary 1 = -31488
16:18:16 - Throt : Rotary 1 = -32768
16:19:47 - Throt : Mouse Ministick X = -31744
16:22:04 - Throt : H = 1
16:22:04 - Throt : SW 2 = 1
16:22:04 - Throt : H = 0
16:22:04 - Throt : SW 2 = 0
16:22:08 - Throt : Left Throttle = -16128
16:22:10 - Throt : Left Throttle = -32448
16:22:33 - Throt : Right Throttle = -11968
16:23:05 - Throt : Right Throttle = -11968
16:23:59 - Throt : Rotary 1 = -31744
16:23:59 - Throt : Rotary 1 = -32768
16:25:25 - Throt : Mouse Ministick X = -31744
16:25:29 - Throt : H = 1
16:25:29 - Throt : SW 2 = 1
16:25:29 - Throt : H = 0
16:25:29 - Throt : SW 2 = 0
16:27:58 - Throt : Mouse Ministick Y = -31744
16:28:14 - Throt : H3 Forward = 1
16:28:14 - Throt : H3 Back = 1
16:28:14 - Throt : H3 Forward = 0
16:28:14 - Throt : H3 Back = 0
16:28:29 - Throt : Right Throttle = -11968
16:29:41 - Throt : Mouse Ministick X = -31488
16:31:44 - Throt : Mouse Ministick X = -31488
16:33:45 - Throt : H = 1
16:33:45 - Throt : SW 2 = 1
16:33:45 - Throt : H = 0
16:33:45 - Throt : SW 2 = 0
16:34:11 - Throt : Rotary 2 = -31488
16:34:31 - Throt : Scroll BCK = 1
16:34:31 - Throt : Scroll BCK = 0
16:36:27 - Throt : Rotary 3 = -31488
16:36:27 - Throt : Rotary 3 = 4942
16:40:04 - Throt : Mouse Ministick X = -31488
16:40:39 - Throt : TGL 2 Down = 1
16:40:39 - Throt : TGL 2 Down = 0
16:41:21 - Throt : TGL 1 Down = 1
16:41:21 - Throt : TGL 2 Down = 1
16:41:22 - Throt : TGL 1 Down = 0
16:41:22 - Throt : TGL 2 Down = 0
16:41:25 - Throt : Rotary 1 = -31488
16:41:25 - Throt : Rotary 1 = -32768
16:43:45 - Throt : Mouse Ministick X = -31488
16:45:10 - Throt : Mouse Ministick Y = -31488
16:46:22 - Throt : Mouse Ministick Y = -31488
16:48:00 - Throt : Rotary 4 = -31744
16:48:00 - Throt : Rotary 4 = -12288
16:48:24 - Throt : Rotary 1 = -31488
16:48:24 - Throt : Rotary 1 = -32768
16:49:25 - Throt : Mouse Ministick X = -31488
16:49:56 - Throt : Mouse Ministick Y = -31488
16:50:18 - Throt : Rotary 1 = -31488
16:50:18 - Throt : Rotary 1 = -32768
16:52:19 - Throt : H3 Forward = 1
16:52:19 - Throt : H3 Back = 1
16:52:19 - Throt : H3 Forward = 0
16:52:19 - Throt : H3 Back = 0
16:52:45 - Throt : TGL 2 Down = 1
16:52:45 - Throt : TGL 2 Down = 0
16:54:38 - Throt : KI Down = 1
16:54:38 - Throt : Scroll BCK = 1
16:54:38 - Throt : KI Down = 0
16:54:38 - Throt : Scroll BCK = 0
16:55:03 - Throt : Scroll BCK = 1
16:55:03 - Throt : Scroll BCK = 0
16:56:40 - Throt : Mouse Ministick Y = -31488
16:56:49 - Throt : Mouse Ministick X = -31488
16:57:22 - Throt : Rotary 2 = -31488
16:57:32 - Throt : Mouse Ministick X = -31488
16:58:04 - Throt : Right Throttle = -16128
17:01:16 - Throt : Rotary 3 = -31488
17:01:16 - Throt : Rotary 3 = 4942
17:01:52 - Throt : Rotary 1 = -31744
17:01:52 - Throt : Rotary 1 = -32768
17:02:11 - Throt : Mouse Ministick X = -31488
17:02:23 - Throt : KI Down = 1
17:02:23 - Throt : Scroll BCK = 1
17:02:23 - Throt : KI Down = 0
17:02:23 - Throt : Scroll BCK = 0
17:03:29 - Throt : Rotary 4 = -31744
17:03:29 - Throt : Rotary 4 = -12288
17:04:28 - Throt : Mouse Ministick X = -31488
17:04:35 - Throt : Mouse Ministick Y = -31744
17:06:03 - Throt : TGL 2 Down = 1
17:06:03 - Throt : TGL 2 Down = 0
17:07:24 - Throt : Mouse Ministick Y = -31488
17:07:46 - Throt : KI Down = 1
17:07:46 - Throt : Scroll BCK = 1
17:07:46 - Throt : KI Down = 0
17:07:46 - Throt : Scroll BCK = 0
17:08:17 - Throt : Mouse Ministick Y = -31488
17:08:23 - Throt : H = 1
17:08:23 - Throt : SW 2 = 1
17:08:23 - Throt : H = 0
17:08:23 - Throt : SW 2 = 0
17:09:10 - Throt : Rotary 2 = -31488
17:10:20 - Throt : Rotary 4 = -31488
17:10:20 - Throt : Rotary 4 = -12288
17:11:33 - Throt : Right Throttle = -11968
17:11:36 - Throt : Mouse Ministick Y = -31488
17:12:17 - Throt : Rotary 4 = -31744
17:12:17 - Throt : Rotary 4 = -12288
17:13:10 - Throt : TGL 2 Down = 1
17:13:10 - Throt : TGL 2 Down = 0
17:13:47 - Throt : Left Throttle = -16064
17:14:19 - Throt : Left Throttle = -32512
17:15:32 - Throt : Right Throttle = -11968
17:16:17 - Throt : Right Throttle = -11968
17:16:36 - Throt : KI Down = 1
17:16:36 - Throt : Scroll BCK = 1
17:16:36 - Throt : KI Down = 0
17:16:36 - Throt : Scroll BCK = 0
17:18:23 - Throt : H = 1
17:18:23 - Throt : SW 2 = 1
17:18:23 - Throt : H = 0
17:18:23 - Throt : SW 2 = 0
17:19:42 - Throt : Rotary 1 = -31488
17:19:42 - Throt : Rotary 1 = -32768
17:20:07 - Throt : Right Throttle = -11968
17:20:44 - Throt : Rotary 2 = -31488
17:21:05 - Throt : H3 Forward = 1
17:21:05 - Throt : H3 Back = 1
17:21:05 - Throt : H3 Forward = 0
17:21:05 - Throt : H3 Back = 0
17:22:41 - Throt : H = 1
17:22:41 - Throt : SW 2 = 1
17:22:41 - Throt : H = 0
17:22:41 - Throt : SW 2 = 0
17:22:51 - Throt : Rotary 1 = -31488
17:22:51 - Throt : Rotary 1 = -32768
17:23:05 - Throt : H = 1
17:23:05 - Throt : SW 2 = 1
17:23:05 - Throt : H = 0
17:23:05 - Throt : SW 2 = 0
17:23:20 - Throt : TGL 1 Down = 1
17:23:20 - Throt : TGL 2 Down = 1
17:23:20 - Throt : TGL 1 Down = 0
17:23:20 - Throt : TGL 2 Down = 0
17:23:49 - Throt : Rotary 4 = -31488
17:23:49 - Throt : Rotary 4 = -12288
17:24:13 - Throt : Rotary 2 = -31488
17:26:24 - Throt : Rotary 4 = -31488
17:26:24 - Throt : Rotary 4 = -12288
17:27:29 - Throt : TGL 1 Down = 1
17:27:29 - Throt : TGL 2 Down = 1
17:27:29 - Throt : TGL 1 Down = 0
17:27:29 - Throt : TGL 2 Down = 0
17:27:59 - Throt : H = 1
17:27:59 - Throt : SW 2 = 1
17:27:59 - Throt : H = 0
17:27:59 - Throt : SW 2 = 0
17:28:07 - Throt : Rotary 1 = -31744
17:28:07 - Throt : Rotary 1 = -32768
17:28:09 - Throt : KI Down = 1
17:28:09 - Throt : Scroll BCK = 1
17:28:09 - Throt : KI Down = 0
17:28:09 - Throt : Scroll BCK = 0
17:28:30 - Throt : Mouse Ministick X = -31488
17:29:52 - Throt : Mouse Ministick Y = -31488
17:30:19 - Throt : Left Throttle = -32512
17:30:39 - Throt : Rotary 1 = -31488
17:30:39 - Throt : Rotary 1 = -32768
17:31:59 - Throt : H3 Back = 1
17:31:59 - Throt : H3 Back = 0
17:32:08 - Throt : Rotary 1 = -31488
17:32:08 - Throt : Rotary 1 = -32768
17:32:43 - Throt : Left Throttle = -32448
17:33:41 - Throt : Right Throttle = -16128
17:34:13 - Throt : Rotary 3 = -31744
17:34:13 - Throt : Rotary 3 = 4942
17:34:35 - Throt : H = 1
17:34:35 - Throt : SW 2 = 1
17:34:35 - Throt : H = 0
17:34:35 - Throt : SW 2 = 0
17:37:02 - Throt : Rotary 4 = -31488
17:37:02 - Throt : Rotary 4 = -12288
17:37:37 - Throt : Left Throttle = -16128
17:38:57 - Throt : H = 1
17:38:57 - Throt : SW 2 = 1
17:38:57 - Throt : H = 0
17:38:57 - Throt : SW 2 = 0
17:39:41 - Throt : Mouse Ministick Y = -31488
17:40:04 - Throt : Rotary 3 = -31488
17:40:04 - Throt : Rotary 3 = 4942
17:40:14 - Throt : Rotary 2 = -31488
17:40:24 - Throt : Scroll BCK = 1
17:40:24 - Throt : Scroll BCK = 0
17:40:38 - Throt : Left Throttle = -16128
17:40:48 - Throt : Rotary 4 = -31488
17:40:48 - Throt : Rotary 4 = -12288
17:41:16 - Throt : Rotary 4 = -31744
17:41:16 - Throt : Rotary 4 = -12288
17:41:18 - Throt : Left Throttle = -16128
17:41:51 - Throt : H = 1
17:41:51 - Throt : SW 2 = 1
17:41:51 - Throt : H = 0
17:41:51 - Throt : SW 2 = 0
17:42:02 - Throt : H3 Forward = 1
17:42:02 - Throt : H3 Back = 1
17:42:02 - Throt : H3 Forward = 0
17:42:02 - Throt : H3 Back = 0
17:42:25 - Throt : Right Throttle = -11968
17:43:01 - Throt : H = 1
17:43:01 - Throt : SW 2 = 1
17:43:01 - Throt : H = 0
17:43:01 - Throt : SW 2 = 0
17:44:46 - Throt : Rotary 2 = -31744
17:45:49 - Throt : Rotary 3 = -31744
17:45:49 - Throt : Rotary 3 = 4942
17:47:10 - Throt : Rotary 4 = -31744
17:47:10 - Throt : Rotary 4 = -12288
17:48:11 - Throt : H3 Back = 1
17:48:11 - Throt : H3 Back = 0
17:50:50 - Throt : Rotary 1 = -31488
17:50:51 - Throt : Rotary 1 = -32768
17:52:44 - Throt : H3 Back = 1
17:52:44 - Throt : H3 Back = 0
17:53:06 - Throt : Mouse Ministick Y = -31488
17:53:42 - Throt : KI Down = 1
17:53:42 - Throt : Scroll BCK = 1
17:53:42 - Throt : KI Down = 0
17:53:42 - Throt : Scroll BCK = 0
17:55:12 - Throt : Left Throttle = -16128
17:55:15 - Throt : Left Throttle = -16128
17:56:11 - Throt : Left Throttle = -16064
17:56:15 - Throt : Right Throttle = -11968
17:57:10 - Throt : Mouse Ministick Y = -31488
17:57:26 - Throt : Scroll BCK = 1
17:57:26 - Throt : Scroll BCK = 0
17:59:07 - Throt : Mouse Ministick X = -31744
17:59:29 - Throt : Scroll BCK = 1
17:59:29 - Throt : Scroll BCK = 0
18:00:49 - Throt : TGL 1 Down = 1
18:00:49 - Throt : TGL 2 Down = 1
18:00:49 - Throt : TGL 1 Down = 0
18:00:49 - Throt : TGL 2 Down = 0
18:03:02 - Throt : Rotary 3 = -31488
18:03:02 - Throt : Rotary 3 = 4942
18:03:48 - Throt : Rotary 1 = -31488
18:03:48 - Throt : Rotary 1 = -32768
18:04:59 - Throt : H3 Forward = 1
18:04:59 - Throt : H3 Back = 1
18:04:59 - Throt : H3 Forward = 0
18:04:59 - Throt : H3 Back = 0
18:05:31 - Throt : KI Down = 1
18:05:31 - Throt : Scroll BCK = 1
18:05:31 - Throt : KI Down = 0
18:05:31 - Throt : Scroll BCK = 0
18:06:06 - Throt : Right Throttle = -16128
18:07:58 - Throt : KI Down = 1
18:07:58 - Throt : Scroll BCK = 1
18:07:58 - Throt : KI Down = 0
18:07:58 - Throt : Scroll BCK = 0
18:08:06 - Throt : Rotary 1 = -31488
18:08:06 - Throt : Rotary 1 = -32768
18:09:42 - Throt : H3 Forward = 1
18:09:42 - Throt : H3 Back = 1
18:09:42 - Throt : H3 Forward = 0
18:09:42 - Throt : H3 Back = 0
18:10:45 - Throt : Mouse Ministick X = -31488
18:11:35 - Throt : Mouse Ministick Y = -31488
18:11:54 - Throt : SW 2 = 1
18:11:54 - Throt : SW 2 = 0
18:13:08 - Throt : Mouse Ministick Y = -31488
18:13:25 - Throt : Rotary 4 = -31488
18:13:25 - Throt : Rotary 4 = -12288
18:13:27 - Throt : KI Down = 1
18:13:27 - Throt : Scroll BCK = 1
18:13:27 - Throt : KI Down = 0
18:13:27 - Throt : Scroll BCK = 0
18:13:55 - Throt : H3 Forward = 1
18:13:55 - Throt : H3 Back = 1
18:13:55 - Throt : H3 Forward = 0
18:13:55 - Throt : H3 Back = 0
18:14:28 - Throt : KI Down = 1
18:14:28 - Throt : Scroll BCK = 1
18:14:28 - Throt : KI Down = 0
18:14:28 - Throt : Scroll BCK = 0
18:15:37 - Throt : SW 2 = 1
18:15:37 - Throt : SW 2 = 0
18:15:57 - Throt : H = 1
18:15:57 - Throt : SW 2 = 1
18:15:57 - Throt : H = 0
18:15:57 - Throt : SW 2 = 0
18:16:14 - Throt : Rotary 3 = -31488
18:16:14 - Throt : Rotary 3 = 4942
18:19:18 - Throt : Right Throttle = -11968
18:21:29 - Throt : Left Throttle = -16128
18:21:38 - Throt : Mouse Ministick Y = -31488
18:21:44 - Throt : KI Down = 1
18:21:44 - Throt : Scroll BCK = 1
18:21:44 - Throt : KI Down = 0
18:21:44 - Throt : Scroll BCK = 0
18:22:08 - Throt : H3 Back = 1
18:22:08 - Throt : H3 Back = 0
18:24:23 - Throt : Rotary 4 = -12032
18:24:23 - Throt : Rotary 4 = -12288
18:24:49 - Throt : Rotary 4 = -12032
18:24:49 - Throt : Rotary 4 = -12288
18:29:55 - Throt : Mouse Ministick Y = -31488
18:30:10 - Throt : Rotary 4 = -31488
18:30:10 - Throt : Rotary 4 = -12288
18:30:22 - Throt : H = 1
18:30:22 - Throt : SW 2 = 1
18:30:22 - Throt : H = 0
18:30:22 - Throt : SW 2 = 0
18:31:30 - Throt : Rotary 4 = -31488
18:31:30 - Throt : Rotary 4 = -12288
18:31:42 - Throt : H3 Forward = 1
18:31:42 - Throt : H3 Back = 1
18:31:42 - Throt : H3 Forward = 0
18:31:42 - Throt : H3 Back = 0
18:31:55 - Throt : Left Throttle = -16128
18:32:03 - Throt : KI Down = 1
18:32:03 - Throt : Scroll BCK = 1
18:32:03 - Throt : KI Down = 0
18:32:03 - Throt : Scroll BCK = 0
18:33:40 - Throt : TGL 1 Down = 1
18:33:40 - Throt : TGL 2 Down = 1
18:33:40 - Throt : TGL 1 Down = 0
18:33:40 - Throt : TGL 2 Down = 0
18:35:01 - Throt : TGL 1 Down = 1
18:35:01 - Throt : TGL 2 Down = 1
18:35:01 - Throt : TGL 1 Down = 0
18:35:01 - Throt : TGL 2 Down = 0
18:35:18 - Throt : Right Throttle = -11968
18:36:20 - Throt : KI Down = 1
18:36:20 - Throt : Scroll BCK = 1
18:36:20 - Throt : KI Down = 0
18:36:20 - Throt : Scroll BCK = 0
18:37:02 - Throt : Mouse Ministick X = -31488
18:38:37 - Throt : H = 1
18:38:37 - Throt : SW 2 = 1
18:38:37 - Throt : H = 0
18:38:37 - Throt : SW 2 = 0
18:40:05 - Throt : H3 Forward = 1
18:40:05 - Throt : H3 Back = 1
18:40:05 - Throt : H3 Forward = 0
18:40:05 - Throt : H3 Back = 0
18:41:13 - Throt : Rotary 2 = -31488
18:43:30 - Throt : Rotary 4 = -31488
18:43:30 - Throt : Rotary 4 = -12288
18:44:03 - Throt : Rotary 3 = -31488
18:44:03 - Throt : Rotary 3 = 4942
18:44:10 - Throt : H = 1
18:44:10 - Throt : SW 2 = 1
18:44:10 - Throt : H = 0
18:44:10 - Throt : SW 2 = 0
18:45:43 - Throt : Rotary 3 = -31488
18:45:43 - Throt : Rotary 3 = 4942
18:47:39 - Throt : Rotary 2 = -31488
18:48:31 - Throt : Mouse Ministick Y = -31488
18:50:17 - Throt : Rotary 4 = -31488
18:50:17 - Throt : Rotary 4 = -12288
18:51:56 - Throt : Rotary 2 = -31488
18:52:39 - Throt : Rotary 1 = -31744
18:52:39 - Throt : Rotary 1 = -32768
18:53:15 - Throt : Left Throttle = -32448
18:53:48 - Throt : TGL 1 Down = 1
18:53:48 - Throt : TGL 2 Down = 1
18:53:48 - Throt : TGL 1 Down = 0
18:53:48 - Throt : TGL 2 Down = 0
18:57:29 - Throt : Rotary 1 = -31488
18:57:29 - Throt : Rotary 1 = -32768
18:58:41 - Throt : Rotary 2 = -31488
19:01:38 - Throt : TGL 1 Down = 1
19:01:38 - Throt : TGL 2 Down = 1
19:01:38 - Throt : TGL 1 Down = 0
19:01:38 - Throt : TGL 2 Down = 0
19:03:44 - Throt : Left Throttle = -32512
19:04:18 - Throt : Rotary 1 = -31744
19:04:18 - Throt : Rotary 1 = -32768
19:04:50 - Throt : Rotary 3 = -31488
19:04:50 - Throt : Rotary 3 = 4942
19:04:57 - Throt : Right Throttle = -11968
19:05:18 - Throt : H = 1
19:05:18 - Throt : SW 2 = 1
19:05:18 - Throt : H = 0
19:05:18 - Throt : SW 2 = 0
19:05:37 - Throt : H3 Forward = 1
19:05:37 - Throt : H3 Back = 1
19:05:37 - Throt : H3 Forward = 0
19:05:37 - Throt : H3 Back = 0
19:05:55 - Throt : H = 1
19:05:55 - Throt : SW 2 = 1
19:05:55 - Throt : H = 0
19:05:55 - Throt : SW 2 = 0
19:06:09 - Throt : H3 Forward = 1
19:06:09 - Throt : H3 Back = 1
19:06:09 - Throt : H3 Forward = 0
19:06:09 - Throt : H3 Back = 0
19:06:18 - Throt : KI Down = 1
19:06:18 - Throt : Scroll BCK = 1
19:06:18 - Throt : KI Down = 0
19:06:18 - Throt : Scroll BCK = 0
19:07:27 - Throt : Mouse Ministick X = -31488
19:07:52 - Throt : Right Throttle = -11968
19:08:01 - Throt : Left Throttle = -32448
19:09:40 - Throt : Mouse Ministick X = -31744
19:10:39 - Throt : Rotary 3 = -31488
19:10:39 - Throt : Rotary 3 = 4942
19:10:59 - Throt : TGL 1 Down = 1
19:10:59 - Throt : TGL 2 Down = 1
19:10:59 - Throt : TGL 1 Down = 0
19:10:59 - Throt : TGL 2 Down = 0
19:11:39 - Throt : H3 Forward = 1
19:11:39 - Throt : H3 Back = 1
19:11:39 - Throt : H3 Forward = 0
19:11:39 - Throt : H3 Back = 0
19:11:43 - Throt : KI Down = 1
19:11:43 - Throt : Scroll BCK = 1
19:11:43 - Throt : KI Down = 0
19:11:43 - Throt : Scroll BCK = 0
19:12:59 - Throt : Left Throttle = -32448
19:14:38 - Throt : Left Throttle = -16128
19:14:53 - Throt : Rotary 4 = -31488
19:14:53 - Throt : Rotary 4 = -12288
19:15:13 - Throt : Rotary 1 = -31488
19:15:13 - Throt : Rotary 1 = -32768
19:15:38 - Throt : Rotary 1 = -31488
19:15:38 - Throt : Rotary 1 = -32768
19:17:05 - Throt : Rotary 2 = -31488
19:17:26 - Throt : Rotary 3 = -31488
19:17:26 - Throt : Rotary 3 = 4942
19:17:33 - Throt : Mouse Ministick X = -31488
19:19:34 - Throt : H3 Forward = 1
19:19:34 - Throt : H3 Back = 1
19:19:34 - Throt : H3 Forward = 0
19:19:34 - Throt : H3 Back = 0
19:20:30 - Throt : KI Down = 1
19:20:30 - Throt : Scroll BCK = 1
19:20:30 - Throt : KI Down = 0
19:20:30 - Throt : Scroll BCK = 0
19:20:59 - Throt : SW 2 = 1
19:20:59 - Throt : SW 2 = 0
19:21:50 - Throt : Rotary 2 = -31488
19:22:28 - Throt : H3 Forward = 1
19:22:28 - Throt : H3 Back = 1
19:22:28 - Throt : H3 Forward = 0
19:22:28 - Throt : H3 Back = 0
19:22:46 - Throt : Mouse Ministick Y = -31488
19:23:48 - Throt : Rotary 4 = -31744
19:23:48 - Throt : Rotary 4 = -12288
19:24:04 - Throt : Right Throttle = -16128
19:25:42 - Throt : Rotary 2 = -31488
19:26:38 - Throt : TGL 1 Down = 1
19:26:38 - Throt : TGL 2 Down = 1
19:26:39 - Throt : TGL 1 Down = 0
19:26:39 - Throt : TGL 2 Down = 0
19:26:40 - Throt : Rotary 4 = -31488
19:26:40 - Throt : Rotary 4 = -12288
19:27:31 - Throt : Rotary 4 = -12032
19:27:31 - Throt : Rotary 4 = -12288
19:27:34 - Throt : Mouse Ministick X = -31744
19:28:25 - Throt : Right Throttle = -11968
19:28:30 - Throt : Scroll BCK = 1
19:28:30 - Throt : Scroll BCK = 0
19:28:41 - Throt : H = 1
19:28:41 - Throt : SW 2 = 1
19:28:41 - Throt : H = 0
19:28:41 - Throt : SW 2 = 0
19:29:30 - Throt : TGL 1 Down = 1
19:29:30 - Throt : TGL 2 Down = 1
19:29:30 - Throt : TGL 1 Down = 0
19:29:30 - Throt : TGL 2 Down = 0
19:30:32 - Throt : H3 Forward = 1
19:30:32 - Throt : H3 Back = 1
19:30:32 - Throt : H3 Forward = 0
19:30:32 - Throt : H3 Back = 0
19:31:20 - Throt : Rotary 4 = -12032
19:31:20 - Throt : Rotary 4 = -12288
19:31:53 - Throt : Mouse Ministick Y = -31488
19:32:53 - Throt : Right Throttle = -11968
19:33:05 - Throt : Rotary 4 = -31744
19:33:05 - Throt : Rotary 4 = -12288
19:33:53 - Throt : Right Throttle = -11968
19:33:53 - Throt : Rotary 4 = -12032
19:33:53 - Throt : Rotary 4 = -12288
19:34:56 - Throt : Mouse Ministick Y = -31488
19:35:25 - Throt : Rotary 4 = -12032
19:35:25 - Throt : Rotary 4 = -12288
19:36:01 - Throt : H = 1
19:36:01 - Throt : SW 2 = 1
19:36:02 - Throt : H = 0
19:36:02 - Throt : SW 2 = 0
19:38:26 - Throt : Rotary 4 = -12032
19:38:26 - Throt : Rotary 4 = -12288
19:39:22 - Throt : KI Down = 1
19:39:22 - Throt : Scroll BCK = 1
19:39:23 - Throt : KI Down = 0
19:39:23 - Throt : Scroll BCK = 0
19:42:30 - Throt : Left Throttle = -16064
19:42:49 - Throt : Left Throttle = -16064
19:45:34 - Throt : Rotary 3 = -31488
19:45:34 - Throt : Rotary 3 = 4942
19:46:37 - Throt : Rotary 4 = -12032
19:46:37 - Throt : Rotary 4 = -12288
19:47:06 - Throt : Right Throttle = -11968
19:48:30 - Throt : Mouse Ministick X = -31488
19:50:31 - Throt : KI Down = 1
19:50:31 - Throt : Scroll BCK = 1
19:50:31 - Throt : KI Down = 0
19:50:31 - Throt : Scroll BCK = 0
19:50:43 - Throt : Left Throttle = -16128
19:51:26 - Throt : Rotary 4 = -12032
19:51:26 - Throt : Rotary 4 = -12288
19:53:46 - Throt : Rotary 4 = -12032
19:53:46 - Throt : Rotary 4 = -12288
19:53:46 - Throt : Right Throttle = -11968
19:56:26 - Throt : H3 Forward = 1
19:56:26 - Throt : H3 Back = 1
19:56:26 - Throt : H3 Forward = 0
19:56:26 - Throt : H3 Back = 0
19:57:28 - Throt : Rotary 1 = -31488
19:57:28 - Throt : Rotary 1 = -32768
19:59:17 - Throt : Left Throttle = -16128
20:00:36 - Throt : H = 1
20:00:36 - Throt : SW 2 = 1
20:00:36 - Throt : H = 0
20:00:36 - Throt : SW 2 = 0
20:00:52 - Throt : Right Throttle = -16128
20:01:44 - Throt : Left Throttle = -16128
20:02:05 - Throt : Rotary 3 = -31488
20:02:06 - Throt : Rotary 3 = 4942
20:04:01 - Throt : Rotary 4 = -31744
20:04:01 - Throt : Rotary 4 = -12288
20:06:57 - Throt : H3 Forward = 1
20:06:57 - Throt : H3 Back = 1
20:06:57 - Throt : H3 Forward = 0
20:06:57 - Throt : H3 Back = 0
20:14:15 - Throt : KI Down = 1
20:14:15 - Throt : Scroll BCK = 1
20:14:15 - Throt : KI Down = 0
20:14:15 - Throt : Scroll BCK = 0
543 events in 4.0 hours: 135.7 events/hour
```

### Through desk

```
20:21:11 - Test Joystick and throttle, 4.0 hours
20:21:26 - Throt : H3 Back = 1
20:21:26 - Throt : H3 Back = 0
20:21:28 - Throt : Mouse Ministick X = -31488
20:21:42 - Throt : H = 1
20:21:42 - Throt : SW 2 = 1
20:21:42 - Throt : H = 0
20:21:42 - Throt : SW 2 = 0
20:22:10 - Throt : Rotary 2 = -31488
20:22:26 - Throt : H = 1
20:22:26 - Throt : SW 2 = 1
20:22:26 - Throt : H = 0
20:22:26 - Throt : SW 2 = 0
20:23:04 - Throt : Right Throttle = -11968
20:26:05 - Throt : H3 Forward = 1
20:26:05 - Throt : H3 Back = 1
20:26:05 - Throt : H3 Forward = 0
20:26:05 - Throt : H3 Back = 0
20:27:30 - Throt : Mouse Ministick Y = -31488
20:29:38 - Throt : Left Throttle = -16128
20:30:55 - Throt : Rotary 4 = -12288
20:30:55 - Throt : Rotary 4 = -31488
20:30:55 - Throt : Rotary 4 = -12288
20:30:55 - Throt : Left Throttle = -32448
20:36:05 - Throt : H3 Forward = 1
20:36:05 - Throt : H3 Back = 1
20:36:05 - Throt : H3 Forward = 0
20:36:05 - Throt : H3 Back = 0
20:37:56 - Throt : Rotary 2 = -31488
20:39:13 - Throt : Rotary 1 = -32768
20:39:13 - Throt : Rotary 1 = -31488
20:39:13 - Throt : Rotary 1 = -32768
20:41:03 - Throt : H = 1
20:41:03 - Throt : SW 2 = 1
20:41:03 - Throt : H = 0
20:41:03 - Throt : SW 2 = 0
20:43:38 - Throt : Mouse Ministick Y = -31488
20:46:00 - Throt : H3 Back = 1
20:46:00 - Throt : H3 Back = 0
20:46:09 - Throt : H = 1
20:46:09 - Throt : SW 2 = 1
20:46:09 - Throt : H = 0
20:46:09 - Throt : SW 2 = 0
20:46:28 - Throt : Rotary 2 = -31488
20:46:31 - Throt : Rotary 3 = 4942
20:46:31 - Throt : Rotary 3 = -31488
20:46:31 - Throt : Rotary 3 = 4942
20:46:41 - Throt : Right Throttle = -11968
20:47:39 - Throt : TGL 1 Down = 1
20:47:39 - Throt : TGL 2 Down = 1
20:47:39 - Throt : TGL 1 Down = 0
20:47:39 - Throt : TGL 2 Down = 0
20:49:04 - Throt : Rotary 3 = -31488
20:49:04 - Throt : Rotary 3 = 4942
20:49:59 - Throt : Rotary 1 = -31488
20:49:59 - Throt : Rotary 1 = -32768
20:50:03 - Throt : Rotary 2 = -31488
20:51:37 - Throt : Rotary 3 = -31488
20:51:37 - Throt : Rotary 3 = 4942
20:52:17 - Throt : Left Throttle = -16128
20:52:40 - Throt : KI Down = 1
20:52:40 - Throt : Scroll BCK = 1
20:52:40 - Throt : KI Down = 0
20:52:40 - Throt : Scroll BCK = 0
20:52:54 - Throt : Right Throttle = -11968
20:55:07 - Throt : Rotary 1 = -31488
20:55:07 - Throt : Rotary 1 = -32768
20:55:16 - Throt : Rotary 1 = -31488
20:55:16 - Throt : Rotary 1 = -32768
20:56:27 - Throt : Mouse Ministick Y = -31488
20:58:42 - Throt : TGL 2 Down = 1
20:58:42 - Throt : TGL 2 Down = 0
20:59:48 - Throt : Rotary 3 = -31488
20:59:48 - Throt : Rotary 3 = 4942
20:59:52 - Throt : H3 Forward = 1
20:59:52 - Throt : H3 Back = 1
20:59:52 - Throt : H3 Forward = 0
20:59:52 - Throt : H3 Back = 0
21:01:23 - Throt : Mouse Ministick Y = -31744
21:01:23 - Throt : Left Throttle = -16064
21:01:29 - Throt : Mouse Ministick Y = -31488
21:01:33 - Throt : Right Throttle = -11968
21:02:57 - Throt : Left Throttle = -16128
21:04:23 - Throt : Rotary 4 = -31488
21:04:23 - Throt : Rotary 4 = -12288
21:05:42 - Throt : Mouse Ministick X = -31744
21:06:57 - Throt : Right Throttle = -11968
21:07:27 - Throt : Rotary 3 = -31488
21:07:27 - Throt : Rotary 3 = 4942
21:10:14 - Throt : Mouse Ministick Y = -31488
21:10:35 - Throt : TGL 1 Down = 1
21:10:35 - Throt : TGL 2 Down = 1
21:10:35 - Throt : TGL 1 Down = 0
21:10:35 - Throt : TGL 2 Down = 0
21:10:41 - Throt : Rotary 1 = -31488
21:10:41 - Throt : Rotary 1 = -32768
21:11:40 - Throt : TGL 1 Down = 1
21:11:40 - Throt : TGL 2 Down = 1
21:11:40 - Throt : TGL 1 Down = 0
21:11:40 - Throt : TGL 2 Down = 0
21:13:15 - Throt : H = 1
21:13:15 - Throt : SW 2 = 1
21:13:16 - Throt : H = 0
21:13:16 - Throt : SW 2 = 0
21:13:35 - Throt : Left Throttle = -32512
21:13:42 - Throt : H = 1
21:13:42 - Throt : SW 2 = 1
21:13:42 - Throt : H = 0
21:13:42 - Throt : SW 2 = 0
21:14:51 - Throt : Rotary 1 = -31744
21:14:51 - Throt : Rotary 1 = -32768
21:15:03 - Throt : KI Down = 1
21:15:03 - Throt : Scroll BCK = 1
21:15:03 - Throt : KI Down = 0
21:15:03 - Throt : Scroll BCK = 0
21:15:06 - Throt : Rotary 4 = -31488
21:15:06 - Throt : Rotary 4 = -12288
21:18:05 - Throt : Rotary 4 = -31488
21:18:06 - Throt : Rotary 4 = -12288
21:18:45 - Throt : Mouse Ministick X = -31744
21:19:07 - Throt : Mouse Ministick Y = -31488
21:20:39 - Throt : Mouse Ministick X = -31488
21:21:15 - Throt : Rotary 3 = -31488
21:21:15 - Throt : Rotary 3 = 4942
21:21:51 - Throt : Rotary 4 = -31488
21:21:51 - Throt : Rotary 4 = -12288
21:22:44 - Throt : KI Down = 1
21:22:44 - Throt : Scroll BCK = 1
21:22:44 - Throt : KI Down = 0
21:22:44 - Throt : Scroll BCK = 0
21:22:55 - Throt : KI Down = 1
21:22:55 - Throt : Scroll BCK = 1
21:22:55 - Throt : KI Down = 0
21:22:55 - Throt : Scroll BCK = 0
21:24:09 - Throt : Mouse Ministick Y = -31488
21:25:04 - Throt : Left Throttle = -32448
21:25:11 - Throt : H3 Forward = 1
21:25:11 - Throt : H3 Back = 1
21:25:11 - Throt : H3 Forward = 0
21:25:11 - Throt : H3 Back = 0
21:25:16 - Throt : Mouse Ministick Y = -31744
21:26:18 - Throt : H = 1
21:26:18 - Throt : SW 2 = 1
21:26:18 - Throt : H = 0
21:26:18 - Throt : SW 2 = 0
21:27:23 - Throt : Mouse Ministick X = -31488
21:27:44 - Throt : Mouse Ministick X = -31744
21:29:07 - Throt : Rotary 2 = -31488
21:30:28 - Throt : Mouse Ministick Y = -31488
21:32:33 - Throt : Rotary 4 = -31488
21:32:33 - Throt : Rotary 4 = -12288
21:32:58 - Throt : H = 1
21:32:58 - Throt : SW 2 = 1
21:32:58 - Throt : H = 0
21:32:58 - Throt : SW 2 = 0
21:34:07 - Throt : Mouse Ministick X = -31488
21:34:52 - Throt : Mouse Ministick Y = -31488
21:36:34 - Throt : TGL 1 Down = 1
21:36:34 - Throt : TGL 2 Down = 1
21:36:34 - Throt : TGL 1 Down = 0
21:36:34 - Throt : TGL 2 Down = 0
21:36:46 - Throt : Rotary 4 = -12032
21:36:46 - Throt : Rotary 4 = -12288
21:37:02 - Throt : Rotary 4 = -31744
21:37:02 - Throt : Rotary 4 = -12288
21:37:19 - Throt : Rotary 4 = -31488
21:37:19 - Throt : Rotary 4 = -12288
21:37:57 - Throt : Right Throttle = -11968
21:38:01 - Throt : Rotary 2 = -31488
21:38:33 - Throt : H3 Forward = 1
21:38:33 - Throt : H3 Back = 1
21:38:33 - Throt : H3 Forward = 0
21:38:33 - Throt : H3 Back = 0
21:39:48 - Throt : Scroll BCK = 1
21:39:48 - Throt : Scroll BCK = 0
21:40:03 - Throt : SW 2 = 1
21:40:03 - Throt : SW 2 = 0
21:40:17 - Throt : Mouse Ministick Y = -31488
21:40:45 - Throt : TGL 1 Down = 1
21:40:45 - Throt : TGL 2 Down = 1
21:40:45 - Throt : TGL 1 Down = 0
21:40:45 - Throt : TGL 2 Down = 0
21:41:20 - Throt : Rotary 3 = -31488
21:41:20 - Throt : Rotary 3 = 4942
21:42:58 - Throt : Mouse Ministick X = -31488
21:44:14 - Throt : Mouse Ministick Y = -31488
21:44:26 - Throt : Rotary 1 = -31488
21:44:26 - Throt : Rotary 1 = -32768
21:46:45 - Throt : Right Throttle = -11968
21:47:04 - Throt : TGL 1 Down = 1
21:47:04 - Throt : TGL 2 Down = 1
21:47:04 - Throt : TGL 1 Down = 0
21:47:04 - Throt : TGL 2 Down = 0
21:48:19 - Throt : Left Throttle = -16128
21:48:32 - Throt : Rotary 2 = -31488
21:48:41 - Throt : Right Throttle = -11968
21:50:40 - Throt : Right Throttle = -11968
21:51:14 - Throt : Rotary 1 = -31488
21:51:14 - Throt : Rotary 1 = -32768
21:51:33 - Throt : Left Throttle = -16128
21:51:42 - Throt : Rotary 4 = -31488
21:51:42 - Throt : Rotary 4 = -12288
21:57:44 - Throt : Left Throttle = -16064
21:58:15 - Throt : Rotary 4 = -12032
21:58:15 - Throt : Rotary 4 = -12288
21:58:23 - Throt : Mouse Ministick X = -31488
21:58:35 - Throt : Mouse Ministick Y = -31744
21:58:40 - Throt : Rotary 1 = -31488
21:58:40 - Throt : Rotary 1 = -32768
21:58:50 - Throt : TGL 1 Down = 1
21:58:50 - Throt : TGL 2 Down = 1
21:58:50 - Throt : TGL 1 Down = 0
21:58:50 - Throt : TGL 2 Down = 0
21:59:21 - Throt : Rotary 1 = -31488
21:59:21 - Throt : Rotary 1 = -32768
22:00:14 - Throt : Mouse Ministick Y = -31488
22:00:34 - Throt : H = 1
22:00:34 - Throt : SW 2 = 1
22:00:34 - Throt : H = 0
22:00:34 - Throt : SW 2 = 0
22:02:36 - Throt : Rotary 2 = -31488
22:03:19 - Throt : TGL 1 Down = 1
22:03:19 - Throt : TGL 2 Down = 1
22:03:19 - Throt : TGL 1 Down = 0
22:03:19 - Throt : TGL 2 Down = 0
22:04:12 - Throt : TGL 2 Down = 1
22:04:12 - Throt : TGL 2 Down = 0
22:04:25 - Throt : H = 1
22:04:25 - Throt : SW 2 = 1
22:04:25 - Throt : H = 0
22:04:25 - Throt : SW 2 = 0
22:05:56 - Throt : H3 Forward = 1
22:05:56 - Throt : H3 Back = 1
22:05:56 - Throt : H3 Forward = 0
22:05:56 - Throt : H3 Back = 0
22:06:24 - Throt : Rotary 1 = -31488
22:06:24 - Throt : Rotary 1 = -32768
22:08:45 - Throt : TGL 1 Down = 1
22:08:45 - Throt : TGL 2 Down = 1
22:08:45 - Throt : TGL 1 Down = 0
22:08:45 - Throt : TGL 2 Down = 0
22:10:29 - Throt : Rotary 1 = -31488
22:10:29 - Throt : Rotary 1 = -32768
22:10:36 - Throt : H = 1
22:10:36 - Throt : SW 2 = 1
22:10:36 - Throt : H = 0
22:10:36 - Throt : SW 2 = 0
22:10:51 - Throt : Mouse Ministick X = -31488
22:11:56 - Throt : H3 Back = 1
22:11:56 - Throt : H3 Back = 0
22:12:43 - Throt : Left Throttle = -16064
22:12:56 - Throt : Scroll BCK = 1
22:12:56 - Throt : Scroll BCK = 0
22:13:40 - Throt : Rotary 3 = -31488
22:13:40 - Throt : Rotary 3 = 4942
22:13:56 - Throt : Rotary 4 = -31488
22:13:56 - Throt : Rotary 4 = -12288
22:14:10 - Throt : H3 Forward = 1
22:14:10 - Throt : H3 Back = 1
22:14:10 - Throt : H3 Forward = 0
22:14:10 - Throt : H3 Back = 0
22:15:21 - Throt : H3 Forward = 1
22:15:21 - Throt : H3 Back = 1
22:15:21 - Throt : H3 Forward = 0
22:15:21 - Throt : H3 Back = 0
22:15:48 - Throt : Mouse Ministick X = -31744
22:17:24 - Throt : Left Throttle = -16064
22:18:05 - Throt : Mouse Ministick Y = -31488
22:18:08 - Throt : Left Throttle = -16128
22:18:31 - Throt : Rotary 3 = -31744
22:18:31 - Throt : Rotary 3 = 4942
22:19:37 - Throt : H = 1
22:19:37 - Throt : SW 2 = 1
22:19:37 - Throt : H = 0
22:19:37 - Throt : SW 2 = 0
22:19:43 - Throt : Mouse Ministick X = -31488
22:21:30 - Throt : Rotary 1 = -31488
22:21:30 - Throt : Rotary 1 = -32768
22:22:47 - Throt : TGL 1 Down = 1
22:22:47 - Throt : TGL 2 Down = 1
22:22:47 - Throt : TGL 1 Down = 0
22:22:47 - Throt : TGL 2 Down = 0
22:24:17 - Throt : Rotary 3 = -31488
22:24:17 - Throt : Rotary 3 = 4942
22:24:42 - Throt : Rotary 4 = -31488
22:24:42 - Throt : Rotary 4 = -12288
22:25:52 - Throt : Mouse Ministick Y = -31488
22:26:00 - Throt : Mouse Ministick X = -31488
22:26:37 - Throt : H3 Back = 1
22:26:37 - Throt : H3 Back = 0
22:28:37 - Throt : Rotary 1 = -31744
22:28:37 - Throt : Rotary 1 = -32768
22:29:46 - Throt : H = 1
22:29:46 - Throt : SW 2 = 1
22:29:46 - Throt : H = 0
22:29:46 - Throt : SW 2 = 0
22:30:22 - Throt : Scroll BCK = 1
22:30:22 - Throt : Scroll BCK = 0
22:30:54 - Throt : Right Throttle = -11968
22:31:25 - Throt : Rotary 3 = -31744
22:31:25 - Throt : Rotary 3 = 4942
22:33:51 - Throt : Left Throttle = -16128
22:34:07 - Throt : KI Down = 1
22:34:07 - Throt : Scroll BCK = 1
22:34:07 - Throt : KI Down = 0
22:34:07 - Throt : Scroll BCK = 0
22:34:15 - Throt : Rotary 3 = -31744
22:34:15 - Throt : Rotary 3 = 4942
22:34:54 - Throt : Right Throttle = -16128
22:35:02 - Throt : Mouse Ministick X = -31488
22:35:12 - Throt : H = 1
22:35:12 - Throt : SW 2 = 1
22:35:12 - Throt : H = 0
22:35:12 - Throt : SW 2 = 0
22:36:28 - Throt : TGL 1 Down = 1
22:36:28 - Throt : TGL 2 Down = 1
22:36:28 - Throt : TGL 1 Down = 0
22:36:28 - Throt : TGL 2 Down = 0
22:37:49 - Throt : Rotary 1 = -31488
22:37:49 - Throt : Rotary 1 = -32768
22:38:49 - Throt : Rotary 1 = -31744
22:38:49 - Throt : Rotary 1 = -32768
22:39:17 - Throt : H = 1
22:39:17 - Throt : SW 2 = 1
22:39:17 - Throt : H = 0
22:39:17 - Throt : SW 2 = 0
22:39:46 - Throt : H = 1
22:39:46 - Throt : SW 2 = 1
22:39:46 - Throt : H = 0
22:39:46 - Throt : SW 2 = 0
22:41:03 - Throt : Rotary 3 = -31488
22:41:03 - Throt : Rotary 3 = 4942
22:42:07 - Throt : H = 1
22:42:07 - Throt : SW 2 = 1
22:42:07 - Throt : H = 0
22:42:07 - Throt : SW 2 = 0
22:42:22 - Throt : KI Down = 1
22:42:22 - Throt : Scroll BCK = 1
22:42:22 - Throt : KI Down = 0
22:42:22 - Throt : Scroll BCK = 0
22:44:19 - Throt : H = 1
22:44:19 - Throt : SW 2 = 1
22:44:19 - Throt : H = 0
22:44:19 - Throt : SW 2 = 0
22:44:45 - Throt : Scroll BCK = 1
22:44:45 - Throt : Scroll BCK = 0
22:44:48 - Throt : TGL 1 Down = 1
22:44:48 - Throt : TGL 2 Down = 1
22:44:48 - Throt : TGL 1 Down = 0
22:44:48 - Throt : TGL 2 Down = 0
22:48:56 - Throt : H = 1
22:48:56 - Throt : SW 2 = 1
22:48:56 - Throt : H = 0
22:48:56 - Throt : SW 2 = 0
23:00:26 - Throt : Right Throttle = -11968
23:01:08 - Throt : Rotary 4 = -12032
23:01:08 - Throt : Rotary 4 = -12288
23:06:38 - Throt : Rotary 4 = -12032
23:06:38 - Throt : Rotary 4 = -12288
23:08:39 - Throt : Rotary 3 = -31488
23:08:39 - Throt : Rotary 3 = 4942
23:09:49 - Throt : Rotary 3 = -31488
23:09:49 - Throt : Rotary 3 = 4942
23:10:12 - Throt : Rotary 1 = -31744
23:10:12 - Throt : Rotary 1 = -32768
23:10:13 - Throt : Right Throttle = -11968
23:10:39 - Throt : KI Down = 1
23:10:39 - Throt : Scroll BCK = 1
23:10:39 - Throt : KI Down = 0
23:10:39 - Throt : Scroll BCK = 0
23:12:25 - Throt : Right Throttle = -11968
23:13:04 - Throt : Rotary 2 = -31488
23:13:44 - Throt : Mouse Ministick X = -31488
23:14:37 - Throt : H = 1
23:14:37 - Throt : SW 2 = 1
23:14:37 - Throt : H = 0
23:14:37 - Throt : SW 2 = 0
23:16:04 - Throt : Mouse Ministick Y = -31488
23:17:29 - Throt : TGL 1 Down = 1
23:17:29 - Throt : TGL 2 Down = 1
23:17:29 - Throt : TGL 1 Down = 0
23:17:29 - Throt : TGL 2 Down = 0
23:17:35 - Throt : Rotary 3 = -31488
23:17:35 - Throt : Rotary 3 = 4942
23:19:38 - Throt : H = 1
23:19:38 - Throt : SW 2 = 1
23:19:38 - Throt : H = 0
23:19:38 - Throt : SW 2 = 0
23:21:39 - Throt : TGL 1 Down = 1
23:21:39 - Throt : TGL 2 Down = 1
23:21:39 - Throt : TGL 1 Down = 0
23:21:39 - Throt : TGL 2 Down = 0
23:21:43 - Throt : Rotary 4 = -31488
23:21:43 - Throt : Rotary 4 = -12288
23:23:48 - Throt : Left Throttle = -16128
23:25:45 - Throt : Rotary 1 = -31488
23:25:45 - Throt : Rotary 1 = -32768
23:25:51 - Throt : Mouse Ministick Y = -31488
23:28:47 - Throt : Right Throttle = -11968
23:31:19 - Throt : Rotary 2 = -31488
23:32:01 - Throt : Mouse Ministick X = -31488
23:32:18 - Throt : Right Throttle = -11968
23:34:08 - Throt : Right Throttle = -11968
23:38:09 - Throt : Mouse Ministick Y = -31488
23:38:22 - Throt : Left Throttle = -32448
23:43:43 - Throt : Rotary 3 = -31488
23:43:43 - Throt : Rotary 3 = 4942
23:44:16 - Throt : Left Throttle = -16064
23:45:03 - Throt : TGL 2 Down = 1
23:45:03 - Throt : TGL 2 Down = 0
23:46:52 - Throt : Mouse Ministick Y = -31488
23:50:27 - Throt : KI Down = 1
23:50:27 - Throt : Scroll BCK = 1
23:50:27 - Throt : KI Down = 0
23:50:27 - Throt : Scroll BCK = 0
23:51:13 - Throt : H = 1
23:51:13 - Throt : SW 2 = 1
23:51:13 - Throt : H = 0
23:51:13 - Throt : SW 2 = 0
23:52:33 - Throt : Rotary 2 = -31488
23:54:31 - Throt : Right Throttle = -11968
23:57:22 - Throt : Right Throttle = -11968
00:00:53 - Throt : Mouse Ministick Y = -31488
00:01:45 - Throt : Right Throttle = -11968
00:02:24 - Throt : Mouse Ministick Y = -31488
00:04:54 - Throt : Rotary 2 = -31488
00:05:10 - Throt : Rotary 2 = -31488
00:05:14 - Throt : H3 Forward = 1
00:05:14 - Throt : H3 Back = 1
00:05:14 - Throt : H3 Forward = 0
00:05:14 - Throt : H3 Back = 0
00:09:05 - Throt : Mouse Ministick X = -31488
00:11:40 - Throt : Rotary 2 = -31488
00:12:14 - Throt : Rotary 4 = -31488
00:12:14 - Throt : Rotary 4 = -12288
00:13:45 - Throt : Rotary 2 = -31488
00:15:28 - Throt : Rotary 2 = -31488
00:15:32 - Throt : Rotary 3 = -31488
00:15:32 - Throt : Rotary 3 = 4942
00:16:35 - Throt : Mouse Ministick X = -31488
00:16:45 - Throt : Rotary 2 = -31488
00:18:19 - Throt : H = 1
00:18:19 - Throt : SW 2 = 1
00:18:19 - Throt : H = 0
00:18:19 - Throt : SW 2 = 0
00:20:06 - Throt : Left Throttle = 16384
00:20:08 - Throt : Left Throttle = -16384
00:20:18 - Throt : Left Throttle = 16320
00:20:18 - Throt : Mouse Ministick X = -32768
00:20:24 - Throt : Left Throttle = 16320
00:20:45 - Throt : Left Throttle = 16320
450 events in 4.0 hours: 112.5 events/hour
```

### Cables separated

Note: there were so many events that I could not scroll back far enough in the command line window to copy all of them.  All known events were Throttle events.

```
1210 events in 4.0 hours: 302.5 events/hour
```

### Ferrite Cables bundled

```
12:00:35 - Test Joystick and throttle, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Ferrite Cables twisted

```
19:46:05 - Test Joystick and throttle, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Ferrite Through desk

```
08:53:18 - Test Joystick and throttle, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Ferrite Cables separated

```
17:26:45 - Test Joystick and throttle, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

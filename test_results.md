# Test Results

The test application knows:

1. What devices are connected on startup.
2. How long the test will last (hard coded).
3. Any inputs that occur during the test.  For axis input, a hard-coded deadzone is assumed.

The result of the test is the number of ghost events/test time.

For these tests, the test length is hour hours with a axis deadzone of 4096.

## Throttle Only

### Connected to PC

Input #?

```
23:38:52 - Test Throttle only, 4.0 hours
00:44:06 - Throt : TGL 3 Down = 1
00:44:06 - Throt : TGL 3 Down = 0
01:51:03 - Throt : TGL 3 Down = 1
01:51:03 - Throt : TGL 3 Down = 0
4 events in 4.0 hours: 1.0 events/hour
```

Input #?+1

```
07:25:32 - Test Throttle only, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

### Connected to external hub

For all of these tests, the throttle is the only device connected to the hub.

#### Belkin F4U073 Port 1

```
13:08:04 - Test Throttle only, 4.0 hours
0 events in 4.0 hours: 0.0 events/hour
```

#### Belkin F4U073 Port 2

```
17:57:23 - Test Throttle only, 4.0 hours
18:19:41 - Throt : M1 = 0
1 events in 4.0 hours: 0.2 events/hour
```

#### Belkin F4U073 Port 3

```
10:59:15 - Test Throttle only, 4.0 hours
11:58:37 - Throt : Scroll FWD = 1
11:58:37 - Throt : Scroll BCK = 1
11:58:37 - Throt : Mouse Ministick Click = 1
11:58:37 - Throt : M1 = 0
11:58:37 - Throt : Scroll FWD = 0
11:58:37 - Throt : Scroll BCK = 0
11:58:37 - Throt : Mouse Ministick Click = 0
11:58:37 - Throt : M1 = 1
12:04:07 - Throt : Rotary 4 = -29184
13:05:19 - Throt : Rotary 4 = -29184
10 events in 4.0 hours: 2.5 events/hour
```

#### Belkin F4U073 Port 4

```
18:13:50 - Test Throttle only, 4.0 hours
19:13:51 - Throt : Rotary 4 = -29184
1 events in 4.0 hours: 0.2 events/hour
```
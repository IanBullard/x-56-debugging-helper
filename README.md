# x-56-debugging-helper
An SDL2-based input watcher to help track down ghost-inputs on the X-56 H.O.T.A.S.

## TL;DR
I own a [Logitech X56 H.O.T.A.S.](https://www.logitechg.com/en-us/products/space/x56-space-flight-vr-simulator-controller.html) that I've used to mostly play [Elite Dangerous](https://www.elitedangerous.com/) and I'd like to move onto other games.  Since moving my desk to another room, the X56 has started generating ghost inputs, meaning that without touching anything on the device it'll send button/toggle/axis events to the computer.  After losing a ship to a ghost input turing on silent running while in combat, I decided to track down the problem.

Now the true TL;DR: there was electrical noise in the USB cable and adding ferrite cores solved the issue. Specifically, [13mm external diameter/5mm internal diameter cores from this pack available on Amazon](https://www.amazon.com/gp/product/B00V4MMIBW) (not an affiliate link).  I placed two of them on each USB cable (throttle and stick) about two inches away from each end.

## What the application does
This console application finds connected X-56 stick/throttles then sits and waits for any inputs from those devices.  Any inputs that occur while the program is running is reported and counted.  After four hours, it displays the number of inputs that occured for the stick/throttle.

Note: I've changed how input events are reported since my [results](test_results.md). The app originally only tracked the number of inputs from both devices. I've changed the code to report inputs from the throttle and stick separately as well as combined.  I did this because while copy/pasting test results I realized that the actual ghost inputs doesn't mean much, but which device is reporting ghost inputs is important.  If I were to do this all again, I'd only keep track of the summary of ghost inputs per device and not all inputs.

## My Test results

The idea was to plug in my stick/throttle in different configurations and then not touch them to record the number of ghost inputs. I wanted to be able to monitor the inputs for hours at a time because the ghost inputs can be 20-60 minutes apart.  A user can set up a test with the X-56 throttle and/or stick and then walk away for four hours to get data on any ghost inputs.

At first, I thought the ghost input problem may be related to what USB port the device was plugged into.  In the end, I was able to collect enough data to prove that wrong and fix the actual problem suing this application.  I'm releasing the source code and my test data in hopes that it can solve other people's problems.

All of my test results are on [another page](test_results.md).

### Suggested fixes
I've seen the following suggested as fixes for the ghost input.  If you do not get the same results as I have, I suggest testing these (listed in order from least effort to most effort):

1. Change the LED brightness.
2. Ferrite cores on the USB cable, one near the device and one near the plug 2" away from each end.
3. [Extra power cable cable](https://www.amazon.com/gp/product/B06ZY98462) (not an affiliate link) to boost the power over the cable
4. Open the device and make sure there's no pinched cables
5. Place ferrite cores on the cables inside the device.

# License
All files in the repository are under the [MIT license](LICENSE).

# Notes
This app isn't for general consumption, it's only a helper to investigate a problem and possible solutions.  I don't recommend using any of this code in a shipping product, it's written to get to provide a solution as quickly as possible and not for safety, security, or any other -ty's.  It's not my best work, but it's also not my worst.

# Building
I'm using xmake as a build system because it's the fastest way I know how to get an SDL2 console app up and running.  To build:

`xmake`

To run:

`./build/windows/x64/release/test-hotas.exe`

While it's possible that this project will compile on Linux/Mac, I have not done any testing on any platform besides Windows 11.
#include <SDL2/SDL.h>
#include <SDL2/SDL_joystick.h>
#include <fmt/core.h>
#include <fmt/chrono.h>

#include <chrono>
#include <ctime>
#include <cstdio>
#include <signal.h>
#include <string>
#include <unordered_map>
#include <vector>

const double MAX_RUNTIME_HOURS = 4.0;
const int INPUT_TIMEOUT_MS = 60000;

const std::string joystick_name = "Saitek Pro Flight X-56 Rhino Stick";
const std::string joystick_short_name = "Stick";
const std::string throttle_name = "Saitek Pro Flight X-56 Rhino Throttle";
const std::string throttle_short_name = "Throt";

// axis
const std::vector<std::string> joystick_axis_names{
    "X Axis",
    "Y Axis",
    "C Stick X",
    "C Stick Y",
    "Twist" // 4
};

const std::vector<std::string> throttle_axis_names{
    "Left Throttle",
    "Right Throttle",
    "Rotary 1",
    "Mouse Ministick X",
    "Mouse Ministick Y",
    "Rotary 2",
    "Rotary 3",
    "Rotary 4", // 7
};

// button
const std::vector<std::string> joystick_button_names{
    "Trigger",
    "A",
    "B",
    "C Stick Click",
    "D",
    "Pinky",
    "H1 Up",
    "H1 Right",
    "H1 Down",
    "H1 Left",
    "H2 Up",
    "H2 Right",
    "H2 Down",
    "H2 Left",
    "M1",
    "M2",
    "M3" // 16
};

const std::vector<std::string> throttle_button_names{
    "E",
    "F Push",
    "G Push",
    "I",
    "H",
    "SW 1",
    "SW 2",
    "SW 3",
    "SW 4",
    "SW 5",
    "SW 6",
    "TGL 1 Up",
    "TGL 1 Down",
    "TGL 2 Up",
    "TGL 2 Down",
    "TGL 3 Up",
    "TGL 3 Down",
    "TGL 4 Up",
    "TGL 4 Down",
    "H3 Up",
    "H3 Forward",
    "H3 Down",
    "H3 Back",
    "H4 Up",
    "H4 Forward",
    "H4 Down",
    "H4 Back",
    "K1 Up",
    "KI Down",
    "Scroll FWD",
    "Scroll BCK",
    "Mouse Ministick Click",
    "SLD",
    "M1",
    "M2",
    "S1" // 35
};

// Hat
const std::vector<std::string> joystick_hat_names{
    "POV"
 };

const std::vector<std::string> throttle_hat_names;

struct JoystickInfo {
    std::string name;
    std::vector<std::string> axis_names;
    std::vector<std::string> button_names;
    std::vector<std::string> hat_names;

    const std::string get_axis_name(int index) {
        if(index < axis_names.size())
            return axis_names[index];

        return fmt::format("Unknown axis {}.", index);
    }

    const std::string get_button_name(int index) {
        if(index < button_names.size())
            return button_names[index];

        return fmt::format("Unknown button {}.", index);
    }

    const std::string get_hat_name(int index) {
        if(index < hat_names.size())
            return hat_names[index];

        return fmt::format("Unknown hat {}.", index);
    }
};

void report_event(const std::string& device, uint32_t timestamp, int axis, int value)
{
    //fmt::print(log_format, timestamp, device);
    printf("%s, %x, %d, %d\n", device.c_str(), timestamp, axis, value);
}

const int32_t deadzone = 4096;

bool in_deadzone(int32_t value) {
    return abs(value) < deadzone;
}

void clear_startup_events()
{
    // Some devices can spam an event or two after SDL_JoystickOpen so we wait one second to collect those events 
    uint64_t startTime = SDL_GetPerformanceCounter();
    SDL_Event event;
    double elapsedTime = 0.0;

    while(elapsedTime < 1.0) {
        SDL_WaitEventTimeout(&event, 1000);
        uint64_t currTime = SDL_GetPerformanceCounter();
        elapsedTime = static_cast<double>((currTime - startTime) / static_cast<double>(SDL_GetPerformanceFrequency()));
    }
}

static bool should_exit = false;

void signal_callback_handler(int signum) {
    float quit_time = (float)INPUT_TIMEOUT_MS / 1000.0f;
    fmt::print("SIGINT received, it may take up {:0.1f} seconds to quit.\n", quit_time);
    should_exit = true;
}

int main(int argc, char** argv)
{
    signal(SIGINT, signal_callback_handler);

    if (SDL_Init(SDL_INIT_JOYSTICK) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }

    std::unordered_map<SDL_JoystickID, JoystickInfo> id_to_info;
    SDL_Joystick *joystick = nullptr;
    SDL_Joystick *throttle = nullptr;
    SDL_JoystickID joystick_id = -1;
    SDL_JoystickID throttle_id = -1;

    // Find the X-56 throttle and joystick.
    auto num_joysticks = SDL_NumJoysticks();

    for(auto i = 0; i < num_joysticks; ++i)
    {
        std::string name = std::string(SDL_JoystickNameForIndex(i));
        if(name == joystick_name) {
            joystick = SDL_JoystickOpen(i);
            joystick_id = SDL_JoystickInstanceID(joystick);
            id_to_info[joystick_id] = JoystickInfo();
            id_to_info[joystick_id].name = joystick_short_name;
            id_to_info[joystick_id].axis_names = joystick_axis_names;
            id_to_info[joystick_id].button_names = joystick_button_names;
            id_to_info[joystick_id].hat_names = joystick_hat_names;
        }
        else if(name == throttle_name) {
            throttle = SDL_JoystickOpen(i);
            throttle_id = SDL_JoystickInstanceID(throttle);
            id_to_info[throttle_id] = JoystickInfo();
            id_to_info[throttle_id].name = throttle_short_name;
            id_to_info[throttle_id].axis_names = throttle_axis_names;
            id_to_info[throttle_id].button_names = throttle_button_names;
            id_to_info[throttle_id].hat_names = throttle_hat_names;
        }
    }

    // Clear any events from initialization.
    clear_startup_events();

    auto start = std::chrono::system_clock::now();
    int event_count = 0;

    SDL_Event event;

    {
        std::string test_name;
        if(joystick != nullptr && throttle != nullptr)
        {
            test_name = "Joystick and throttle";
        }
        else if (joystick != nullptr)
        {
            test_name = "Joystick only";
        }
        else if (throttle != nullptr)
        {
            test_name = "Throttle only";
        }
        else
        {
            fmt::print("ERROR: No Logitech X-56 devices connected!\n");
            exit(-1);
        }
        
        auto time = fmt::localtime(std::time(nullptr));
        fmt::print("{:%H:%M:%S} - Test {}, {:.1f} hours\n", time, test_name, MAX_RUNTIME_HOURS);
    }

    while(!should_exit) {
        SDL_WaitEventTimeout(&event, INPUT_TIMEOUT_MS);
        auto time = fmt::localtime(std::time(nullptr));
        std::string device;
        std::string input;
        std::string value;
        bool report = false;


        switch (event.type)
        {
        case SDL_JOYAXISMOTION:
            device = id_to_info[event.jaxis.which].name;
            input = id_to_info[event.jaxis.which].get_axis_name(event.jaxis.axis);
            value = fmt::format("{}", event.jaxis.value);
            if(!in_deadzone(event.jaxis.value))
                report = true;
            break;
        case SDL_JOYBALLMOTION:
            device = id_to_info[event.jball.which].name;
            input = fmt::format("Unknown ball {}", event.jball.ball);
            value = fmt::format("{}", event.jball.xrel + event.jball.yrel);
            report = true;
            break;
        case SDL_JOYHATMOTION:
            device = id_to_info[event.jhat.which].name;
            input = id_to_info[event.jhat.which].get_hat_name(event.jhat.hat);
            value = fmt::format("{}", event.jhat.value);
            report = true;
            break;
        case SDL_JOYBUTTONDOWN:
        case SDL_JOYBUTTONUP:
            device = id_to_info[event.jbutton.which].name;
            input = id_to_info[event.jbutton.which].get_button_name(event.jbutton.button);
            value = fmt::format("{}", event.jbutton.state);
            report = true;
            break;
        default:
            break;
        }

        if(report) {
            event_count++;
            fmt::print("{:%H:%M:%S} - {} : {} = {}\n", time, device, input, value);
        }
        
        auto current_time = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = current_time-start;
        double hours = elapsed_seconds.count() / 60.0 / 60.0;
        if(hours >= MAX_RUNTIME_HOURS)
            should_exit = true;
    }

    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    double hours = elapsed_seconds.count() / 60.0 / 60.0;
    double events_per_hour = std::round(((double)event_count/hours)*10.0) / 10.0;

    fmt::print("{} events in {:.1f} hours: {:.1f} events/hour\n", event_count, hours, events_per_hour);

    if(joystick)
        SDL_JoystickClose(joystick);
    if(throttle)
        SDL_JoystickClose(throttle);

    return 0;
}
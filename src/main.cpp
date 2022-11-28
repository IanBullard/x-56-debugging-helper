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

const std::string joystick_name = "Saitek Pro Flight X-56 Rhino Stick";
const std::string joystick_short_name = "Stick";
const std::string throttle_name = "Saitek Pro Flight X-56 Rhino Throttle";
const std::string throttle_short_name = "Throt";

// axis
const std::vector<std::string> joystick_axis_names{
    "RollX",
    "RollY",
    "ThumX",
    "ThumY",
    "Yaw"
};

const std::vector<std::string> throttle_axis_names{
    "ThroL",
    "ThroR",
    "TopSc",
    "ThumX",
    "ThumY",
    "BotSc",
    "Rtry3",
    "Rtry4",
};

// button
const std::vector<std::string> joystick_button_names{
    "Trigg",
    "ButtA",
    "ButtB",
    "ButtC",
    "PinkB",
    "PinkS",
};

const std::vector<std::string> throttle_button_names{
    "ButtE", // 00
    "ButtF", // 01
    "ButtG", // 02
    "ButtI", // 03
    "ButtH", // 04
    "Swch1", // 05
    "Swch2", // 06
    "Swch3", // 07
    "Swch4", // 08
    "Swch5", // 09
    "Swch6", // 10
    "Tgl1U", // 11
    "Tgl1D", // 12
    "Tg21U", // 13
    "Tg21D", // 14
    "Tg31U", // 15
    "Tg41D", // 16
    "Tg51U", // 17
    "Tg61D", // 18
    "H3Up ", // 19
    "H3For", // 20
    "H3Dwn", // 21
    "H3Bck", // 22
    "H4Up ", // 23
    "H4For", // 24
    "H4Dwn", // 25
    "H4Bck", // 26
    "KIUp ", // 27
    "KIDwn", // 28
    "ScrFd", // 29
    "ScrBk", // 30
    "ThbBt", // 31
    "ThSld", // 32
};

struct JoystickInfo {
    std::string name;
    std::vector<std::string> axis_names;
    std::vector<std::string> button_names;

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
        return fmt::format("Unknown hat {}.", index);
    }
};

void report_event(const std::string& device, uint32_t timestamp, int axis, int value)
{
    //fmt::print(log_format, timestamp, device);
    printf("%s, %x, %d, %d\n", device.c_str(), timestamp, axis, value);
}

const int32_t deadzone = 8192;

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
            printf("Found joystick\n");
            joystick = SDL_JoystickOpen(i);
            joystick_id = SDL_JoystickInstanceID(joystick);
            id_to_info[joystick_id] = JoystickInfo();
            id_to_info[joystick_id].name = joystick_short_name;
            id_to_info[joystick_id].axis_names = joystick_axis_names;
            id_to_info[joystick_id].button_names = joystick_button_names;
        }
        else if(name == throttle_name) {
            printf("Found throttle\n");
            throttle = SDL_JoystickOpen(i);
            throttle_id = SDL_JoystickInstanceID(throttle);
            id_to_info[throttle_id] = JoystickInfo();
            id_to_info[throttle_id].name = throttle_short_name;
            id_to_info[throttle_id].axis_names = throttle_axis_names;
            id_to_info[throttle_id].button_names = throttle_button_names;
        }
    }

    // Clear any events from initialization.
    clear_startup_events();

    auto start = std::chrono::system_clock::now();
    int event_count = 0;

    SDL_Event event;

    while(!should_exit) {
        SDL_WaitEventTimeout(&event, 100);
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
    }

    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end-start;
    double hours = elapsed_seconds.count() / 60.0 / 60.0;

    fmt::print("{} events in {:.2} hours: {:.2} events/hour\n", event_count, hours, (double)event_count/hours);

    if(joystick)
        SDL_JoystickClose(joystick);
    if(throttle)
        SDL_JoystickClose(throttle);

    return 0;
}
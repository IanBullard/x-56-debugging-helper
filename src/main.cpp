#include <SDL2/SDL.h>
#include <SDL2/SDL_joystick.h>
#include <fmt/core.h>

#include <cstdio>
#include <string>
#include <unordered_map>

const std::string joystick_name = "Saitek Pro Flight X-56 Rhino Stick";
const std::string joystick_short_name = "Stick";
const std::string throttle_name = "Saitek Pro Flight X-56 Rhino Throttle";
const std::string throttle_short_name = "Throt";

std::unordered_map<SDL_JoystickID, std::string> id_to_string_map;

// axis
const std::string joystick_axis_names[] = {
    ""
};

const std::string throttle_axis_names[] = {
    ""
};

// button
const std::string joystick_button_names[] = {
    ""
};

const std::string throttle_button_names[] = {
    ""
};

// hat
const std::string joystick_hat_names[] = {
    ""
};

const std::string throttle_hat_names[] = {
    ""
};

const std::string log_format = "{0:08x} {1:4} {2:16}\n";

void report_event(const std::string& device, uint32_t timestamp, int axis, int value)
{
    //fmt::print(log_format, timestamp, device);
    printf("%s, %x, %d, %d\n", device.c_str(), timestamp, axis, value);
}

const int32_t deadzone = 3072;

bool in_deadzone(int32_t value) {
    return abs(value) < deadzone;
}

void clear_startup_events()
{
    uint64_t startTime = SDL_GetPerformanceCounter();
    SDL_Event event;
    double elapsedTime = 0.0;

    while(elapsedTime < 1.0) {
        SDL_WaitEventTimeout(&event, 1000);
        uint64_t currTime = SDL_GetPerformanceCounter();
        elapsedTime = static_cast<double>((currTime - startTime) / static_cast<double>(SDL_GetPerformanceFrequency()));
    }
}


int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_JOYSTICK) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }

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
            id_to_string_map[joystick_id] = joystick_short_name;
        }
        else if(name == throttle_name) {
            printf("Found throttle\n");
            throttle = SDL_JoystickOpen(i);
            throttle_id = SDL_JoystickInstanceID(throttle);
            id_to_string_map[throttle_id] = throttle_short_name;
        }
    }

    // Clear any events from initialization.
    clear_startup_events();

    SDL_Event event;

    bool quit = false;
    while(!quit) {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
        case SDL_JOYAXISMOTION:
            if(!in_deadzone(event.jaxis.value))
                report_event(id_to_string_map[event.jaxis.which], event.jaxis.timestamp, event.jaxis.axis, event.jaxis.value);
            break;
        case SDL_JOYBALLMOTION:
            report_event(id_to_string_map[event.jball.which], event.jball.timestamp, event.jball.ball, event.jball.xrel + event.jball.yrel);
            break;
        case SDL_JOYHATMOTION:
            report_event(id_to_string_map[event.jhat.which], event.jhat.timestamp, event.jhat.hat, event.jhat.value);
            break;
        case SDL_JOYBUTTONDOWN:
        case SDL_JOYBUTTONUP:
            report_event(id_to_string_map[event.jbutton.which], event.jbutton.timestamp, event.jbutton.button, event.jbutton.state);
            break;
        default:
            break;
        }
    }

    if(joystick)
        SDL_JoystickClose(joystick);
    if(throttle)
        SDL_JoystickClose(throttle);

    return 0;
}
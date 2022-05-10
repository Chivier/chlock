#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/time.h>
#include <tuple>
#include <vector>

namespace chlock_space {

void PrintTime(std::string format = "%Y-%m-%d %H:%M:%S") {
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string s(30, '\0');
    std::strftime(&s[0], s.size(), format.c_str(), std::localtime(&now));
    std::cout << s << std::endl;
}

static bool gLastTimeFlag = false;
static std::chrono::time_point<std::chrono::system_clock> gLastTime;

void GetInterval(const std::string info = "", const int mode = 1) {
    if (!gLastTimeFlag) {
        std::cout << "Set new time tag here!" << std::endl;
        gLastTimeFlag = true;
        gLastTime = std::chrono::system_clock::now();
        return;
    }

    if (info == "") {
        std::cout << "Since last time tag: ";
    } else {
        std::cout << info;
    }

    auto now = std::chrono::system_clock::now();
    auto duration = now - gLastTime;

    if (mode == 0) {
        // millisecond mode
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
        duration -= milliseconds;
        auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(duration);
        std::cout << std::setw(5) << milliseconds.count() << " ms" << std::setw(5) << microseconds.count() << std::endl;
    } else if (mode == 1) {
        // second mode
        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
        duration -= seconds;
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
        std::cout << std::setw(8) << std::fixed << std::setprecision(3);
        std::cout << seconds.count() + milliseconds.count() * 1.0 / 1000;
        std::cout << " s" << std::endl;
    } else if (mode == 2) {
        // minute mode
        auto minutes = std::chrono::duration_cast<std::chrono::minutes>(duration);
        duration -= minutes;
        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration);
        duration -= seconds;
        std::ios old_state(nullptr);
        old_state.copyfmt(std::cout);
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
        std::cout << std::setw(4) << minutes.count() << ":" << std::setfill('0') << std::setw(2) << seconds.count();
        std::cout.copyfmt(old_state);
        std::cout << std::setw(5) << milliseconds.count() << " ms" << std::endl;
    }

    gLastTime = std::chrono::system_clock::now();
}

void ClearInterval() {
    std::cout << "interval flag is removed" << std::endl;
    gLastTimeFlag = false;
}
} // namespace chlock_space
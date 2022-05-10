#include "../chlock.hpp"
#include <unistd.h>

using namespace chlock_space;

int main(int argc, char **argv) {
    chlock_space::PrintTime();
    chlock_space::GetInterval();
    for (int index = 0; index < 3; ++index) {
        sleep(1);
        chlock_space::GetInterval("Tag " + std::to_string(index) + ": ", 0);
    }
    for (int index = 0; index < 3; ++index) {
        sleep(1);
        chlock_space::GetInterval("Tag " + std::to_string(index) + ": ", 1);
    }
    for (int index = 0; index < 3; ++index) {
        sleep(1);
        chlock_space::GetInterval("Tag " + std::to_string(index) + ": ", 2);
    }
    return 0;
}
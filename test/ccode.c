#include "../chlock.h"
#include <unistd.h>

int main(int argc, char **argv) {
    ChlockPrintTimeDefault();
    ChlockSetInterval();
    for (int index = 0; index < 5; ++index) {
        sleep(1);
        ChlockGetInterval(1);
    }
    ChlockFreeInterval();
    return 0;
}
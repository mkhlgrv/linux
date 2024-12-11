

#include <signal.h>
#include <iostream>
#include <unistd.h>

unsigned int runtime = 0;
unsigned int usr1_count = 0;

void ______(int signum) {
    if (signum == ______) {
        std::cout << "Runtime: " << runtime << " seconds" << std::endl;
        ______++;
    }
    else if (signum == SIGUSR2) {
        std::cout << "Received " << ______ << " SIGUSR1 signals" << std::endl;
    }
    else if (signum == ______) {
        std::cout << "Terminating..." << std::endl;
        ______;
    }
}

int main() {
    signal(______, signal_handler);
    signal(______, signal_handler);
    signal(______, signal_handler);

    while(true) {
        std::cout << "Working..." << std::endl;
        sleep(1);
        ______++;
    }

    return 0;
}

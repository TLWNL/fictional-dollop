#include <iostream>
#include "Client.h"

/**
 * You don't have to edit anything in this file, but you may inspect it to get a better understanding of how
 * the program works.
 */
int main(int nargs, char **argv) {
    std::cout << "Computer Networks Chat Client Starting..." << std::endl;
    Client client;
    std::cout << "Setting up" << std::endl;
    client.setup();           // Commented out for ease of debugging.
    std::cout << "Running application" << std::endl;
    while (!client.stop && client.tick() >= 0) {
        if(client.tick() == -1)
            client.stop = true;
//        std::cout << "Please enter your command:\n";

        client.tick();

        // Wait for 100 milliseconds before checking for new input and messages.
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    return 0;
}

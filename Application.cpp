//
// Created by Jesse on 2019-01-09.
//

#include "Application.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

void Application::run() {
    while (!this->stop) {
        std::string command;
        std::cout << "Please enter your command:\n";
        std::cin >> command;
        if (strcmp(command.c_str(), "!quit") == 0) {
            std::cout << "Stopping Application";
            stopApplication();
        }

        this->tick();
    }
}

void Application::stopApplication() {
//    std::cout << "Stopping Application\n";
    this->stop = true;
}

bool Application::isStopped() {
    return this->stop;
}

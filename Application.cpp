//
// Created by Jesse on 2019-01-09.
//

#include "Application.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

void Application::run() {
    while (!this->stop) {
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

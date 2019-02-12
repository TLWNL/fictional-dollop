//
// Created by Jesse on 2019-01-09.
//

#ifndef CPP_CHAT_CLIENT_CLIENT_H
#define CPP_CHAT_CLIENT_CLIENT_H

#include <thread>
#include <string.h>
#include <pthread.h>
#include "Application.h"
#include "vusocket.h"
#include "CircularLineBuffer.h"

class Client : public Application {
private:
    /**
     * You are free to add new member variables and methods here if needed.
     * Please do not remove the ones that are already here.
     */
    SOCKET sock;
    std::thread socketThread, stdinThread;
    CircularLineBuffer socketBuffer, stdinBuffer;

    /**
     * Assignment 2
     *
     * See the lab manual for the assignment description.
     */
    void tick() override{};

    /**
     * Assignment 4
     *
     * See the lab manual for the assignment description.
     */
    int readFromStdin(){};

    /**
     * Assignment 4
     *
     * See the lab manual for the assignment description.
     */
    int readFromSocket(){

    };

    inline void threadReadFromStdin() {
        while (!isStopped()) {
            auto res = readFromStdin();
            if (res < 0) {
                stopApplication();
            }
        }
    }

    inline void threadReadFromSocket() {
        while (!isStopped()) {
            auto res = readFromSocket();
            if (res < 0) {
                stopApplication();
            }
        }
    }

    void createSocketAndLogIn(){
        // Use the getaddrinfo to translate address to machine-readable (use hints param)
        //The chat-server IP: 52.58.97.202 5378
        struct addrinfo hints;
        struct addrinfo *res;
        const char *ip = "52.58.97.202";
        const char *port = "5378";

        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;
        hints.ai_flags = 0;



        int myInfo = getaddrinfo(ip, port, &hints, &res);
        if (myInfo != 0) {
            fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(myInfo));
            exit(EXIT_FAILURE);
        }

        int handle = socket(AF_INET, SOCK_STREAM, 0);
        if(handle != 0) {
            fprintf(stderr, "connect: %s\n", gai_strerror(handle));
        }

        int connection = connect(handle, res->ai_addr, res->ai_addrlen);

        if(connection != 0) {
            printf("%d", connection);
            fprintf(stderr, "connect: %s\n", gai_strerror(connection));
        }

    };

    void closeSocket(){};

    inline void startThreads() {
        socketThread = std::thread(&Client::threadReadFromSocket, this);
        stdinThread = std::thread(&Client::threadReadFromStdin, this);
    }

    inline void stopThreads() {
        this->stopApplication();
        socketThread.join();
        stdinThread.join();
    }

public:
    inline ~Client() override {
        closeSocket();
        stopThreads();
    }

    /**
     * Assignment 1
     *
     * See the lab manual for the assignment description.
     */
    inline void setup() override {
        createSocketAndLogIn();
        startThreads();
    }
};


#endif //CPP_CHAT_CLIENT_CLIENT_H

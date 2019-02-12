//
// Created by Jesse on 2019-01-09.
//

#ifndef CPP_CHAT_CLIENT_CLIENT_H
#define CPP_CHAT_CLIENT_CLIENT_H

#include <thread>
#include <string.h>
#include <sstream>
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
        struct addrinfo hints{}, *res;
        const char *ip = "52.58.97.202";
        const char *port = "5378";
//        size_t bytesToReceive;
        const void *recvBuffer;
        std::string loginName;
        char buf[500];

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
        if(handle < 0) {
            fprintf(stderr, "connect: %s\n", gai_strerror(handle));
        }

        int connection = connect(handle, res->ai_addr, res->ai_addrlen);

        if(connection != 0) {
            fprintf(stderr, "connect: %s\n", gai_strerror(connection));
        }

        freeaddrinfo(res);


        std::cout << "Please enter your log-in name: ";
        std::cin >> loginName;

        std::stringstream ss;
        ss << "HELLO-FROM " << loginName << "\n";
        std::string handshake = ss.str();

        char const *byteShake = handshake.c_str();

        ssize_t sendRes = send(handle, byteShake, handshake.size(), 0);

        if(sendRes != -1){
            std::cout << "Send successful!\n";
        }

        size_t bytesToReceive = 7 + loginName.length();

        ssize_t receive = recv(handle, buf, bytesToReceive, 0);

        if((int) receive == -1){
            fprintf(stderr, "receive error: -1");
        }

        std::cout << buf;

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

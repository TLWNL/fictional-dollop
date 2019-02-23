//
// Created by dylan on 2/7/19.
//
#include <iostream>
#include "Client.h"



void Client::tick() {
    std::string command;
    std::cout << "Please enter your command:\n";
    std::cin >> command;

    if (strcmp(command.c_str(), "!quit") == 0) {
        std::cout << "Stopping Application";
        stopApplication();
    }
    else if (strcmp(command.c_str(),  "!who") == 0){
        char const *who = "WHO\n";
        char who_buffer[1024];

        ssize_t who_result = send(handle, who, 5, 0);
        if((int) who_result == -1){
            fprintf(stderr, "send Error: -1\n");
        }

        ssize_t receive_result = recv(handle, who_buffer, 1024, 0);
        if((int) receive_result == -1){
            fprintf(stderr, "receive error: -1\n");
        }

        std::cout << who_buffer;
    }

    else if(command.at(0) == '@'){
        std::string message;
        char message_buffer[9];
        std::getline (std::cin, message);   // Get the message from cin
        std::string userName = command.erase(0, 1); // Erase the @ from the @<name>

        std::stringstream to_send;
        to_send << "SEND " << userName << message << "\n";
        std::string to_send_str = to_send.str();
        const char *byteSend = to_send_str.c_str();

        ssize_t message_result = send(handle, byteSend, to_send_str.length(), 0);
        if((int) message_result == -1){
            fprintf(stderr, "send Error: -1");
        }

        ssize_t message_receive = recv(handle, message_buffer, 9, 0);
        if((int) message_receive == -1){
            fprintf(stderr, "receive error: -1");
        }
        std::cout << message_buffer;
    }

    else{
        fprintf(stderr, "Command not recognised\n");
    }
}

int Client::readFromStdin(){
    return 0;
}

int Client::readFromSocket() {
    return 0;
}

void Client::createSocketAndLogIn(){
    struct addrinfo hints{}, *res;
    const char *ip = "52.58.97.202";
    const char *port = "5378";
    std::string login_name;
    char buf[500];
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = 0;

    int my_info = getaddrinfo(ip, port, &hints, &res);
    if (my_info != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(my_info));
        exit(EXIT_FAILURE);
    }

    handle = socket(AF_INET, SOCK_STREAM, 0);
    if(handle < 0) {
        fprintf(stderr, "socket: %s\n", gai_strerror(handle));
    }

    int connection = connect(handle, res->ai_addr, res->ai_addrlen);
    if(connection != 0) {
        fprintf(stderr, "connect: %s\n", gai_strerror(connection));
    }

    freeaddrinfo(res);

    std::cout << "Please enter your log-in name: ";
    std::cin >> login_name;

    std::stringstream string_stream;
    string_stream << "HELLO-FROM " << login_name << "\n";
    std::string handshake = string_stream.str();
    char const *byteShake = handshake.c_str();

    ssize_t send_result = send(handle, byteShake, handshake.size(), 0);
    if(send_result == -1){
        fprintf(stderr, "send error: -1");
    }

    size_t bytes_to_receive = 6 + login_name.length();
    ssize_t receive = recv(handle, buf, bytes_to_receive, 0);
    if((int) receive == -1){
        fprintf(stderr, "receive error: -1");
    }

    const char* in_use = "IN-USE\n";
    if(strcmp(buf, in_use) == 0){
        fprintf(stderr, "Username %s is already in use, please enter another one:", login_name.c_str());
    }

    std::cout << buf << "\n";
}

void Client::closeSocket(){
    sock_close(sock);
    sock_quit();
}


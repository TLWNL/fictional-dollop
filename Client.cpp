//
// Created by dylan on 2/7/19.
//

#include <iostream>
#include "Client.h"

int Client::tick() {
//    handleCommand();
    if(socketBuffer.hasLine()) {
        std::string sockString = readFromSocket();
    }
    if(stdinBuffer.hasLine())
        readFromStdin();
    return 0;
}


int Client::handleCommand() {
    std::string command;
    std::cout << "Please enter your command:\n";
    std::cin >> command;

    stdinBuffer.writeChars(command.c_str(), strlen(command.c_str()));

    if (strcmp(command.c_str(), "!quit") == 0) {
        std::cout << "Stopping Application";
        return -1;
    }
    else if (strcmp(command.c_str(),  "!who") == 0){
        stdinBuffer.writeChars("WHO\n", 4);
//        char who_buffer[1024];
//        memset(&who_buffer, 0, sizeof(who_buffer));
//
//        ssize_t who_result = send(this->sock, "WHO\n", 4, 0);
//        if((int) who_result == -1){
//            fprintf(stderr, "send Error: -1\n");
//        }

//        ssize_t receive_result = recv(this->sock, who_buffer, 1024, 0);
//
//        if((int) receive_result == -1){
//            fprintf(stderr, "receive error: -1\n");
//        }
//
//        std::cout << who_buffer;
    }

    else if(command.at(0) == '@'){
        std::string message;
        char message_buffer[14];
//        memset(&message_buffer, 0, sizeof(message_buffer));
//        std::getline (std::cin, message);   // Get the message from cin
//        std::string userName = command.erase(0, 1); // Erase the @ from the @<name>
//
//        message = "SEND " + userName + message +"\n";
//        const char *buffer_c_str = message.c_str();
//        stdinBuffer.writeChars(buffer_c_str, strlen(buffer_c_str));
//
//        ssize_t message_result = send(this->sock, byteSend, strlen(byteSend), 0);
//        if((int) message_result == -1){
//            fprintf(stderr, "send Error: -1");
//        }
//
//        ssize_t message_receive = recv(this->sock, message_buffer, 8, 0);
//
//        if((int) message_receive == -1){
//            fprintf(stderr, "receive error: -1");
//        }
//        std::cout << message_buffer;
    }

    else{
        fprintf(stderr, "Command not recognised\n");
    }
}
int Client::readFromStdin(){
    /*
     * 1. Read command
     * 2. Format the command into ready to send c_string
     * 3. Put the formatted c_string into buffer
     */
    // Read command
    std::string command;
    std::cin >> command;
    if(!std::cin) {
        fprintf(stderr, "Input error! \n");
        return -1;
    }

    if (strcmp(command.c_str(), "!quit") == 0) {
        std::cout << "Stopping Application";
        return -1;
    }

    else if (strcmp(command.c_str(),  "!who") == 0) {
        stdinBuffer.writeChars("WHO\n", 4);
    }
    else{
        std::cout << to_buf << " has been added to the stdin buffer";
    }

    else if(command.at(0) == '@') {
        std::string message = command.erase(0, 1); // Erase the @ from the @<name>
    }


    // Format the command into ready to send c_string
//    switch(command.at(0)){
//        case '@':
//            std::string userName = command.erase(0, 1); // Erase the @ from the @<name>
//            std::string message = "SEND " + userName + message +"\n";

    }






//
//    if(!stdinBuffer.writeChars(to_buf.c_str(), strlen(to_buf.c_str()))) {
//        fprintf(stderr, "Writing error, buffer is full! \n");
//        return -2;
//    }

    return 0;
}

int Client::readFromSocket() {
    char socketBuf[500];
    if(recv(this->sock, socketBuf, 500, 0) == -1)
        fprintf(stderr, "receive error: -1");
    else{
        if(!socketBuf.writeChars(socketBuf, strlen(socketBuf))) {
            fprintf(stderr, "Writing error, buffer is full! \n");
            return -2;
        }
        else{
            std::cout << socketBuf << " has been added to the buffer";
        }
    }

    return 0;
}

void Client::createSocketAndLogIn(){
    struct addrinfo hints{}, *res;
    const char *ip = "52.58.97.202";
    const char *port = "5378";
    std::string login_name, login_message;
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

    this->sock = socket(AF_INET, SOCK_STREAM, 0);

    int connection = connect(this->sock, res->ai_addr, res->ai_addrlen);
    if(connection != 0) {
        fprintf(stderr, "connect: %s\n", gai_strerror(connection));
    }

    freeaddrinfo(res);

    std::cout << "Please enter your log-in name: ";
    std::cin >> login_name;

    login_message = "HELLO-FROM " + login_name + "\n";
    char const *byteShake = login_message.c_str();

    ssize_t send_result = send(this->sock, byteShake, strlen(byteShake), 0);
    if(send_result == -1){
        fprintf(stderr, "send error: -1");
    }

    std::string receive_str = "HELLO " + login_name + "\n";
    char const *to_receive2 = receive_str.c_str();

    ssize_t receive = recv(this->sock, buf, strlen(to_receive2), 0);
    if((int) receive == -1){
        fprintf(stderr, "receive error: -1");
    }

    const char* in_use = "IN-USE\n";
    if(strcmp(buf, in_use) == 0){
        fprintf(stderr, "Username %s is already in use, please enter another one:", login_name.c_str());
    }

    std::cout << buf << "\n";

}

void Client::closeSocket() {
    sock_close(this->sock);
    sock_quit();
}
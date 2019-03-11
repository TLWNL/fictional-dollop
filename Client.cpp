//
// Created by dylan on 2/7/19.
//

#include <iostream>
#include "Client.h"

int Client::tick() {
    if(readFromStdin() == -1) {
        std::cout << "We outtie boiz \n";
        return -1;
    }

    if(stdinBuffer.hasLine()) {
        std::string to_send = stdinBuffer.readLine() + "\n";
        std::cout << "LINE FOUND: " << to_send;
        if(send(this->sock, to_send.c_str(), strlen(to_send.c_str()), 0) == -1)
            fprintf(stderr, "send Error\n");
        else
            std::cout << "Send complete.\n";
    }
//    if(socketBuffer.hasLine()){
//        std::cout << "line found!\n";
//        std::cout << socketBuffer.readLine();
//    }

//    if(stdinBuffer.hasLine())
//        readFromStdin();
//    std::cout << "ret\n";
//    readFromSocket();

    return 0;
}

int Client::readFromStdin(){
    std::cout << "Please enter your command:\n";
    std::string command = " ";
//    std::cin >> command;
    std::cin.ignore();
    std::getline(std::cin, command, '\n');
    std::cout << command << std::endl;

    if (strcmp(command.c_str(), "!quit") == 0) {
        std::cout << "Stopping Application";
        return -1;
    }
    else if (strcmp(command.c_str(),  "!who") == 0) {
        stdinBuffer.writeChars("WHO\n", 4);
//        std::cout << "WHO\n" << " has been added to the stdin buffer" << std::endl;
    }

    else if(command.at(0) == '@'){
        std::string message;
        std::string name = command.erase(0,1);
        std::getline(std::cin, message);
//        std::cout << "Message = " << message;

        message = "SEND " + name + " " + message +"\n";
        stdinBuffer.writeChars(message.c_str(), strlen(message.c_str()));
        std::cout << message << " has been added to the stdin buffer" << std::endl;

    }

    else{
        std::cout << "Command not recognised\n";
    }


    return 0;
}

int Client::readFromSocket() {
    char socketBuf[500];
//    std::string str = std::string(socketBuf);

    if(recv(this->sock, socketBuf, 500, 0) == -1)
        fprintf(stderr, "receive error: -1");
    else{
        std::string str = std::string(socketBuf);

        socketBuffer.writeChars(str.c_str(), strlen(str.c_str()));
        std::cout << str << " has been added to the socket buffer";

    }

    return 0;
}

void Client::createSocketAndLogIn(){
    struct addrinfo hints{}, *res;
    const char *ip = "52.58.97.202";
    const char *port = "5378";
    std::string login_name, login_message;
    char buf[500];
    memset(&buf, 0, sizeof(buf));
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
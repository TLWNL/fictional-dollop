//
// Created by dylan on 2/7/19.
//

#include "CircularLineBuffer.h"
#include <string.h>

int CircularLineBuffer::freeSpace() {
    int amount_of_space = 0;
    while(!mtx.try_lock())
        mtx.try_lock();

    for (char i : buffer) {
        if(i == 0){
            amount_of_space++;
        }
    }
    mtx.unlock();
    return amount_of_space;
}

bool CircularLineBuffer::isFull(){
    return count == bufferSize;
};

bool CircularLineBuffer::isEmpty() {
    return count == 0;
}

int CircularLineBuffer::nextFreeIndex() {
    if(isFull())
        return -1;

    for(int i = 0; i<100; i++){
       if(buffer[i] == 0)
           return i;
    }

    return -2;
}

int CircularLineBuffer::findNewline() {
    for (char i : buffer) {
        if(i == '\\'){
            if(i + 1 == 'n')
                return i;
        }
    }
    return -1;
}

bool CircularLineBuffer::hasLine() {
    return findNewline() < 0;
}

bool CircularLineBuffer::writeChars(const char *chars, size_t nchars) {
    while(!mtx.try_lock())
        mtx.try_lock();

    if (isFull())
        return false;

    if (isEmpty()){
        for(int i = 0; i< nchars; i++){
            buffer[i] = chars[i];
            count++;
        }
    }

    mtx.unlock();
    return true;
}
std::string CircularLineBuffer::readLine() {
    std::string return_string;
    int newline_index = findNewline();

    while(!mtx.try_lock())
        mtx.try_lock();

    for(int i = start; i < bufferSize; i++){
        if(buffer[i] == 0)
            return return_string;

        return_string.append(&buffer[i]);
        buffer[i] = 0;
        count--;
    }
    for(int j = 0; j < start; j++){
        if(buffer[j] == 0)
            return return_string;
        return_string.append(&buffer[j]);
        buffer[j] = 0;
        count--;
    }

    std::string error_string = "Error while reading line!\n";
    mtx.unlock();
    return error_string;
}


char* CircularLineBuffer::increaseBuffer(char *buffer) {
    while(!mtx.try_lock())
        mtx.try_lock();

    char *extendo[2 * bufferSize] = {0};
    for(int i = start; i < bufferSize; i++){
        extendo[i] = &buffer[i];
    }
    for(int j = 0; j < start; j++){
        extendo[j] = &buffer[j];
    }
    mtx.unlock();
    return *extendo;
}
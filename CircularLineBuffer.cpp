//
// Created by dylan on 2/7/19.
//
#include "CircularLineBuffer.h"
#include <string>

int CircularLineBuffer::freeSpace() {
    while(!mtx.try_lock())
        mtx.try_lock();
    mtx.unlock();

    int amountOfSpace = 0;
    for (char i : buffer) {
        if(i == 0){
            amountOfSpace++;
        }
    }
    return amountOfSpace;
}

bool CircularLineBuffer::isFull(){
    return count == 100;
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
    return nextFreeIndex();
//    return 0;
}

bool CircularLineBuffer::hasLine() {
//    if(mtx.try_lock())

    return false;
}

bool CircularLineBuffer::writeChars(const char *chars, size_t nchars) {
    while(!mtx.try_lock())
        mtx.try_lock();
    mtx.unlock();

    if (isFull())
        return false;

    if (isEmpty()){
        for(int i = 0; i< nchars; i++){
            buffer[i] = chars[i];
            count++;
        }
    }

    mtx.lock();
    return true;
}
std::string CircularLineBuffer::readLine() {
    std::string returnString;
    while(!mtx.try_lock())
        mtx.try_lock();
    mtx.unlock();
//    mutexUnlock(mtx);

    for(int i = start; i < bufferSize; i++){
        if(buffer[i] == 0)
            return returnString;

        returnString.append(&buffer[i]);
        buffer[i] = 0;
        count--;
    }
    for(int j = 0; j < start; j++){
        if(buffer[j] == 0)
            return returnString;
        returnString.append(&buffer[j]);
        buffer[j] = 0;
        count--;
    }

    std::string errorString = "Error while reading line!\n";
    return errorString;


}
void CircularLineBuffer::mutexUnlock(std::mutex mtx){
    while(!mtx.try_lock())
        mtx.try_lock();
    mtx.unlock();
}

char* CircularLineBuffer::increaseBuffer(char *buffer) {
    char* extendo[2 * bufferSize] = {0};
    for(int i = 0; i < bufferSize; i++){
        extendo[i] = &buffer[i];
    }

    return *extendo;
}



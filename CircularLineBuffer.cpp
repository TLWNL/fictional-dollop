//
// Created by dylan on 2/7/19.
//

#include "CircularLineBuffer.h"
#include <string.h>
#include <cstdlib>
#include <iostream>

int CircularLineBuffer::freeSpace() {
    return bufferSize - count;
}

bool CircularLineBuffer::isFull(){
    return count == bufferSize;
}

bool CircularLineBuffer::isEmpty() {
    return count == 0;
}

int CircularLineBuffer::nextFreeIndex() {
    if(isFull())
        return -1;

    return start + count;           // I think

//    for(int i = start; i<bufferSize; i++){
//       if(buffer[i] == 0)
//           return i;
//    }
//    for(int j = 0; j<start; j++){
//        if(buffer[j] == 0)
//            return j;
//    }
//    return -2;
}

int CircularLineBuffer::findNewline() {
    for(int i = start; i<bufferSize; i++) {
        if(buffer[i] == '\n')
            return i;
    }
    for(int j = 0; j < start; j++) {
        if(buffer[j] == '\n')
            return j;
    }
    return -1;
}

bool CircularLineBuffer::hasLine() {
    return findNewline() > 0;
}

bool CircularLineBuffer::_writeChars(const char *chars, size_t nchars) {
    bool loop = false;
    int chars_written = 0;
//
//    if(nchars > freeSpace())
//        return false;

    for(int i = nextFreeIndex(); i< start + nchars; i++){
        if(i == bufferSize) {
            loop = true;
            break;
        }
        buffer[i] = chars[chars_written];
        count++;
        chars_written++;
    }
    if(loop){
//        std::cout << "Looping \/n";
        for(int j = 0; j < nchars - chars_written +1; j++){
//            if(j == start)
//                return false;
            buffer[j] = chars[chars_written];
            chars_written++;
            count++;
        }
    }
    return true;
}

std::string CircularLineBuffer::_readLine() {
    std::string return_string;
//    int newline_index = findNewline();
    bool loop = false;

    if(findNewline() == -1)
        return return_string;               // Return empty string if there is no full line

    for(int i = start; i < bufferSize; i++){            // change i < bufferSize to i < findNewLine()
        if(buffer[i] == '\n') {
            this->start = nextFreeIndex();        // !!
            count--;
            return return_string;
        }
//        if(i  == bufferSize) {
//            loop = true;
//            break;
//        }

//        if(buffer[i] == 0)                // Ask if we must terminate as well if we read an empty space.
//            return return_string;

        return_string += buffer[i];
        count--;
    }
//    if(loop) {
        for (int j = 0; j < start; j++) {
            if (buffer[j] == '\n') {
                this->start = nextFreeIndex();
                count--;
                return return_string;
            }
            return_string += buffer[j];
            count--;

        }
//    }

    // Change the starting position to 1 element after the end-line
//    std::cout << findNewline();

//    this->start = findNewline() + 1;        // !!
//    std::cout << start << std::endl;
//    std::cout << this->findNewline() + 1 << std::endstartl;
//    std::cout << this->start << std::endl;

    return "Error while reading line!\n";
}
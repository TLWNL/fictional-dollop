//
// Created by dylan on 2/7/19.
//

#include "CircularLineBuffer.h"
#include <string.h>
#include <cstdlib>

int CircularLineBuffer::freeSpace() {
    int amount_of_space = 0;

    for (char i : buffer) {
        if(i == 0)
            amount_of_space++;
    }

    return amount_of_space;
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

    for(int i = start; i<bufferSize; i++){
       if(buffer[i] == 0)
           return i;
    }
    for(int j = 0; j<start; j++){
        if(buffer[j] == 0)
            return j;
    }
    return -2;
}

int CircularLineBuffer::findNewline() {
    for(int i = start; i<bufferSize; i++) {
        if(i == '\n')
            return std::abs(start-i);
    }
    for(int j = 0; j < start; j++) {
        if(j == '\n')
            return std::abs(start-bufferSize) + j;          // Amount of steps from start to end + steps from 0.
    }
    return -1;
}

bool CircularLineBuffer::hasLine() {
    return findNewline() > 0;
}

bool CircularLineBuffer::_writeChars(const char *chars, size_t nchars) {
    bool loop = false;
    int chars_written = 0;

    if(nchars > freeSpace())
        return false;

    for(int i = start + count; i< nchars; i++){
        if(i > bufferSize) {
            loop = true;
            break;
        }
        buffer[i] = chars[chars_written];
        count++;
        chars_written++;
    }
    if(loop){
        for(int j = 0; j < nchars - chars_written; j++){            // Ask if changing the chars_written variable fucks with the loop?
            if(j == start)
                return false;
            buffer[j] = chars[chars_written];
            chars_written++;
            count++;
        }
    }
    return true;
}

std::string CircularLineBuffer::_readLine() {
    std::string return_string;
    int newline_index = findNewline();
    bool loop = false;

    if(findNewline() == -1)
        return return_string;               // Return empty string if there is no full line

    for(int i = start; i < bufferSize; i++){
        if(buffer[i] == '\n')
            return return_string;
        if(i > bufferSize) {
            loop = true;
            break;
        }

//        if(buffer[i] == 0)                // Ask if we must terminate as well if we read an empty space.
//            return return_string;

        return_string.append(&buffer[i]);
//        buffer[i] = 0;
//        count--;
    }
    if(loop) {
        for (int j = 0; j < start; j++) {
            if (buffer[j] == '\n')
                return return_string;

            if (buffer[j] == 0)
                return return_string;
            return_string.append(&buffer[j]);
            //        buffer[j] = 0;
            //        count--;
        }
    }

    std::string error_string = "Error while reading line!\n";
    return error_string;
}
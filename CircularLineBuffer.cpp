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

    return start + count;
}

int CircularLineBuffer::findNewline() {
    for(int i = start; i < bufferSize; i++) {
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
    int start_point = nextFreeIndex();

    if(nchars > freeSpace()) {
        std::cout << "Not enough space in the buffer!\n";
        return false;
    }

    for(int i = start_point; i< start_point + nchars; i++){
        if(i >= bufferSize) {
            loop = true;
            break;
        }
        buffer[i] = chars[chars_written];
        count++;
        chars_written++;
    }
    if(loop){
        int magnie;
        int chars_left = nchars - chars_written;

        while(chars_left != 0){
            magnie = (start+count) - bufferSize;
            buffer[magnie] = chars[chars_written];
            chars_written++;
            chars_left--;
            count++;
        }

    }
    return true;
}

std::string CircularLineBuffer::_readLine() {
    std::string return_string;

    if(findNewline() == -1)
        return return_string;               // Return empty string if there is no full line


    if(findNewline() < start){
        for(int e = start; e < bufferSize; e++){            // Loops from start to end of buffer
            return_string += buffer[e];                     // Append character to return string
            count --;                                       // Decrease count
        }
        // Append elements from start of the buffer until '\n' is read
        int d = 0;
        while(buffer[d] != '\n'){
            return_string += buffer[d];
            count --;
            d++;
        }
        if(buffer[d] == '\n')
            count --;                                       // Makes sure count is correct
    }

    for(int i = start; i <= findNewline(); i++){          // No loop in buffer, so append 'normally'
        if(buffer[i] == '\n') {
            start = i+1;
            count--;
            return return_string;
        }

        return_string += buffer[i];
        count--;
    }

    return return_string;
}
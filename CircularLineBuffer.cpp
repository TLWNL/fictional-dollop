//
// Created by dylan on 2/7/19.
//

#include "CircularLineBuffer.h"
#include <string.h>
#include <cstdlib>
#include <iostream>

int CircularLineBuffer::freeSpace() {
    return bufferSize - this->count;
}

bool CircularLineBuffer::isFull(){
    return this->count == bufferSize;
}

bool CircularLineBuffer::isEmpty() {
    return this->count == 0;
}

int CircularLineBuffer::nextFreeIndex() {
    if(this.isFull())
        return -1;

    return this->start + this->count;
}

int CircularLineBuffer::findNewline() {
    for(int i = this->start; i < bufferSize; i++) {
        if(this->buffer[i] == '\n')
            return i;
    }
    for(int j = 0; j < this->start; j++) {
        if(this->buffer[j] == '\n')
            return j;
    }
    return -1;
}

bool CircularLineBuffer::hasLine() {
    return this.findNewline() > 0;
}

bool CircularLineBuffer::_writeChars(const char *chars, size_t nchars) {
    bool loop = false;
    int chars_written = 0;
    int start_point = this.nextFreeIndex();

    if(nchars > freeSpace()) {
        std::cout << "Not enough space in the buffer!\n";
        return false;
    }

    for(int i = start_point; i< start_point + nchars; i++){
        if(i >= bufferSize) {
            loop = true;
            break;
        }
        this->buffer[i] = chars[chars_written];
        this->count++;
        chars_written++;
    }
    if(loop){
        int magnie;
        int chars_left = nchars - chars_written;

        while(chars_left != 0){
            magnie = (this->start+this->count) - bufferSize;
            this->buffer[magnie] = chars[chars_written];
            chars_written++;
            chars_left--;
            this->count++;
        }

    }
    return true;
}

std::string CircularLineBuffer::_readLine() {
    std::string return_string;

    if(this.findNewline() == -1)
        return return_string;               // Return empty string if there is no full line


    if(findNewline() < this->start){
        for(int e = this->start; e < bufferSize; e++){            // Loops from start to end of buffer
            return_string += buffer[e];                     // Append character to return string
            this->count --;                                       // Decrease count
        }
        // Append elements from start of the buffer until '\n' is read
        int d = 0;
        while(this->buffer[d] != '\n'){
            return_string += buffer[d];
            this->count --;
            d++;
        }
        if(this->buffer[d] == '\n')
            this->count --;                                       // Makes sure count is correct
    }

    for(int i = this->start; i <= findNewline(); i++){          // No loop in buffer, so append 'normally'
        if(this->buffer[i] == '\n') {
            this->start = i+1;
            this->count--;
            return return_string;
        }

        return_string += this->buffer[i];
        this->count--;
    }

    return return_string;
}
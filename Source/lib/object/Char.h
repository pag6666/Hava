#pragma once

#include "object.h"
namespace System {
class Char: public Object {
private:
    char value = '\0';
public:
    Char():Char('\0') { }
    Char(char value) {
        this->value = value;
    }
    std::string ToString() const override {
        return ("Char: " + value);
    }
    size_t GetHashCode() const override {
        return std::hash<char>()(value);
    }
    char operator = (char out) {
        return value = out;
    }
    operator char() const {
        return value;
    }
    ~Char() {}
};
}
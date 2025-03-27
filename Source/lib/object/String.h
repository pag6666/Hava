#pragma once

#include "object.h"
namespace System {
class String: public Object {
private:
    std::string value = "";
public:
    String():String("") { }
    String(std::string value) {
        this->value = value;
    }
    String(const char value[]) {
        this->value = std::string(value);
    }
    String(char* value) {
        this->value = std::string(value);
    }
    std::string ToString() const override {
        return ("String: " + value);
    }
    size_t GetHashCode() const override {
        return std::hash<std::string>()(value);
    }
    std::string operator = (std::string out) {
        return value = out;
    }
    std::string operator = (const char value[]) {
        return this->value = std::string(value);
    }
    std::string operator = (char* value) {
        return this->value = std::string(value);
    }
    operator const char*() const {
        return value.c_str();
    }
    ~String() {}
};
}
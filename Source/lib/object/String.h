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
    std::string ToString() const override {
        return ("String: " + value);
    }
    size_t GetHashCode() const override {
        return std::hash<std::string>()(value);
    }
    std::string operator = (std::string out) {
        return value = out;
    }
    operator std::string() const {
        return value;
    }
    ~String() {}
};
}
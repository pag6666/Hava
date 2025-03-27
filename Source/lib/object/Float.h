#pragma once
#include "object.h"
namespace System {
class Float: public Object {
private:
    float value = 0;
public:
    Float():Float(0) { }
    Float(float value) {
        this->value = value;
    }
    std::string ToString() const override {
        return ("Float: " + std::to_string(value));
    }
    size_t GetHashCode() const override {
        return std::hash<float>()(value);
    }
    float operator = (float out) {
        return value = out;
    }
    operator float() const {
        return value;
    }
    ~Float() {}
};
}
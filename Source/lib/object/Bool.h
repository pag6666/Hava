#pragma once

#include "object.h"
namespace System {
class Bool: public Object {
private:
    bool value = 0;
public:
    Bool():Bool(0) { }
    Bool(bool value) {
        this->value = value;
    }
    std::string ToString() const override {
        return ("Bool: " + std::to_string(value));
    }
    size_t GetHashCode() const override {
        return std::hash<bool>()(value);
    }
    bool operator = (bool out) {
        return value = out;
    }
    operator bool() const {
        return value;
    }
    ~Bool() {}
};
}
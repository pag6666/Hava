#pragma once
#include "object.h"
namespace System {
class Int: Object {
    private:
    int value;
    public:
    std::string ToString() const override {
        return ("Int: " + std::to_string(value));
    }
    size_t GetHashCode() const override {
        return std::hash<std::string>()("Int: ")^std::hash<int>()(value);
    }
    int operator = (int out) {
        return value = out;
    }
    operator int() const {
        return value;
    }
};
}
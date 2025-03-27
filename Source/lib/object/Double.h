#pragma once

#include "object.h"
namespace System {
class Double: public Object {
private:
    double value = 0;
public:
    Double():Double(0) { }
    Double(double value) {
        this->value = value;
    }
    std::string ToString() const override {
        return ("Double: " + std::to_string(value));
    }
    size_t GetHashCode() const override {
        return std::hash<double>()(value);
    }
    double operator = (double out) {
        return value = out;
    }
    operator double() const {
        return value;
    }
    ~Double() {}
};
}
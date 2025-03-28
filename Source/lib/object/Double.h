#pragma once

#include "object.h"
#include "../memory_stack/GC/Gc.h"
namespace System {
class Double: public Object {
private:
    double value = 0;
public:
    static bool isPointerFlag;
    void* operator new(size_t size) {
        isPointerFlag = true;
        return ::operator new(size);
    }
    Double():Double(0) { }
    Double(double value) {
        this->value = value;
         if (isPointerFlag)
	        System::Memory::Gc::heap.push_back(System::Memory::p_gc_type(this, VAR_NAME(System::Double)));
        else
	        System::Memory::Gc::stack.push_back(System::Memory::p_gc_type(this, VAR_NAME(System::Double)));
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
bool System::Double::isPointerFlag = false;
}
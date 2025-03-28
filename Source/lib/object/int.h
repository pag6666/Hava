#pragma once

#include "object.h"
#include "../memory_stack/GC/Gc.h"
namespace System {
class Int: public Object {
private:
    int value = 0;
public:
    static bool isPointerFlag;
    void* operator new(size_t size) {
        isPointerFlag = true;
        return ::operator new(size);
    }
    Int():Int(0) { }
    Int(int value) {
        this->value = value;
         if (isPointerFlag)
	        System::Memory::Gc::heap.push_back(this);
        else
	        System::Memory::Gc::stack.push_back(this);
    }
    std::string ToString() const override {
        return ("Int: " + std::to_string(value));
    }
    size_t GetHashCode() const override {
        return std::hash<int>()(value);
    }
    int operator = (int out) {
        return value = out;
    }
    operator int() const {
        return value;
    }
    ~Int() {}
};
bool System::Int::isPointerFlag = false;
}
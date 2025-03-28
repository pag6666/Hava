#pragma once

#include "object.h"
#include "../memory_stack/GC/Gc.h"
namespace System {
class Float: public Object {
private:
    float value = 0;
public:
    static bool isPointerFlag;
    void* operator new(size_t size) {
        isPointerFlag = true;
        return ::operator new(size);
    }
    Float():Float(0) { }
    Float(float value) {
        this->value = value;
         if (isPointerFlag)
	        System::Memory::Gc::heap.push_back(System::Memory::p_gc_type(this, VAR_NAME(System::Float)));
        else
	        System::Memory::Gc::stack.push_back(System::Memory::p_gc_type(this, VAR_NAME(System::Float)));
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
bool System::Float::isPointerFlag = false;
}
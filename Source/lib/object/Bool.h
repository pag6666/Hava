#pragma once

#include "object.h"
#include "../memory_stack/GC/Gc.h"
namespace System {
class Bool: public Object {
private:
    bool value = 0;
public:
    static bool isPointerFlag;
    void* operator new(size_t size) {
        isPointerFlag = true;            
        return ::operator new(size);
    }
    Bool():Bool(0) { }
    Bool(bool value) {
        this->value = value;
        if (isPointerFlag)
	        System::Memory::Gc::heap.push_back(System::Memory::p_gc_type(this, VAR_NAME(System::Bool)));
        else
	        System::Memory::Gc::stack.push_back(System::Memory::p_gc_type(this, VAR_NAME(System::Bool)));
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
bool System::Bool::isPointerFlag = false;
}
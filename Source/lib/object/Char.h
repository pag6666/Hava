#pragma once

#include "object.h"
#include "../memory_stack/GC/Gc.h"
namespace System {
class Char: public Object {
private:
    char value = '\0';
public:
    static bool isPointerFlag;
    void* operator new(size_t size) {
        isPointerFlag = true;
        return ::operator new(size);
    }
    Char():Char('\0') { 
    }
    Char(char value) {
        this->value = value;
         if (isPointerFlag)
	        System::Memory::Gc::heap.push_back(System::Memory::p_gc_type(this, VAR_NAME(System::Char)));
        else
	        System::Memory::Gc::stack.push_back(System::Memory::p_gc_type(this,VAR_NAME(System::Char)));
    }
    std::string ToString() const override {
        return ("Char: " + value);
    }
    size_t GetHashCode() const override {
        return std::hash<char>()(value);
    }
    char operator = (char out) {
        return value = out;
    }
    operator char() const {
        return value;
    }
    ~Char() {}
};
bool System::Char::isPointerFlag = false;
}
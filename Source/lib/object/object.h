#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include "../memory_stack/memory_stack_heap.h"

namespace System {
    class Object {
    private:
        std::string value = "";
    public:
        Object() {
        }
        virtual std::string ToString() const {
            return "Object: " + std::string(value);
        }
        Object operator =(std::string out) {
            value = out;
            return *this;
        }
        virtual size_t GetHashCode() const {
            return std::hash<std::string>()(ToString());
        }

        virtual bool Equals(const Object& other) const {
            return this->GetHashCode() == other.GetHashCode();
        }

        ~Object() {}
    };
}

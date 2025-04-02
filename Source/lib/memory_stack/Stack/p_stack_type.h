#pragma once

#include <string>

namespace System {
    namespace Stack {
        namespace Type {
            class p_stack_type {
                public:
                p_stack_type(std::string name, std::string value) {
                    this->name = name;
                    this->value = value;
                }
                std::string name;
                std::string value;

            };
        }
    }
}
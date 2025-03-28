#pragma once
#include "../../object/ex_object.h"
namespace System {
    namespace Memory {
        struct p_gc_type {
        public:
            p_gc_type(System::Object* obj, std::string name) {
                this->obj = obj;
                this->name = name;
            }
            System::Object* obj;
            std::string name;
        };
    }
}

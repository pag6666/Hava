#pragma once
#include "../../object/ex_object.h"
#include <vector>

namespace System{
    namespace Memory {
        class Gc {
            public:
            static std::vector<System::Object*> heap;
            static std::vector<System::Object*> stack;
            static void Info() {
                std::cout << "Heap: " << heap.size() << std::endl;
                std::cout << "Stack: " << stack.size() << std::endl;
            }
            ~Gc(){
                if(heap.size() > 0){
                    for (System::Object* obj : heap) {
                        delete obj;
                    }
                    heap.clear();
                }
                if(stack.size() > 0) {
                    for (System::Object* obj : stack) {
                        delete obj;
                    }
                    stack.clear();
                }
            }
        };
        std::vector<System::Object*> Gc::heap;
        std::vector<System::Object*> Gc::stack;
    }
}

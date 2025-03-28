#pragma once
#include <vector>
#include "p_gc_type.h"
namespace System{
    namespace Memory {
        class Gc {
            public:
            static std::vector<System::Memory::p_gc_type> heap;
            static std::vector<System::Memory::p_gc_type> stack;
            static void Info() {
                std::cout << "Heap: " << heap.size() << std::endl;
                for(size_t i = 0; i < heap.size(); i++){
                    std::cout << "heap_name: " << heap[i].name << std::endl;
                }
                std::cout << "Stack: " << stack.size() << std::endl;
                for(size_t i = 0; i < stack.size(); i++){
                    std::cout << "stack_name: " << stack[i].name << std::endl;
                }
            }
            ~Gc(){
                if(heap.size() > 0){
                    for (size_t i = 0; i < heap.size(); i++) {
                        delete heap[i].obj;
                    }
                    heap.clear();
                }
                if(stack.size() > 0) {
                    for (size_t i = 0; i < stack.size(); i++) {
                        delete stack[i].obj;
                    }
                    stack.clear();
                }
            }
        };
        std::vector<System::Memory::p_gc_type> Gc::heap;
        std::vector<System::Memory::p_gc_type> Gc::stack;
    }
}

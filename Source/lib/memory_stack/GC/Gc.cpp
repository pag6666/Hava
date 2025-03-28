#include "Gc.h"

namespace System {
    namespace Memory {
        std::vector<System::Memory::p_gc_type> Gc::heap;
        std::vector<System::Memory::p_gc_type> Gc::stack;
    }
}
#include "Gc.h"

namespace System {
    namespace Memory {
        // Определение статических переменных
        std::vector<System::Object*> Gc::heap; // Определение вектора для кучи
        std::vector<System::Object*> Gc::stack; // Определение вектора для стека
    }
}
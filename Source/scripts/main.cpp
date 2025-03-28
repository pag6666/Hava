#include <iostream>
#include "../lib/fun/ex_fun.h"
#include "../lib/object/ex_object.h"
#include "../lib/memory_stack/GC/Gc.h"

void print_oject(System::Object& obj) {
    std::cout << "info: ( "<< obj.ToString() << " )." << std::endl;
}
int main (int argc, char* argv[]) {

    System::Char* ch = new System::Char('A');
    System::Int* i = new System::Int(0);
    System::Float* f = new System::Float(0);
    System::Double* d = new System::Double(0);
    System::Bool b =  System::Bool(0);

    System::String str = System::String("1");
    
    System::Memory::Gc::Info();
    return EXIT_SUCCESS;
}
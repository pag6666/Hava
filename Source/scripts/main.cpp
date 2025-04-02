#include <iostream>
#include "../lib/fun/ex_fun.h"
#include "../lib/object/ex_object.h"
#include "../lib/memory_stack/GC/Gc.h"
#include "../lib/interpreter/interpreter.h"

void print_oject(System::Object& obj) {
    std::cout << "info: ( "<< obj.ToString() << " )." << std::endl;
}
void test_type() {
    System::Char* ch = new System::Char('A');
    System::Int* i = new System::Int(0);
    System::Float* f = new System::Float(0);

    System::Double d = 0.123;

    System::Bool b =  true;

    System::String str = System::String("1");
    
    System::Memory::Gc::Info();
}
int main (int argc, char* argv[]) {

    //test_type();
    System::Interpreter::Interpreter* inter = new System::Interpreter::Interpreter();

    inter->OpenFile(L"C:\\Users\\SystemX\\Documents\\test\\main.hava");
    inter->PrintScripts();
    
    System::Memory::Gc::Info();
    delete inter;
    return EXIT_SUCCESS;
}
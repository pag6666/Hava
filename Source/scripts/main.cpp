#include <iostream>
#include "../lib/object/ex_object.h"

void print_oject(System::Object& obj) {
    std::cout << "info: ( "<< obj.ToString() << " )." << std::endl;
}
int main (int argc, char* argv[]) {
    
    System::Char ch = '!';
    System::String str = "Hello World";
    System::Int i = 1;
    System::Float f = 0.23f;
    System::Double d = 0.32;
    System::Bool b = 0;

    return EXIT_SUCCESS;
}
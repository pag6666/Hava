#include <iostream>
#include "lib/object/int.h"
int main (int argc, char* argv[]) {
    System::Int var1 = System::Int();
    var1 = 2;
    std::cout << var1 << std::endl;
    return EXIT_SUCCESS;
}
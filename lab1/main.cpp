#include <iostream>
#include "mymath/mymath.h"
#include "newFac/newFac.h"

int main() {
    int a,b;
    std::cin >> a >> b;
    std::cout << "Я умею суммировать! Зацени 1+1=";
    std::cout << mymath::sum(a, b) << std::endl;
    std::cout <<"а еще умею факториал 7" << std::endl;
    std::cout << newFac::factorial(7) << std::endl;
    return 0;
}

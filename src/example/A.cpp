#include "../../include/example/A.hpp"
#include "../../include/reflection/classregister.hpp"
#include <iostream>

namespace example {
    
void A::show() {
    std::cout << "A" << std::endl;
}

REGISTER_CLASS(A);
REGISTER_CLASS_FIELD(A, m_name, string);
REGISTER_CLASS_FIELD(A, m_age, int);
REGISTER_CLASS_METHOD(A, show);

}
#ifndef _A_
#define _A_

#include <string>
#include "../reflection/classfactory.hpp"

namespace example{ 

class A: public reflect::Object {
public:
    void show();

    std::string m_name;
    int m_age;
};

}


#endif
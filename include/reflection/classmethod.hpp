#ifndef _CLASSMETHOD_
#define _CLASSMETHOD_

#include <string>
#include <stddef.h>

namespace reflect {

class ClassMethod {
public:
    ClassMethod();
    ClassMethod(const std::string& name, uintptr_t method);
    ~ClassMethod() {}

public:
    const std::string& getName() { return m_name; }
    uintptr_t getMethod() { return m_method; }

private:
    std::string m_name;
    uintptr_t m_method;
};

}


#endif
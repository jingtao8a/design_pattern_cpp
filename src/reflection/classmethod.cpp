#include "../../include/reflection/classmethod.hpp"

namespace reflect {

ClassMethod::ClassMethod()
            :m_name(""),
            m_method(0) {}

ClassMethod::ClassMethod(const std::string& name, uintptr_t method)
            :m_name(name),
            m_method(method) {}

}
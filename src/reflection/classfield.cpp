#include "../../include/reflection/classfield.hpp"

namespace reflect {

ClassField::ClassField()
            :m_name(""),
            m_type(""),
            m_offset(0) {}

ClassField::ClassField(const std::string&name, const std::string& type, size_t offset) 
            :m_name(name),
            m_type(type),
            m_offset(offset){}

}
#include "../../include/reflection/classregister.hpp"
#include <iostream>

namespace reflect
{

ClassRegister::ClassRegister(const std::string& className, create_object method) {
    std::cout << "class register " << className << std::endl;
    ClassFactory* factory = utility::Singleton<ClassFactory>::instance();
    factory->register_class(className, method);
}

ClassRegister::ClassRegister(const std::string& className, const std::string& fieldName, const std::string& fieldType, size_t offset) {
    std::cout << "class register field " << fieldName << std::endl;
    ClassFactory* factory = utility::Singleton<ClassFactory>::instance();
    factory->register_class_field(className, fieldName, fieldType, offset);
}

ClassRegister::ClassRegister(const std::string& className, const std::string& methodName, uintptr_t method) {
    std::cout << "class register method " << methodName << std::endl;
    ClassFactory* factory = utility::Singleton<ClassFactory>::instance();
    factory->register_class_method(className, methodName, method);
}

}
 // namespace reflect

#ifndef _CLASSREGISTER_
#define _CLASSREGISTER_
#include "classfactory.hpp"
#include <functional>

namespace reflect{ 

class ClassRegister {
public:
    ClassRegister(const std::string& className, create_object method);
    ClassRegister(const std::string& className, const std::string& fieldName, const std::string& fieldType, size_t offset);
    ClassRegister(const std::string& className, const std::string& methodName, uintptr_t method);
};

#define REGISTER_CLASS(className)\
    reflect::Object *createObject##className() {\
        reflect::Object *obj = new className();\
        obj->setClassName(#className);\
        return obj;\
    } \
    reflect::ClassRegister classRegister##className(#className, createObject##className)

#define REGISTER_CLASS_FIELD(className, fieldName, fieldType)\
    className className##fieldName;\
    reflect::ClassRegister classRegister##className##fieldName(#className, #fieldName, #fieldType, (size_t)(&(className##fieldName.fieldName)) - (size_t)(&className##fieldName))
}

#define REGISTER_CLASS_METHOD(className, methodName)\
    std::function<void(className *) > className##methodName##method = &className::methodName;\
    reflect::ClassRegister classRegister##className##methodName(#className, #methodName, (uintptr_t)&className##methodName##method)

#endif
#include "../../include/reflection/classfactory.hpp"
#include <functional>

namespace reflect {

Object::Object() {}

Object::~Object() {}

int Object::get_field_count() {
    ClassFactory *factory = utility::Singleton<ClassFactory>::instance();
    return factory->getFieldCount(m_className);
}
    
ClassField *Object::get_field(int pos) {
    ClassFactory *factory = utility::Singleton<ClassFactory>::instance();
    return factory->getField(m_className, pos);
}
    
ClassField *Object::get_field(const std::string& fieldName) {
    ClassFactory *factory = utility::Singleton<ClassFactory>::instance();
    return factory->getField(m_className, fieldName);
}

void Object::call(const std::string& methodName) {
    ClassFactory *factory = utility::Singleton<ClassFactory>::instance();
    ClassMethod * methodinfo = factory->getClassMethod(m_className, methodName);
    uintptr_t method = methodinfo->getMethod();
    typedef std::function<void(decltype(this))> class_method;
    (*((class_method *)method))(this);
}


void ClassFactory::register_class(const std::string& className, create_object method) {
    m_classMap[className] = method;
}

Object* ClassFactory::create_class(const std::string& className) {
    auto it = m_classMap.find(className);
    if (it == m_classMap.end()) {
        return nullptr;
    }
    return it->second();
}

void ClassFactory::register_class_field(const std::string& className, const std::string& fieldName, const std::string& fieldType, size_t offset) {
    m_classFields[className].push_back(new ClassField(fieldName, fieldType, offset));
}

int ClassFactory::getFieldCount(const std::string& className) {
    return m_classFields[className].size();
}

ClassField * ClassFactory::getField(const std::string& className, int pos) {
    int size = getFieldCount(className);
    if (pos < 0 || pos >= size) {
        return nullptr;
    }
    return m_classFields[className][pos];
}

ClassField * ClassFactory::getField(const std::string& className, const std::string& fieldName) {
    for (auto it = m_classFields[className].begin(); it != m_classFields[className].end(); ++it) {
        if ((*it)->getName() == fieldName) {
            return (*it);
        }
    }
    return nullptr;
}


void ClassFactory::register_class_method(const std::string& className, const std::string& methodName, uintptr_t method) {
    m_classMethods[className].push_back(new ClassMethod(methodName, method));
}

int ClassFactory::getClassMethodCount(const std::string& className) {
    return m_classMethods[className].size();
}
    
ClassMethod *ClassFactory::getClassMethod(const std::string& className, int pos) {
    size_t size = m_classMethods[className].size();
    if (pos < 0 || pos >= size) {
        return nullptr;
    }
    return m_classMethods[className][pos];
}
    
ClassMethod *ClassFactory::getClassMethod(const std::string& className, const std::string& methodName) {
    for (auto iter = m_classMethods[className].begin(); iter != m_classMethods[className].end(); ++iter) {
        if ((*iter)->getName() == methodName) {
            return (*iter);
        }
    }
    return nullptr;
}

}
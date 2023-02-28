#ifndef _CLASSFACTORY_
#define _CLASSFACTORY_

#include <string>
#include <map>
#include <vector>
#include "../utility/singleton.hpp"
#include "classfield.hpp"
#include "classmethod.hpp"

namespace reflect {

class Object {
public:
    Object();

    virtual ~Object();
    
    void call(const std::string& methodName);
    
    int get_field_count();
    
    ClassField *get_field(int pos);
    
    ClassField *get_field(const std::string& fieldName);

    template <typename T>
    void get(const std::string& fieldName, T& value);

    template <typename T>
    void set(const std::string& fieldName, const T& value);

public:
    void setClassName(const std::string& name) { m_className = name; }

    const std::string& getClassName() { return m_className; }

private:
    std::string m_className;
};

typedef Object *(*create_object)();

class ClassFactory {
    template <class T>
    friend class utility::Singleton;
public:
    void register_class(const std::string& className, create_object method);

    Object* create_class(const std::string& className);

public:
    void register_class_field(const std::string& className, const std::string& fieldName, const std::string& fieldType, size_t offset);
    
    int getFieldCount(const std::string& className);
    
    ClassField *getField(const std::string& className, int pos);
    
    ClassField *getField(const std::string& className, const std::string& fieldName);

public:
    void register_class_method(const std::string& className, const std::string& methodName, uintptr_t method);

    int getClassMethodCount(const std::string& className);
    
    ClassMethod *getClassMethod(const std::string& className, int pos);
    
    ClassMethod *getClassMethod(const std::string& className, const std::string& methodName);

private:
    ClassFactory() {}
    ~ClassFactory() {}

private:
    std::map<std::string, create_object> m_classMap;
    std::map<std::string, std::vector<ClassField*> > m_classFields;
    std::map<std::string, std::vector<ClassMethod*> > m_classMethods;
}; 

template <typename T>
void Object::get(const std::string& fieldName, T& value) {
    ClassFactory *factory = utility::Singleton<ClassFactory>::instance();
    ClassField* field = factory->getField(m_className, fieldName);
    size_t offset = field->getOffset();
    value = *(T*)((char *)this + offset);
}

template <typename T>
void Object::set(const std::string& fieldName,const T& value) {
    ClassFactory *factory = utility::Singleton<ClassFactory>::instance();
    ClassField* field = factory->getField(m_className, fieldName);
    size_t offset = field->getOffset();
    *(T*)((char *)this + offset) = value;
}

}

#endif
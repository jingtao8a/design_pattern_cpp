#include "../include/reflection/classfactory.hpp"
#include <iostream>

int main() {
    reflect::ClassFactory *factory = utility::Singleton<reflect::ClassFactory>::instance();
    reflect::Object *obj = factory->create_class("A");
    obj->call("show");
    obj->set("m_name", std::string("yuxintao"));
    obj->set("m_age", 22);
    std::string name;
    int age;
    obj->get("m_name", name);
    obj->get("m_age", age);
    std::cout << name << age << std::endl;
    auto fieldinfo = obj->get_field("m_name");
    std::cout << fieldinfo->getName() << fieldinfo->getOffset() << fieldinfo->getType();
    return 0;
}
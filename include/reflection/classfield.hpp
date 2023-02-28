#ifndef _CLASSFIELD_
#define _CLASSFIELD_

#include <string>
#include <stddef.h>

namespace reflect {

class ClassField {
public:
    ClassField();
    ClassField(const std::string&name, const std::string& type, size_t offset);
    ~ClassField() {}

public:
    const std::string& getName() {
        return m_name;
    }
    
    const std::string& getType() {
        return m_type;
    }

    size_t getOffset() {
        return m_offset;
    }

private:
    std::string m_name;
    std::string m_type;
    size_t m_offset;
};

}

#endif
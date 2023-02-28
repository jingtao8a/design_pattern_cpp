#ifndef _SINGLETON_
#define _SINGLETON_

namespace utility {

template <class T>
class Singleton {
public:
    static T* instance() {
        static T obj;
        return &obj;
    }
private:
    Singleton() {}
    ~Singleton() {}
    Singleton& operator=(const Singleton&);
    Singleton(const Singleton&);
};

}

#endif
#include <algorithm>
#include <iostream>

#include "valueholder.hpp"

class Any {
public:
    Any() = default;
    
    template<class T>
    Any(const T& value)
        : holder_(new ValueHolder<T>(value)) 
    { }
   
    ~Any() {
        delete holder_;
        holder_ = nullptr;
    }
    
    Any(const Any& a) 
        : holder_(a.holder_ ? a.holder_->clone() : nullptr) 
    { }

    void swap(Any& a) {
        std::swap(holder_, a.holder_);
    }
    
    Any& operator=(const Any& a) {
        Any(a).swap(*this);
        return *this;
    }

    template<class T>
    Any& operator=(const T& value) {
        Any(value).swap(*this);
        return *this;
    }

    template<class T>
    T* cast() {
        ValueHolder<T>* holderptr = dynamic_cast<ValueHolder<T>*>(holder_);
        if (!holderptr)
            return nullptr;

        return &holderptr->value_;
    }

private:
    ICloneable* holder_ = nullptr;
};

int main() {
    Any empty;
    Any a(10);
    a = empty;
    a = 'a';
    char* value = a.cast<char>();
    std::cout << *value << std::endl;
}

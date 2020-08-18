#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <algorithm>

template <typename T>
class Array {
public:
    Array() = default;

    explicit Array(size_t size)
        : Array(size, T()) {
    }

    Array(size_t size, const T& value)
        : size_(size)
        , data_((T*) new char [size * sizeof(T)]) {
        for (size_t i = 0; i != size_; ++i)
            new (data_ + i) T(value);
    }

    Array(const Array& other)
        : size_(other.size_)
        , data_((T*) new char [other.size_ * sizeof(T)]) {
        for (size_t i = 0; i != size_; ++i)
            new (data_ + i) T(other.data_[i]);
    }
    
    ~Array() {
        for (size_t i = 0; i != size_; ++i)
            data_[i].~T();

        delete[] (char*)data_;
        data_ = nullptr;
    }
    
    Array& operator=(const Array& other) {
        Array(other).swap(*this);
        return *this;
    }

    void swap(Array& other) {
        std::swap(size_, other.size_);
        std::swap(data_, other.data_);
    }
    
    size_t size() const {
        return size_;
    }
   
    T& operator[](size_t i) {
        return data_[i];
    }

    const T& operator[](size_t i) const {
        return data_[i];
    }
    
private:
    size_t size_ = 0;
    T* data_ = nullptr;
};

#endif // __ARRAY_HPP__

#include <algorithm>

template <typename T>
class Array {
public:
    explicit Array(size_t size = 0, const T& value = T())
        : size_(size)
        , data_(new T [size]) {
        for (size_t i = 0; i != size_; ++i)
            data_[i] = value;
    }

    Array(const Array& other)
        : size_(other.size_)
        , data_(new T [other.size_]) {
        for (size_t i = 0; i != size_; ++i)
            data_[i] = other.data_[i];
    }
    
    ~Array() {
        delete[] data_;
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
    T* data_;
    size_t size_;
};

int main() {
    Array<int> arr(5, 0);
    Array<int> arr2(5, 1);
    arr.swap(arr2);
    return 0;
}

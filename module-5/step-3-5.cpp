#include <algorithm>

template <typename T>
struct SharedPtr {
    struct PtrCounter {
        PtrCounter()
            : counter(1) {
        }

        unsigned counter;
    };

    explicit SharedPtr(T* ptr = nullptr)
        : ptr_(ptr)
        , ptr_counter(ptr ? new PtrCounter : nullptr) {
    }

    ~SharedPtr() {
        if (!ptr_counter)
            return;
            
        --ptr_counter->counter;
        if (!ptr_counter->counter) {
            delete ptr_;
            ptr_ = nullptr;
            delete ptr_counter;
            ptr_counter = nullptr;
        }
    }

    SharedPtr(const SharedPtr& other)
        : ptr_(other.ptr_)
        , ptr_counter(other.ptr_counter) {
        if (ptr_counter)
            ++ptr_counter->counter;      
    }

    SharedPtr& operator=(const SharedPtr& other) {
        SharedPtr(other).swap(*this);
        return *this;
    }

    T* get() const {
        return ptr_;
    }

    void reset(T* ptr = nullptr) {
        SharedPtr(ptr).swap(*this);
    }

    T& operator*() const {
        return *ptr_;
    }

    T* operator->() const {
        return ptr_;
    }

    void swap(SharedPtr& other) {
        std::swap(this->ptr_, other.ptr_);
        std::swap(this->ptr_counter, other.ptr_counter);
    }

private:
    T* ptr_;
    PtrCounter* ptr_counter;
};

struct Expr { 
};

int main() {
    SharedPtr<Expr> p(new Expr);
    return 0;
}

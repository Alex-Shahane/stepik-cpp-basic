#include <algorithm>

struct Expression { 
};

struct SharedPtr {
    struct PtrCounter {
        PtrCounter()
            : counter(1) {
        }

        unsigned counter;
    };

    explicit SharedPtr(Expression* ptr = nullptr)
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

    Expression* get() const {
        return ptr_;
    }

    void reset(Expression* ptr = nullptr) {
        SharedPtr(ptr).swap(*this);
    }

    Expression& operator*() const {
        return *ptr_;
    }

    Expression* operator->() const {
        return ptr_;
    }

    void swap(SharedPtr& other) {
        std::swap(this->ptr_, other.ptr_);
        std::swap(this->ptr_counter, other.ptr_counter);
    }

private:
    Expression* ptr_;
    PtrCounter* ptr_counter;
};

int main() {
    return 0;
}

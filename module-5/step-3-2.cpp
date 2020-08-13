struct Expression { 
};

struct ScopedPtr {
    explicit ScopedPtr(Expression* ptr = nullptr)
        : ptr_(ptr) 
    { }

    ~ScopedPtr() {
        delete ptr_;
        ptr_ = nullptr;
    }

    Expression* get() const {
        return ptr_;
    }

    Expression* release() {
        Expression* new_ptr = ptr_;
        ptr_ = nullptr;
        return new_ptr;
    }

    void reset(Expression* ptr = nullptr) {
        delete ptr_;
        ptr_ = ptr;
    }

    Expression& operator*() const {
        return *ptr_;
    }

    Expression* operator->() const {
        return ptr_;
    }

private:
    ScopedPtr(const ScopedPtr&);

    ScopedPtr& operator=(const ScopedPtr&);

    Expression* ptr_;
};

int main() {
    return 0;
}

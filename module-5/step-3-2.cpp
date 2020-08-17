template <typename T>
struct ScopedPtr {
    explicit ScopedPtr(T* ptr = nullptr)
        : ptr_(ptr) 
    { }

    ~ScopedPtr() {
        delete ptr_;
        ptr_ = nullptr;
    }

    T* get() const {
        return ptr_;
    }

    T* release() {
        T* new_ptr = ptr_;
        ptr_ = nullptr;
        return new_ptr;
    }

    void reset(T* ptr = nullptr) {
        delete ptr_;
        ptr_ = ptr;
    }

    T& operator*() const {
        return *ptr_;
    }

    T* operator->() const {
        return ptr_;
    }

private:
    ScopedPtr(const ScopedPtr&);
    ScopedPtr& operator=(const ScopedPtr&);

    T* ptr_;
};

struct Expr { 
};

int main() {
    ScopedPtr<Expr> p(new Expr);
    return 0;
}

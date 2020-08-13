struct Expression { 
};

struct SharedPtr
{
    explicit SharedPtr(Expression *ptr = 0) {

    }

    ~SharedPtr() {

    }

    SharedPtr(const SharedPtr &) {

    }

    SharedPtr& operator=(const SharedPtr &) {

    }

    Expression* get() const {

    }

    void reset(Expression *ptr = 0) {

    }

    Expression& operator*() const {

    }

    Expression* operator->() const {
        
    }
};
#include <iostream>

struct Expression {
    virtual ~Expression() = default;
    virtual double evaluate() const = 0;
    virtual int type() const {
        return 0;
    };
};

struct Number : Expression {
    Number(double value)
        : value(value)
    {}

    double evaluate() const {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression {

    BinaryOperation(Expression const* left, char op, Expression const* right)
        : left(left), op(op), right(right)
    { }

    ~BinaryOperation() {
        delete left;
        left = nullptr;
        delete right;
        right = nullptr;
    }

    double evaluate() const override {
        switch (this->op) {
        case '+':
            return left->evaluate() + right->evaluate();
        case '-':
            return left->evaluate() - right->evaluate();
        case '*':
            return left->evaluate() * right->evaluate();
        case '/':
            return left->evaluate() / right->evaluate();
        default:
            return 0;
        }
    }

private:
    Expression const* left;
    Expression const* right;
    char op;
};


struct ScopedPtr {
    explicit ScopedPtr(Expression* ptr = 0)
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

    void reset(Expression* ptr = 0) {
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

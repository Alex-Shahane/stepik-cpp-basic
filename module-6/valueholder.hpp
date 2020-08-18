#ifndef __VALUEHOLDER_HPP__
#define __VALUEHOLDER_HPP__

struct ICloneable {
    virtual ICloneable* clone() const = 0;
    virtual ~ICloneable() = default;
};

template <typename T>
struct ValueHolder : ICloneable {
    explicit ValueHolder(const T& value)
        : value_(value) {
    }

    ICloneable* clone() const override {
        return new ValueHolder(value_);
    }

    T value_;
};

#endif // __VALUEHOLDER_HPP__

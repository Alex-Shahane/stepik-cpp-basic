struct ICloneable {
    virtual ICloneable* clone() const = 0;
    virtual ~ICloneable() = default;
};

template <typename T>
struct ValueHolder : ICloneable {
    explicit ValueHolder(const T& data)
        : data_(data) {
    }

    ICloneable* clone() const override {
        return new ValueHolder(data_);
    }

    T data_;
};

int main() {
    ValueHolder<int> aa(10);        
    return 0;
}

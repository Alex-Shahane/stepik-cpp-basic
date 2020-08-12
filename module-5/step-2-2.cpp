
struct Rational {
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational rational);
    void sub(Rational rational);
    void mul(Rational rational);
    void div(Rational rational);

    void neg();
    void inv();
    double to_double() const;
    
    operator double() const {
        return to_double();
    }
    
    Rational& operator+=(Rational rational) {
        add(rational);
        return *this;
    };

    Rational& operator-=(Rational rational) {
        sub(rational);
        return *this;
    };

    Rational& operator*=(Rational rational) {
        mul(rational);
        return *this;
    };

    Rational& operator/=(Rational rational) {
        div(rational);
        return *this;
    };

    Rational operator-() const { 
        Rational new_rat(*this);
        new_rat.neg();
        return new_rat; 
    }

    Rational operator+() const { 
        return *this; 
    }

    friend bool operator==(const Rational& left, const Rational& right);
    friend bool operator!=(const Rational& left, const Rational& right);
    friend bool operator<(const Rational& left, const Rational& right);
    friend bool operator>(const Rational& left, const Rational& right);
    friend bool operator>=(const Rational& left, const Rational& right);
    friend bool operator<=(const Rational& left, const Rational& right);

private:
    int numerator_;
    int denominator_;
};

Rational operator+(Rational l, const Rational& rational) {
    return l += rational;
}

Rational operator-(Rational l, const Rational& rational) {
    return l -= rational;
}

Rational operator*(Rational l, const Rational& rational) {
    return l *= rational;
}

Rational operator/(Rational l, const Rational& rational) {
    return l /= rational;
}

bool operator==(const Rational& left, const Rational& right) {
    return left.numerator_ * right.denominator_ == right.numerator_ * left.denominator_;
}

bool operator!=(const Rational& left, const Rational& right) {
    return !(left == right);
}

bool operator<(const Rational& left, const Rational& right) {
    return left.numerator_ * right.denominator_ < right.numerator_ * left.denominator_;
}

bool operator>(const Rational& left, const Rational& right) {
    return right < left;
}

bool operator>=(const Rational& left, const Rational& right) {
    return !(left < right);
}

bool operator<=(const Rational& left, const Rational& right) {
    return !(left > right);
}

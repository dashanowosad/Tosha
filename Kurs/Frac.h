//
// Created by asakujaku on 19.02.2020.
//

#pragma once

#include <numeric>
#include <iostream>
#include <string>

class Frac{
private:
    int64_t numerator;
    int64_t denominator;
    inline void Simplify();
public:
    Frac();
    explicit Frac(const int64_t&);
    Frac(const int64_t&, const int64_t&);
    ~Frac();

    Frac& operator=(const int);
    Frac& operator=(const Frac&);

    Frac& operator+=(const int);
    Frac& operator+=(const Frac&);

    Frac& operator-=(const int);
    Frac& operator-=(const Frac&);

    Frac& operator*=(const int);
    Frac& operator*=(const Frac&);

    Frac& operator/=(const int);
    Frac& operator/=(const Frac&);

    Frac& operator-();

    friend Frac operator+(const Frac&, const Frac&);
    friend Frac operator-(const Frac&, const Frac&);
    friend Frac operator*(const Frac&, const Frac&);
    friend Frac operator/(const Frac&, const Frac&);

    bool operator==(const int);
    bool operator==(const Frac&);

    bool operator>(const int);
    bool operator>(const Frac&);

    bool operator<(const int);
    bool operator<(const Frac&);

    bool operator!=(const int);
    bool operator!=(const Frac&);

    friend std::ostream& operator<<(std::ostream&, const Frac&);
    friend std::istream& operator>>(std::istream&, Frac&);
};


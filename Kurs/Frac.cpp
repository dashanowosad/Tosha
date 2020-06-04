//
// Created by asakujaku on 19.02.2020.
//


#include "Frac.h"

Frac::Frac(): numerator(0), denominator(1){}

Frac::Frac(const int64_t &num) : numerator(num), denominator(1){}

Frac::Frac(const int64_t& num, const int64_t& den) : numerator(num), denominator(den) { this->Simplify(); }

Frac::~Frac()= default;


void Frac::Simplify() {
    int64_t gcd = std::gcd(std::abs(this->numerator), std::abs(this->denominator));
    this->numerator /= gcd;
    this->denominator /= gcd;
    if (this->denominator == 0) {
        throw std::logic_error("Division by zero");
    }
    if (this->numerator == 0 && this->denominator != 1) {
        this->denominator = 1;
    }
    if (this->numerator < 0 && this->denominator < 0) {
        this->numerator = std::abs(this->numerator);
        this->denominator = std::abs(this->denominator);
    }
    if (this->denominator < 0) {
        this->numerator *= -1;
        this->denominator = std::abs(this->denominator);
    }
}


Frac& Frac::operator=(const int num){
    this->numerator = num;
    this->denominator = 1;
    this->Simplify();
    return *this;
}

Frac& Frac::operator=(const Frac& b){
    this->numerator = b.numerator;
    this->denominator = b.denominator;
    this->Simplify();
    return *this;
}

Frac& Frac::operator+=(const int num){
    this->numerator += num * this->denominator;
    this->Simplify();
    return *this;
}

Frac& Frac::operator+=(const Frac& b){
    int64_t nok = std::lcm(this->denominator, b.denominator);
    int64_t fnum, snum;
    fnum = nok / this->denominator * this->numerator;
    snum = nok / b.denominator * b.numerator;
    this->denominator = nok;
    this->numerator = fnum + snum;
    this->Simplify();
    return *this;
}

Frac& Frac::operator-=(const int num){
    this->numerator -= num * this->denominator;
    this->Simplify();
    return *this;
}

Frac& Frac::operator-=(const Frac& b){
    int64_t nok = std::lcm(this->denominator, b.denominator);
    int64_t Fnum, Snum;
    Fnum = nok / this->denominator * this->numerator;
    Snum = nok / b.denominator * b.numerator;
    this->numerator = Fnum - Snum;
    this->denominator = nok;
    this->Simplify();
    return *this;
}

Frac& Frac::operator*=(const int num){
    this->denominator *= num;
    this->Simplify();
    return *this;
}

Frac& Frac::operator*=(const Frac& b) {
    this->numerator *= b.numerator;
    this->denominator *= b.denominator;
    this->Simplify();
    return *this;
}

Frac& Frac::operator/=(const int num){
    this->denominator *= num;
    this->Simplify();
    return *this;
}

Frac& Frac::operator/=(const Frac& b){
    this->numerator *= b.denominator;
    this->denominator *= b.numerator;
    this->Simplify();
    return *this;
}

Frac& Frac::operator-(){
    this->numerator *= -1;
    return *this;
}

bool Frac::operator==(const int num){
    return this->numerator == num && this->denominator == 1;
}

bool Frac::operator==(const Frac& b){
    return this->numerator == b.numerator && this->denominator == b.denominator;
}

bool Frac::operator>(const int num){
    return this->numerator > num * this->denominator;
}

bool Frac::operator>(const Frac& b){
    int64_t nok = std::lcm(this->denominator, b.denominator);
    int64_t Fnum, Snum;
    Fnum = nok / this->denominator * this->numerator;
    Snum = nok / b.denominator * b.numerator;
    return Fnum > Snum;
}

bool Frac::operator<(const int num){
    return this->numerator < num * this->denominator;
}

bool Frac::operator<(const Frac& b){
    int64_t nok = std::lcm(this->denominator, b.denominator);
    int64_t Fnum, Snum;
    Fnum = nok / this->denominator * this->numerator;
    Snum = nok / b.denominator * b.numerator;
    return Fnum < Snum;
}

bool Frac::operator!=(const int num){
    return this->numerator != num * this->denominator;
}

bool Frac::operator!=(const Frac& b){
    return !(this->numerator == b.numerator && this->denominator == b.denominator);
}

Frac operator+(const Frac& a, const Frac& b){
    Frac tmp = a;
    tmp += b;
    return tmp;
}

Frac operator-(const Frac& a, const Frac& b) {
    Frac tmp = a;
    tmp -= b;
    return tmp;
}

Frac operator*(const Frac& a, const Frac& b) {
    Frac tmp = a;
    tmp *= b;
    return tmp;
}

Frac operator/(const Frac& a, const Frac& b) {
    Frac tmp = a;
    tmp /= b;
    return tmp;
}

std::ostream& operator<<(std::ostream& os, const Frac& b){
    std::string tmp = std::to_string(b.numerator);
    if (b.denominator != 1)
        tmp += '/' + std::to_string(b.denominator);
    os << tmp;
    return os;
}

std::istream& operator>>(std::istream& is, Frac& b){
    std::string InputString;
    is >> InputString;
    auto separated = InputString.find('/');
    if (separated == std::string::npos)
        b = Frac(std::stoll(InputString));
    else{
        std::string strNum, strDen;
        strNum = InputString.substr(0, separated);
        strDen = InputString.substr(separated + 1, InputString.length());
        b = Frac(std::stoll(strNum), std::stoll(strDen));
    }
    return is;
}

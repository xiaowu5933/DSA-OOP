#include <bits/stdc++.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

struct PhanSo {
    int iTuSo;
    int iMauSo;
    PhanSo(int _iTuSo = 0, int _iMauSo = 1) {
        iTuSo = _iTuSo;
        iMauSo = _iMauSo;
        assert(iMauSo != 0);
    }
    void RutGon(PhanSo &lhs) {
        int _gcd = gcd(lhs.iTuSo, lhs.iMauSo);
        lhs.iTuSo = lhs.iTuSo / _gcd;
        lhs.iMauSo = lhs.iMauSo / _gcd;
    }
    friend PhanSo operator+(const PhanSo &lhs, const PhanSo &rhs) {
        PhanSo result;
        result.iTuSo = lhs.iTuSo * rhs.iMauSo + rhs.iTuSo * lhs.iMauSo;
        result.iMauSo = lhs.iMauSo * rhs.iMauSo;
        return result;
    }
    friend PhanSo operator-(const PhanSo &lhs, const PhanSo &rhs) {
        PhanSo result;
        result.iTuSo = lhs.iTuSo * rhs.iMauSo - rhs.iTuSo * lhs.iMauSo;
        result.iMauSo = lhs.iMauSo * rhs.iMauSo;
        return result;
    }
    friend PhanSo operator*(const PhanSo &lhs, const PhanSo &rhs) {
        PhanSo result;
        result.iTuSo = lhs.iTuSo * rhs.iTuSo;
        result.iMauSo = lhs.iMauSo * rhs.iMauSo;
        return result;
    }
    friend PhanSo operator/(const PhanSo &lhs, const PhanSo &rhs) {
        PhanSo result;
        result.iTuSo = lhs.iTuSo * rhs.iMauSo;
        result.iMauSo = lhs.iMauSo * rhs.iTuSo;
        return result;
    }
    friend std::istream &operator>>(std::istream &is, PhanSo &lhs) {
        int _iTuSo, _iMauSo;
        is >> _iTuSo >> _iMauSo;
        lhs = PhanSo(_iTuSo, _iMauSo);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const PhanSo &lhs) {
        return os << lhs.iTuSo << " / " << lhs.iMauSo;
    }
    friend bool operator==(const PhanSo &lhs, const PhanSo &rhs) {
        return lhs.iTuSo * rhs.iMauSo == lhs.iMauSo * rhs.iTuSo;
    }
    friend bool operator!=(const PhanSo &lhs, const PhanSo &rhs) {
        return lhs.iTuSo * rhs.iMauSo != lhs.iMauSo * rhs.iTuSo;
    }
    friend bool operator>(const PhanSo &lhs, const PhanSo &rhs) {
        return lhs.iTuSo * rhs.iMauSo > lhs.iMauSo * rhs.iTuSo;
    }
    friend bool operator>=(const PhanSo &lhs, const PhanSo &rhs) {
        return lhs.iTuSo * rhs.iMauSo >= lhs.iMauSo * rhs.iTuSo;
    }
    friend bool operator<(const PhanSo &lhs, const PhanSo &rhs) {
        return lhs.iTuSo * rhs.iMauSo < lhs.iMauSo * rhs.iTuSo;
    }
    friend bool operator<=(const PhanSo &lhs, const PhanSo &rhs) {
        return lhs.iTuSo * rhs.iMauSo <= lhs.iMauSo * rhs.iTuSo;
    }
};

int main() {
    PhanSo a, b;
    std::cin >> a >> b;

    // Tim phan so lon nhat
    if (a > b) {
        std::cout << a << "\n";
    } else {
        std::cout << b << "\n";
    }

    // In ra tong 2 phan so
    std::cout << "Tong 2 phan so la : " << a + b << "\n";

    // In ra hieu 2 phan so
    std::cout << "Hieu 2 phan so la : " << a - b << "\n";

    // In ra tich 2 phan so
    std::cout << "Tich 2 phan so la : " << a * b << "\n";

    // In ra thuong 2 phan so
    std::cout << "Thuong 2 phan so la : " << a / b << "\n";

    return 0;
}


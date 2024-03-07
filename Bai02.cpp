#include <bits/stdc++.h>

void case1(int &day, int &month, int &year) {
    if (day < 28) {
        ++day;
    } else if (day == 28) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            ++day;
        } else {
            day = 1;
            ++month;
        }
    } else {
        std::cout << "Ngay khong hop le\n";
        exit(0);
    }
}

void case2(int &day, int &month, int &year) {
    if (day < 31) {
        ++day;
    } else if (day == 31){
        day = 1;
        ++month;
    } else {
        std::cout << "Ngay khong hop le\n";
        exit(0);
    }
}

void case3(int &day, int &month, int &year) {
    if (day < 30) {
        ++day;
    } else if (day == 30 ){
        day = 1;
        if (month == 12) {
            month = 1;
            ++year;
        } else {
            ++month;
        }
    } else {
        std::cout << "Ngay khong hop le\n";
        exit(0);
    }
}

void solve(int &day, int &month, int &year) {
    if (month == 2) {
        case1(day, month, year);
    } else if ((month >= 1 && month <= 7 && month % 2 == 1) || (month > 7 && month <= 12 && month % 2 == 0)) {
        case1(day, month, year);
    } else if ((month >= 1 && month <= 7 && month % 2 == 0) || (month > 7 && month <= 12 && month % 2 == 1)) {
        case1(day, month, year);
    } else {
        std::cout << "Ngay khong hop le\n";
        exit(0);
    }
}

int main() {
    int day, month, year;
    std::cin >> day >> month >> year;

    solve(day, month, year);
    std::cout << day << "/" << month << "/" << year << "\n";

    return 0;
}

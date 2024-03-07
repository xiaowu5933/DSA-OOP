#include <bits/stdc++.h>

struct Info {
	std::string sFullName;
	double dMath, dLiterature;
	
	void input() {
		std::cin.ignore();
		std::getline(std::cin, sFullName);
		std::cin >> dMath >> dLiterature;
	}

	void out() {
		std::cout << sFullName;
	}

	double ComputeAverageOfStudent() {
		return (dMath + dLiterature) / 2.0;
	}
};

struct Class {
	double dAverage;
	int NumberOfStudents;
	std::vector<Info> students;

	void AddStudent(const Info &lhs) {
		++NumberOfStudents;
		students.push_back(lhs);
	}

	void ComputeAverageOfClass() {
		for (auto v : students) {
			dAverage += v.ComputeAverageOfStudent();
		}
		dAverage /= double(NumberOfStudents);
	}

	void FindAllHighestInClass() {
		double dMx = 0;
		for (auto v : students) {
			if (v.ComputeAverageOfStudent() > dMx) {
				dMx = v.ComputeAverageOfStudent();
			}
		}
		std::cout << "Hoc sinh co diem trung binh cao nhat lop la : \n";
		for (auto v : students) {
			if (v.ComputeAverageOfStudent() == dMx) {
				v.out();
				std::cout << "\n";
			}
		}
	}

	void FindAllStudentLessThanAverage() {
		std::vector<Info> a;
		for (auto v : students) {
			if (v.ComputeAverageOfStudent() < dAverage) {
				a.push_back(v);
			}
		}
		if (a.size()) {
			std::cout << "Nhung hoc sinh co diem trung binh thap hon diem trung binh chung cua lop la : \n";
			for (auto v : a) {
				v.out();
				std::cout << "\n";
			}
		} else {
			std::cout << "Khong co hoc sinh co diem trung binh thap hon diem trung binh chung cua lop\n";
		}
	}
};

int main() {
	Class cl; // Khai bao 1 lop hoc

	int n;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		Info student;
		student.input();
		cl.AddStudent(student);
	}

	// Tinh diem trung binh ca lop
	cl.ComputeAverageOfClass();

	// Tim nhung hoc sinh co diem trung binh nhat lop
	cl.FindAllHighestInClass();

	// Tim nhung hoc sinh co diem trung binh thap hon diem trung binh chung cua lop
	cl.FindAllStudentLessThanAverage();
}
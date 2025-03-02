#include "database.hpp"
#include <iostream>

Database::Database() {};

bool Database::add(const Student& student) {
	if (std::find(students_.begin(), students_.end(), student) == students_.end()) {
		students_.push_back(student);
		return true;
	}
	else 
		return false;

};

void Database::show() {
	for (auto student : students_) {
		std::cout << student.StudentData() << std::endl;
	}
}

std::string Database::show(Student& student) {
	return student.StudentData();
}
#pragma once
#include "student.hpp"
#include <vector>

class Database {
private:
	std::vector<Student> students_;
public:
	Database();

	bool add(const Student& student);
	void show();
	std::string show(Student& student);
};
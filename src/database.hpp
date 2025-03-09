#pragma once
#include "student.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

class Database {
private:
	std::vector<Student> students_;
public:
	Database();

	bool add(const Student& student);
	void show();
	std::string show(Student& student);
	bool erase(int index);

	template <typename Getter>
	Student search(Getter getter, const std::string& value) {
		for (const auto& student : students_) {
			if ((student.*getter)() == value) // Wywo³ujemy getter
				return student;
		}
		std::cout << "Student not found";
	}

	template <typename Getter>
	void sort(Getter getter) {
		std::sort(students_.begin(), students_.end(), 
			[&getter](const Student& a, const Student& b) {
				return (a.*getter)() < (b.*getter)();
			});
	}

};
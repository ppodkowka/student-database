#include "database.hpp"
#include <iostream>

Database::Database() {};

bool Database::add(const Student& student) 
{
	if (std::find(students_.begin(), students_.end(), student) == students_.end()) 
	{
		students_.push_back(student);
		return true;
	}
	else return false;
};

void Database::show() 
{
	int index = 1;
	for (auto student : students_) 
	{
		std::cout <<index << ": " << student.StudentData() << std::endl;
		index++;
	}
}

std::string Database::show(Student& student) 
{
	return student.StudentData();
}

bool Database::erase(int index) 
{
    auto it = std::find_if(students_.begin(), students_.end(),
        [index](const Student& student) {
            return student.getIndex() == index;
        });

    if (it != students_.end()) 
	{
        students_.erase(it);
        return true;
    }
    return false;
}
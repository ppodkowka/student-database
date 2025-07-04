#include "student.hpp"
#include <iostream>

std::unordered_map<Gender, std::string> genderToStringMap 
{
	{Gender::Male, "Male"},
	{Gender::Female, "Female"}
};


Student::Student(const std::string& name, std::string surname, std::string address, int index, std::string pesel,Gender gender)
				: name_(name)
				, surname_(surname)
				, address_(address)
				, index_(index)
				, pesel_(pesel)
				, gender_(gender)
{}

std::string Student::getName() const { return name_; }
std::string Student::getSurname() const { return surname_; }
std::string Student::getAddress() const { return address_; }
int Student::getIndex() const { return index_; }
std::string Student::getPesel() const { return pesel_; }
Gender Student::getGender() const { return gender_; }

std::string Student::StudentData() 
{
	std::string str = name_ + " " +
					  surname_ + " " +
					  address_ + " " +
					  std::to_string(index_) + " " +
					  pesel_ + " " +
					  genderToStringMap[gender_];

	return str;
}


#pragma once
#include <string>
#include <unordered_map>

enum class Gender {
	Male,
	Female
};

class Student {
private:
	std::string name_;
	std::string surname_;
	std::string address_;
	int index_;
	std::string pesel_;
	Gender gender_;

public:
	Student(const std::string& name, std::string surname, std::string address, int index, std::string pesel,
		Gender gender);

	auto operator<=>(const Student& other) const = default;

	// in cpp 17:
	//bool operator==(const Student& other) const {
	//	return name_ == other.name_ &&
	//		surname_ == other.surname_ &&
	//		address_ == other.address_ &&
	//		index_ == other.index_ &&
	//		pesel_ == other.pesel_ &&
	//		gender_ == other.gender_;
	//}

	std::string getName() const;
	std::string getSurname() const;
	std::string getAddress() const;
	int getIndex() const;
	std::string getPesel() const;
	Gender getGender() const;

	std::string StudentData();
};
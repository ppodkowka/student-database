#include <gtest/gtest.h>
#include "student.hpp"
#include "database.hpp"

class DatabaseTest : public ::testing::Test {
protected:
	void SetUp() override {
		student = std::make_unique<Student>("Adam",
											"Kowalski",
											"ul. Spokojna 21",
											401037,
											"930415081",
											Gender::Male);

		student2 = std::make_unique<Student>("Zenon",
											 "Wazon",
											 "ul. Dluga 21",
											 301037,
											 "9204545081",
											 Gender::Male);

		database= std::make_unique<Database>();
	}

	std::unique_ptr<Database> database;
	std::unique_ptr<Student> student;
	std::unique_ptr<Student> student2;
};

TEST_F(DatabaseTest, CanStoreStudentRecords) {
	EXPECT_EQ(student->getName(), "Adam");
	EXPECT_EQ(student->getSurname(), "Kowalski");
	EXPECT_EQ(student->getGender(), Gender::Male);
}

TEST_F(DatabaseTest, CanAddStudentToDatabase) {
	EXPECT_TRUE(database->add(*student));
	EXPECT_FALSE(database->add(*student));
	EXPECT_TRUE(database->add(*student2));
}

TEST_F(DatabaseTest, CanShowDatabase) {
	EXPECT_TRUE(database->add(*student));
	EXPECT_TRUE(database->add(*student2));
	EXPECT_EQ(database->show(*student), "Adam Kowalski ul. Spokojna 21 401037 930415081 Male");
	database->show();
}

TEST_F(DatabaseTest, CanSearchBySurnameOrPesel) {
	EXPECT_TRUE(database->add(*student));
	EXPECT_TRUE(database->add(*student2));
	EXPECT_EQ(database->search(&Student::getSurname, "Wazon"), *student2);
	EXPECT_NE(database->search(&Student::getSurname,"Kowalski"), *student2);
	EXPECT_EQ(database->search(&Student::getPesel,"930415081"), *student);
}

TEST_F(DatabaseTest, CanSortBySurnameOrPesel) {
	EXPECT_TRUE(database->add(*student));
	EXPECT_TRUE(database->add(*student2));
	
	database->sort(&Student::getSurname);
	database->show();

	database->sort(&Student::getPesel);
	database->show();
}

TEST_F(DatabaseTest, CanErase) {
	EXPECT_TRUE(database->add(*student));
	EXPECT_TRUE(database->add(*student2));
	EXPECT_TRUE(database->erase(401037));
	EXPECT_FALSE(database->erase(401037));
}
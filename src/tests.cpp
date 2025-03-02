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
											 "9304545081",
											 Gender::Male);

		database= std::make_unique<Database>();
	}

	std::unique_ptr<Database> database;
	std::unique_ptr<Student> student;
	std::unique_ptr<Student> student2;
};

TEST_F(DatabaseTest, CanGetStudentName) {
	EXPECT_EQ(student->getName(), "Adam");
}

TEST_F(DatabaseTest, CanAddStudentToDatabase) {
	EXPECT_TRUE(database->add(*student));
}

TEST_F(DatabaseTest, CanShowDatabase) {
	EXPECT_TRUE(database->add(*student));
	EXPECT_EQ(database->show(*student), "Adam Kowalski ul. Spokojna 21 401037 930415081 Male");
}
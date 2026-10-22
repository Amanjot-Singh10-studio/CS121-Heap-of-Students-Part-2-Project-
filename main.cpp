#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include "date.h"
#include "address.h"
#include "student.h"

void loadStudents(std::vector<Student*>& students);
void printStudents(std::vector<Student*>& students);
void showStudentNames(std::vector<Student*>& students);
void findStudent(std::vector<Student*>& students);
void delStudents(std::vector<Student*>& students);
std::string menu();

int main() {
    std::vector<Student*> students;
    loadStudents(students);
    std::string choice = "";
    while (choice != "0") {
        choice = menu();
        if (choice == "1") {
            showStudentNames(students);
        }
        else if (choice == "2") {
            printStudents(students);
        }
        else if (choice == "3") {
            findStudent(students);
        }
        else if (choice == "0") {
            std::cout << "Thank you!"  << std::endl;
        }
        else {
            std::cout << "Invalid choice!" << std::endl;
        }
    }
    delStudents(students);
    return 0;
}

void loadStudents(std::vector<Student*>& students) {
    std::ifstream file("students.csv");
    if (!file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        if (line != "") {
            Student* student = new Student();
            (*student).init(line);
            students.insert(students.end(), student);
        }
    }
    file.close();
}

void printStudents(std::vector<Student*>& students) {
    for (int i = 0; i < students.size(); i++) {
	Student* student = students[i]; 
        (*student).printStudent();
        std::cout << "------------------------" << std::endl;
    }
}

void showStudentNames(std::vector<Student*>& students) {
    for (int i = 0; i < students.size(); i++) {
        std::cout << (*students[i]).getLastFirst()
                  << std::endl;
    }
}

void findStudent(std::vector<Student*>& students) {
    std::string lastName;
    std::cout << "Last name of student: ";
    std::getline(std::cin, lastName);
    bool found = false;
    for (int i = 0; i < lastName.length(); i++) {
        lastName[i] = std::tolower(lastName[i]); 
    }
    for (int i = 0; i < students.size(); i++) {
	Student* student = students[i]; 
        std::string name = (*student).getLastName(); 
        for (int j = 0; j < name.length(); j++) {
            name[j] = std::tolower(name[j]);
        }
        if (name.find(lastName) != std::string::npos) {
            (*student).printStudent();
            std::cout << "------------------------"
                      << std::endl;
            found = true;
        }
    }
    if (found == false) {
        std::cout << "Student not found!"
                  << std::endl;
    }
}

void delStudents(std::vector<Student*>& students) {
    for (int i = 0; i < students.size(); i++) {
        delete students[i];
    }
    students.clear();
}

std::string menu() {

    std::string choice;
    std::cout << std::endl;
    std::cout << "0) quit" << std::endl;
    std::cout << "1) print all student names" << std::endl;
    std::cout << "2) print all student data" << std::endl;
    std::cout << "3) find a student" << std::endl;
    std::cout << std::endl;
    std::cout << "Please choose 0-3: ";
    std::getline(std::cin, choice);

    return choice;
}


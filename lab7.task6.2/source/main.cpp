#include <iostream>
#include "Dormitory.h"

std::string skip = "\n\n\n\n\n\n\n\n\n\n\n";

void pause() {
    char a;
    std::cout << "Enter 1 to continue!\n";
    std::cin >> a;
    std::cout << skip;
}

void printOptions() {
    std::cout << "Main Menu:\n";
    std::cout << "1: Add Faculty\n";
    std::cout << "2: Add student\n";
    std::cout << "3: Get Faculty Info\n";
    std::cout << "4: Get Dormitory Info\n";
    std::cout << "5: Search student by name\n";
    std::cout << "6: Search students by block number\n";
    std::cout << "7: kick student by name\n";
    std::cout << "8: fine student\n";
    std::cout << "9: quit\n";
}

int getInt() {
    int x;
    std::cout << "\nEnter a block number\n";
    std::cin >> x;
    while(std::cin.fail()) {
        std::cout << "\nBlock num can't be a string, try again!\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "Enter a block number\n";
        std::cin >> x;
    }
    return x;
}

void showMenu() {
    bool addedFaculty = false;
    bool addedStudent = false;
    std::cout << "Welcome to dormitory Database\nChoose Type the name of it: ";
    std::string name;
    std::cin >> name;
    std::shared_ptr<Dormitory> dormitory (new Dormitory(name));
    std::cout << skip;
    while (true) {
        printOptions();
        char choice;
        std::cin >> choice;
        switch(choice) {
            case '1': {
                std::cout << skip;
                std::cout << "Enter a name of a faculty: ";
                std::string name;
                std::cin >> name;
                std::shared_ptr<Faculty> f(new Faculty(name));
                dormitory->addFaculty(f);
                addedFaculty = true;
                std::cout << skip;
                break;
            }
            case '2': {
                if (addedFaculty) {
                    std::cout << skip;
                    std::cout << "Enter a name, surname and third name of a student(through space): ";
                    std::string name, surname, thirdName;
                    std::cin >> name >> surname >> thirdName;
                    dormitory->chooseFaculty();
                    std::shared_ptr<Faculty> faculty;
                    while (true) {
                        char ans;
                        std::cin >> ans;
                        if (ans - '0' >= 0 && ans - '0' < dormitory->getNumOfFaculties()) {
                            faculty = dormitory->getFacultyByIndex(ans - '0');
                            break;
                        } else {
                            std::cout << "\nChoose one of the given numbers:\n\n";
                            dormitory->chooseFaculty();
                        }
                    }
                    auto student = std::shared_ptr<Student>(new Student(name, surname, thirdName, faculty));
                    dormitory->giveRoomToStudent(student);
                    addedStudent = true;
                    std::cout << skip;
                    break;
                } else {
                    std::cout << "\nAdd faculty first, then go here!\n";
                    break;
                }
            }
            case '3': {
                if (addedFaculty) {
                    std::cout << skip;
                    dormitory->chooseFaculty();
                    std::shared_ptr<Faculty> faculty;
                    while (true) {
                        char ans;
                        std::cin >> ans;
                        if (ans - '0' >= 0 && ans - '0' < dormitory->getNumOfFaculties()) {
                            faculty = dormitory->getFacultyByIndex(ans - '0');
                            break;
                        } else {
                            std::cout << "\nChoose one of the given numbers:\n\n";
                            dormitory->chooseFaculty();
                        }
                    }
                    faculty->printFacultyInfo();
                    pause();
                } else {
                    std::cout << skip;
                    std::cout << "Add Faculty First, type in 1 to continue\n";
                    pause();
                }
                break;
            }
            case '4': {
                std::cout << skip;
                dormitory->printAllInfo();
                pause();
                break;
            }
            case '5': {
                if (addedStudent) {
                    std::cout << skip;
                    std::cout << "\nEnter a name, surname and a third name of the student you are looking for\n";
                    std::string name, surname, thirdName;
                    std::cin >> name >> surname >> thirdName;
                    dormitory->getInfoAboutStudent(name, surname, thirdName);
                    pause();
                    break;
                } else {
                    std::cout << skip;
                    std::cout << "Add Student first, type in 1 to continue\n";
                    pause();
                    break;
                }
            }
            case '6': {
                if (addedStudent) {
                    std::cout << skip;
                    int num = getInt();
                    dormitory->getStudentFromBlockNumber(num);
                    pause();
                    break;
                } else {
                    std::cout << skip;
                    std::cout << "Add Student first, type in 1 to continue\n";
                    pause();
                    break;
                }
            }
            case '7': {
                if (addedStudent) {
                    std::cout << skip;
                    std::cout << "\nEnter a name, surname and a third name of the student you want to kick\n";
                    std::string name, surname, thirdName;
                    std::cin >> name >> surname >> thirdName;
                    dormitory->kickStudent(name, surname, thirdName);
                    pause();
                    break;
                } else {
                    std::cout << skip;
                    std::cout << "Add Student first, type in 1 to continue\n";
                    pause();
                    break;
                }
            }
            case '8': {
                std::cout << skip;
                std::cout << "\nEnter a name, surname and a third name of the student you want to kick\n";
                std::string name, surname, thirdName;
                std::cin >> name >> surname >> thirdName;
                auto student = dormitory->getStudent(name, surname, thirdName);
                if (student != nullptr) {
                    bool mbKick = student->getFined();
                    if (mbKick) {
                        char ans;
                        bool flag = false;
                        while (!flag) {
                            std::cout << "\nStudent has got more than three warnings, maybe you wanna kick him?\n1.Yes\n2.No\n";
                            std::cin >> ans;
                            switch (ans) {
                                case '1': {
                                    dormitory->kickStudent(name, surname, thirdName);
                                    flag = true;
                                    break;
                                }
                                case '2': {
                                    std::cout << "\nOk, let him breeze\n";
                                    flag = true;
                                    break;
                                }
                                default: {
                                    std::cout << "\nType in 1 or 2, nothing else\n";
                                    break;
                                }
                            }
                        }
                        pause();
                    } else {
                        std::cout << "\nHe is ok, less then 3 fines.\n";
                        pause();
                    }
                } else {
                    std::cout << "\nStudent named: " << name << " " << surname << " " << thirdName << " doesn't exist\n";
                    pause();
                }
                break;
            }
            case '9': {
                return;
            }
            default:
                std::cout << skip;
                break;
        }
    }
}

int main() {
    showMenu();
    return 0;
}
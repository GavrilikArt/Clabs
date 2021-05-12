//
// Created by apple on 5/10/21.
//

#include "Dormitory.h"
#include <iostream>

#include <utility>

Dormitory::Dormitory(std::string name) {
    this->name = std::move(name);
}

void Dormitory::addFaculty(std::shared_ptr<Faculty>& faculty) {
    faculties.push_back(faculty);
    faculty->number = faculties.size();
}

void Dormitory::addStudentToAll(const std::shared_ptr<Student>& student) {
    this->allStudents[student->getHash()] = student;
}

void Dormitory::giveRoomToStudent(const std::shared_ptr<Student>& student) {
    auto f = student->getFaculty();
    f->settleStudent(student);
    addStudentToAll(student);
}

void Dormitory::getInfoAboutStudent(std::string name, std::string surname, std::string thirdName) const {
    std::hash<std::string> hash;
    std::shared_ptr<Student> student = allStudents[hash(name + surname + thirdName)];
    if (student != nullptr) {
        student->printStudentsInfo();
    } else {
        std::cout << "\nNo student named: " << name << " " << surname << " " << thirdName << "\n";
    }
}

void Dormitory::chooseFaculty() const {
    if (faculties.empty()) {
        std::cout << "\nNo Faculties Available, first add a faculty!\n";
        return;
    } else {
        std::cout << "\nChoose a faculty\n";
        int count = 0;
        for (const auto& faculty : faculties) {
            std::cout << count << ": " << faculty->name << "\n";
            count++;
        }
    }
}

void Faculty::printFacultyInfo() const {
    std::cout << "\n______________________\n";
    std::cout << this->name << "\n\n\n";
    for (const auto& block : this->blocks) {
        std::cout << "Block number: " << block->num << "\n+++++++++++++++++++++\n";
        for (const auto& student : block->students) {
            student->printStudentsInfo();
        }
        std::cout << "+++++++++++++++++++++\n";
    }
}

void Dormitory::printAllInfo() const {
    for (const auto& faculty : faculties) {
        std::cout << "\n______________________\n";
        std::cout << faculty->name << "\n\n\n";
        for (const auto& block : faculty->blocks) {
            std::cout << "Block number: " << block->num << "\n+++++++++++++++++++++\n";
            for (const auto& student : block->students) {
                student->printStudentsInfo();
            }
            std::cout << "+++++++++++++++++++++\n";
        }
    }
}

void Dormitory::kickStudent(std::string name, std::string surname, std::string thirdName) {
    std::hash<std::string> hash;
    std::shared_ptr<Student> student = allStudents[hash(name + surname + thirdName)];
    if (student != nullptr) {
        auto block = student->block;
        for (auto it = block->students.begin(); it < block->students.end(); ++it) {
            if ((*it)->getHash() == student->getHash()) {
                block->students.erase(it);
                break;
            }
        }
        allStudents[hash(name + surname + thirdName)] = nullptr;
        std::cout << "Student named: " << name << " " << surname << " " << thirdName << " was kicked";
    } else {
        std::cout << "\nNo student named: " << name << " " << surname << " " << thirdName << "\n";
    }
}

void Dormitory::getStudentFromBlockNumber(int blockNum) const {
    if (blockNum / 100 > faculties.size()) {
        std::cout << "\nThis block doesn't exist\n";
        return;
    } else if (blockNum < 100)  {
        std::cout << "\nThis block doesn't exist\n";
        return;
    } else if (blockNum % 100 > faculties[blockNum / 100 - 1]->blocks.size() - 1) {
        std::cout << "\nThis block is empty\n";
        return;
    } else {
        auto block = faculties[blockNum / 100 - 1]->blocks[blockNum % 100];
        block->getBlockInfo();
    }
}

std::shared_ptr<Student> Dormitory::getStudent(std::string name, std::string surname, std::string thirdName) const {
    std::hash<std::string> hash;
    std::shared_ptr<Student> student = allStudents[hash(name + surname + thirdName)];
    if (student != nullptr) {
        return student;
    } else {
        return nullptr;
    }
}

std::shared_ptr<Faculty> Dormitory::getFacultyByIndex(int index) const{
    return faculties[index];
}

int Dormitory::getNumOfFaculties() const {
    return faculties.size();
}

Faculty::Faculty(std::string name) {
    this->name = std::move(name);
}


void Faculty::settleStudent(const std::shared_ptr<Student>& student) {
    if (blocks.empty()) {
        std::shared_ptr<Block> block (new Block(this->number*100 + currentBlock));
        blocks.push_back(block);
    }
    if (blocks[currentBlock]->students.size() > 4) {
        currentBlock++;
        std::shared_ptr<Block> block (new Block(this->number*100 + currentBlock));
        blocks.push_back(block);
    }
    if (blocks.size() > capacity) {
        std::cout << "\nNo more available places\n" << std::endl;
        return;
    }
    blocks[currentBlock]->students.push_back(student);
    blocks[currentBlock]->num = this->number*100 + currentBlock;
    student->setBlock(blocks[currentBlock]);
}

std::string Faculty::getName() const {
    return this->name;
}

Student::Student(const std::string& name, const std::string& surname, const std::string& thirdName, std::shared_ptr<Faculty> faculty) {
    this->name = name;
    this->surname = surname;
    this->thirdName = thirdName;
    this->faculty = std::move(faculty);
    this->fineCount = 0;
    std::hash<std::string> hash;
    this->studentHash = hash(name + surname + thirdName);
    this->block = nullptr;
}

size_t Student::getHash() {
    return this->studentHash;
}

std::shared_ptr<Faculty> Student::getFaculty() {
    return this->faculty;
}

void Student::setBlock(std::shared_ptr<Block> block) {
    this->block = block;
}

void Student::printStudentsInfo() const {
    std::cout << "\n";
    std::cout << "Student: " << this->name << " " << surname << " " << thirdName << "\n";
    std::cout << "Faculty: " << faculty->getName() << "\n";
    std::cout << "Block's number: " << block->num << "\n\n";
}

bool Student::getFined() {
    fineCount++;
    if (fineCount >= 3) {
        return true;
    } else {
        return false;
    }
}

Block::Block(short num) {
    this->num = num;
}

void Block::getBlockInfo() {
    std::cout << "Block number: " << num << "\n";
    for (const auto& student : students) {
        student->printStudentsInfo();
    }
}


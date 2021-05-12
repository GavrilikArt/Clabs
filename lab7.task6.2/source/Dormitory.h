//
// Created by apple on 5/10/21.
//

#ifndef LAB7_TASK6_2_DORMITORY_H
#define LAB7_TASK6_2_DORMITORY_H
#include <vector>
#include <string>
#include <unordered_map>

class Dormitory;
class Block;
class Faculty;

class StuffMember {

};

class Student {
public:
    friend class Faculty;
    friend class Dormitory;
    Student(const std::string& name, const std::string& surname, const std::string& thirdName, std::shared_ptr<Faculty> faculty);
    size_t getHash();
    bool getFined();
    std::shared_ptr<Faculty> getFaculty();
    void setBlock(std::shared_ptr<Block> block);
    void printStudentsInfo() const;
private:
    std::string name;
    std::string surname;
    std::string thirdName;
    unsigned short int fineCount;
    std::shared_ptr<Block> block;
    std::shared_ptr<Faculty> faculty;
    size_t studentHash;
};

class Block {
public:
    friend class Faculty;
    friend class Dormitory;
    friend class Student;
    Block(short int num);
    void getBlockInfo();
    std::vector<std::shared_ptr<Student> > students;
private:
    unsigned short int num;
};

class Faculty {
public:
    friend class Dormitory;
    Faculty(std::string name);
    std::string getName() const;
    void settleStudent(const std::shared_ptr<Student>& student);
    void printFacultyInfo() const;
    const short int capacity = 25;
private:
    unsigned short int currentBlock = 0;
    std::vector<std::shared_ptr<Block> > blocks;
    std::string name;
    short int number;
};

class Dormitory {
public:
    int getNumOfFaculties() const;
    std::shared_ptr<Faculty> getFacultyByIndex(int index) const;
    explicit Dormitory(std::string name);
    void kickStudent(std::string name, std::string surname, std::string thirdName);
    void getStudentFromBlockNumber(int blockNum) const;
    void addFaculty(std::shared_ptr<Faculty>& faculty);
    void addStudentToAll(const std::shared_ptr<Student>& student);
    void giveRoomToStudent(const std::shared_ptr<Student>& student);
    void chooseFaculty() const;
    std::shared_ptr<Student> getStudent(std::string name, std::string surname, std::string thirdName);
    void getInfoAboutStudent(std::string name, std::string surname, std::string thirdName);
    void printAllInfo() const;
private:
    std::unordered_map<size_t, std::shared_ptr<Student> > allStudents;
    std::string name;
    std::vector<std::shared_ptr<Faculty> > faculties;
};


#endif //LAB7_TASK6_2_DORMITORY_H

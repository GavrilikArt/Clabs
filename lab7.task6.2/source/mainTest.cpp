#include "Dormitory.h"
#include <assert.h>

void test() {
    std::shared_ptr<Dormitory> d(new Dormitory("D"));
    std::shared_ptr<Faculty> f(new Faculty("F"));
    std::shared_ptr<Faculty> f1(new Faculty("F1"));
    std::shared_ptr<Faculty> f2(new Faculty("F2"));
    d->addFaculty(f);
    d->addFaculty(f1);
    d->addFaculty(f2);
    std::shared_ptr<Student> s(new Student("a", "a", "a", f));
    std::shared_ptr<Student> s1(new Student("b", "b", "b", f));
    std::shared_ptr<Student> s2(new Student("c", "c", "c", f));
    std::shared_ptr<Student> s3(new Student("d", "d", "d", f));
    std::shared_ptr<Student> s4(new Student("e", "e", "e", f));
    std::shared_ptr<Student> s5(new Student("f", "f", "f", f));
    std::shared_ptr<Student> s6(new Student("g", "g", "g", f1));
    std::shared_ptr<Student> s7(new Student("a", "b", "b", f1));
    std::shared_ptr<Student> s8(new Student("a", "c", "c", f1));
    std::shared_ptr<Student> s9(new Student("a", "d", "d", f1));
    std::shared_ptr<Student> s10(new Student("a", "e", "e", f1));
    std::shared_ptr<Student> s11(new Student("a", "f", "f", f1));
    std::shared_ptr<Student> s12(new Student("a", "g", "g", f1));
    std::shared_ptr<Student> s13(new Student("g", "n", "g", f2));
    std::shared_ptr<Student> s14(new Student("a", "n", "b", f2));
    std::shared_ptr<Student> s15(new Student("a", "da", "c", f2));
    std::shared_ptr<Student> s16(new Student("a", "nd", "d", f2));
    std::shared_ptr<Student> s17(new Student("a", "g", "e", f2));
    std::shared_ptr<Student> s18(new Student("a", "wfa", "f", f2));
    std::shared_ptr<Student> s19(new Student("a", "af", "g", f2));
    d->giveRoomToStudent(s);
    d->giveRoomToStudent(s1);
    d->giveRoomToStudent(s2);
    d->giveRoomToStudent(s3);
    d->giveRoomToStudent(s4);
    d->giveRoomToStudent(s5);
    d->giveRoomToStudent(s6);
    d->giveRoomToStudent(s7);
    d->giveRoomToStudent(s8);
    d->giveRoomToStudent(s9);
    d->giveRoomToStudent(s10);
    d->giveRoomToStudent(s11);
    d->giveRoomToStudent(s12);
    d->giveRoomToStudent(s13);
    d->giveRoomToStudent(s14);
    d->giveRoomToStudent(s15);
    d->giveRoomToStudent(s16);
    d->giveRoomToStudent(s17);
    d->giveRoomToStudent(s18);
    d->giveRoomToStudent(s19);
    int a = d->getNumOfFaculties();
    assert(a == 3);
    assert(d->getFacultyByIndex(0) == f);
    d->getStudentFromBlockNumber(101);
    d->getStudentFromBlockNumber(1);
    d->getStudentFromBlockNumber(10000);
    d->chooseFaculty();
    d->getInfoAboutStudent("a", "a", "a");
    d->getInfoAboutStudent("afafaf", "afaffa", "afaafa");
    auto student = d->getStudent("a", "a", "a");
    d->getStudent("aljf", "afllaf", "lafjja");
    d->printAllInfo();
    f->printFacultyInfo();
    auto name = f->getName();
    student->getFined();
    student->getFined();
    student->getFined();
    student->getFined();
    d->kickStudent("a", "a", "a");
    d->kickStudent("aafljalf", "alfaljfaf", "lll1ja");
}

#undef main
int main() {
    test();
    return 0;
}
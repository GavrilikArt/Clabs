//
// Created by apple on 4/21/21.
//

#ifndef LAB5_TASK5_1_MAIN_H
#define LAB5_TASK5_1_MAIN_H

#include <vector>
#include <list>
#include <string>

std::list<int> LongMulLong(std::list<int> left, std::list<int> right);
std::list<int> LongAddLong(std::list<int> left, std::list<int> right);
std::vector<int> LongSubLong(std::vector<int> first_number, std::vector<int> second_number);
std::vector<int> LongDivLong(std::vector<int> first_number, std::vector<int> second_number);
std::vector<int> convert(std::string number);
std::list<int> castStrToList(std::string str);
#endif //LAB5_TASK5_1_MAIN_H

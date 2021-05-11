#include <iostream>
#include "main.h"
#include <list>
#include <string>
#include <vector>
using namespace std;

std::list<int> castStrToList(std::string str) {
  std::list<int> ans;
  for (int i = 0; i < str.size(); ++i) {
    ans.push_back(str[i] - '0');
  }
  return ans;
}

std::list<int> LongAddLong(std::list<int> left, std::list<int> right) {
  int rank1 = left.size();
  int rank2 = right.size();
  if (rank1 < rank2) {
    for (int i = 0; i < rank2 - rank1; ++i) {
      left.push_front(0);
    }
  } else if (rank1 > rank2) {
    for (int i = 0; i < rank1 - rank2; ++i) {
      right.push_front(0);
    }
  }
  std::list<int> ans;
  int add = 0;
  auto i = --left.end();
  for (auto j = --right.end(); j != --right.begin(); --i, --j) {
    int leftDig = *i;
    int rightDig = *j;
    short int sum = leftDig + rightDig + add;
    if (sum > 9) {
      sum -= 10;
      add = 1;
    } else add = 0;
    ans.push_front(sum);
  }
  if (rank1 == rank2) {
    if (add == 1) {
      ans.push_front(1);
    }
  } else {
    if (add == 1) {
      ans.push_front(*(i++) + 1);
    }
    for (; i != --left.begin(); --i) {
      ans.push_front(*i);
    }
  }
  return ans;
}

std::list<int> multiplyByOneDigit(std::list<int> number, int digit) {
  std::list<int> ans;
  int add = 0;
  for (auto it = --number.end(); it != --number.begin(); it--) {
    auto temp = *it;
    ans.push_front(((*it) * digit + add) % 10);
    add = (digit * (*it) + add) / 10;
  }
  if (add != 0) {
    ans.push_front(add);
  }
  return ans;
}

std::list<int> LongMulLong(std::list<int> left, std::list<int> right) {
  std::list<int> ans;
  std::list<int> middle;
  std::list<int> biggerNum;
  std::list<int> smallerNum;
  biggerNum = left.size() >= right.size() ? left : right;
  if (biggerNum == left) {
    smallerNum = right;
  } else {
    smallerNum = left;
  }
  int count = 0;
  for (auto it = --smallerNum.end(); it != --smallerNum.begin(); it--) {
    middle = multiplyByOneDigit(biggerNum, *it);
    int j = 0;
    while (j < count) {
      middle.push_back(0);
      ++j;
    }
    count++;
    if (!ans.empty()) {
      ans = LongAddLong(middle, ans);
    } else {
      ans = middle;
    }
  }
  return ans;
}

vector<int> convert(string number) {
  vector <int> convert_number;
  for (int i = number.size() - 1; i >= 0; i--) {
    convert_number.push_back(number[i] - '0');
  }
  return convert_number;
}
void remove_leading_zeros(vector<int>& number) {
  while (number.size() > 0 && number.back() == 0) {
    number.pop_back();
  }
  if (number.size() == 0) {
    number.push_back(0);
  }
}
vector<int> LongSubLong(vector<int> first_number, vector<int> second_number) {
  for (size_t i = 0; i < first_number.size(); i++) {
    if (i < second_number.size()) {
      first_number[i] -= second_number[i];
    }
    if (first_number[i] < 0) {
      first_number[i] += 10;
      first_number[i + 1]--;
    }
  }
  remove_leading_zeros(first_number);
  return first_number;
}

vector<int> multiplication(vector<int> first_number, vector<int> second_number)  {
  vector<int> answer(first_number.size() + second_number.size(), 0);
  for (size_t i = 0; i < first_number.size(); i++) {
    int carry = 0;
    for (size_t j = 0; j < second_number.size() || carry; j++) {
      long long add = 0;
      if (j < second_number.size()) {
        add = 1ll * first_number[i] * second_number[j];
      }
      long long temp = answer[i + j] + add + carry;
      answer[i + j] = temp % 10;
      carry = temp / 10;
    }
  }
  remove_leading_zeros(answer);
  return answer;
}

vector<int> multiplication_by_int(vector<int> number, int mid) {
  vector<int> temp;
  temp.push_back(mid);
  return multiplication(number, temp);
}

bool less_or_equal(vector<int> first_number, vector<int> second_number) {
  if (second_number.size() > first_number.size()) {
    return true;
  }
  if (first_number.size() > second_number.size()) {
    return false;
  }
  for (int i = second_number.size() - 1; i >= 0; i--) {
    if (second_number[i] != first_number[i]) {
      return first_number[i] < second_number[i];
    }
  }
  return true;
}

vector<int> LongDivLong(vector<int> first_number, vector<int> second_number) {
  vector<int> current;
  string answer;

  for (int i = first_number.size() - 1; i >= 0; i--) {
    current.insert(current.begin(), first_number[i]);
    remove_leading_zeros(current);
    int l = 0, r = 10;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      vector<int> temp = multiplication_by_int(second_number, mid);

      if (less_or_equal(temp, current)) {
        l = mid;
      }
      else {
        r = mid;
      }
    }
    answer += char(l + '0');
    vector <int> temp = multiplication_by_int(second_number, l);
    current = LongSubLong(current, temp);
  }
  vector <int> result = convert(answer);
  remove_leading_zeros(result);
  return result;
}


int main(int argc, char** argv) {
  std::string a, b;
  std::cin >> a >> b;
  vector<int> va = convert(a);
  vector<int> vb = convert(b);
  for (auto i : LongMulLong(castStrToList(a), castStrToList(b))) {
    std::cout << i;
  }
  std::cout << "\n";
  vector<int> vec = LongSubLong(va, vb);
  reverse(vec.begin(), vec.end());
  for (auto i : vec) {
    std::cout << i;
  }
  std::cout << "\n";
  for (auto i : LongAddLong(castStrToList(a), castStrToList(b))) {
    std::cout << i;
  }
  std::cout << "\n";
  vector<int> vec1 = LongDivLong(va, vb);
  reverse(vec1.begin(), vec1.end());
  for (auto i : vec1) {
    std::cout << i;
  }

  return 0;
}
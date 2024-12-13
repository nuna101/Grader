#include <cassert>
#include <vector>
#include <iostream>
#include <string>
#include "list.h"
#include "student.h"

using std::cin;
using std::cout;
using std::string;

template <typename T>
void test() {
  int repeat;
  int n;
  CP::list<CP::list<T>> la,lb;

  cin >> repeat;

  //read one list
  la.push_back(CP::list<T>());
  cin >> n;
  for (int j = 0;j < n;j++) {
    T tmp;
    cin >> tmp;
    la.back().push_back(tmp);
  }
  //read b list
  int b;
  cin >> b;
  for (int i = 0;i < b;i++) {
    lb.push_back(CP::list<T>());
    cin >> n;
    for (int j = 0;j < n;j++) {
      T tmp;
      cin >> tmp;
      lb.back().push_back(tmp);
    }
  }

  while (repeat > 0) {
    la.front().merge(lb);
    lb.front().merge(la);
    if (repeat == 1) {
      cout << "LA\n";
      la.front().print();

      auto it = lb.begin();
      for (int i = 0;i < (int)lb.size();i++) {
        cout << "LB " << i << "\n";
        it->print();
        it++;
      }
    }
    repeat--;
  }
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  int type;
  cin >> type;
  if (type == 0) {
    test<int>();
  } else {
    test<std::string>();
  }

}


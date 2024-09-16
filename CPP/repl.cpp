#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

unordered_map<int , int> um;

int main() {
  int a = 10;

  int pre_num = 100000;
  int post_num = 100000;

  um[4] = 3;

  if (um[4]) {
    cout << "nahi hai0" << endl;
  }

  if (um[3]) {
    cout << "nahi hai -1" << endl;
  }

  if (!um[4]) {
    cout << "nahi hai1" << endl;
  }

  if (!!um[4]) {
    cout << "nahi hai2" << endl;
  }

  if (!um[3]) {
    cout << "nahi hai3" << endl;
  }

  if (!!um[3]) {
    cout << "nahi hai4" << endl;
  }

  string str = to_string(pre_num) + to_string(post_num) ;
  cout << str;
  return 0;
}
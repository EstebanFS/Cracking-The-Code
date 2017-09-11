#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/*
Description: Implement a method to perform basic string compression using the
             counts of repeated characters, asume the string has only uppercase
             and lowercase letters.

Time Complexity: O(n)
Space Complexity: O(n)
*/

template <class T> string toStr(T &x) {
  stringstream ss;
  ss << x;
  return ss.str();
}

#define ASCII 128

string compression(string &x) {
  x += ' ';
  string ans;
  char lastChar = x[0];
  int countLastChar = 1;
  for(int i = 1; i < x.size(); ++i) {
    char currChar = x[i];
    if(currChar == lastChar) {
      countLastChar++;
      continue;
    } else {
      ans += (lastChar + toStr(countLastChar));
      lastChar = currChar;
      countLastChar = 1;
    }
  }
  if(ans.size() > (x.size() - 1)) ans = x;
  return ans;
}

int main() {
  string word;
  while(cin >> word) cout << compression(word) << endl;
}

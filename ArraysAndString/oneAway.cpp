#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

/*
Description: Given two strings, write a function to check if they are one edit
             (or zero) away. One edit means: insert, remove or replace one
             character.
Time Complexity: O(n)
Space Complexity: O(n)
*/

#define ASCII 128

bool isOneRemovingAway(string &x, string &y) {
  int indexX = 0, indexY = 0;
  while(indexX < x.size() && indexY < y.size()) {
    if(x[indexX] != y[indexY]) {
      if(indexX != indexY) return false;
      indexX++;
    } else {
      indexX++;
      indexY++;
    }
  }
  return true;
}

bool isOneReplaceAway(string &x, string &y) {
  int diff = 0;
  for(int i = 0; i < x.size(); ++i) {
    if(x[i] != y[i]) diff++;
    if(diff > 1) return false;
  }
  return true;
}

bool isOneAway(string &x, string &y) {
  if(abs((int)x.size() - (int)y.size()) > 1) return false;
  if(x.size() == y.size() && isOneReplaceAway(x, y)) return true;
  return isOneRemovingAway(x, y) || isOneRemovingAway(y, x);
}

int main() {
  string x, y;
  while(cin >> x >> y) cout << isOneAway(x, y) << endl;
}

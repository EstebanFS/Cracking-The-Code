#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Description: Given two strings, write a method to decide if one is a
permutation of the other.

Time Complexity: O(n)
Space Complexity: O(n)
*/

#define ASCII 128

bool checkPermutation(string &x, string &y) {
  if(x == y) return false;
  vector<int> frequencyX(ASCII, 0);
  vector<int> frequencyY(ASCII, 0);
  for(int i = 0; i < x.size(); ++i) {
    int currChar = x[i];
    frequencyX[currChar]++;
  }
  for(int i = 0; i < y.size(); ++i) {
    int currChar = y[i];
    frequencyY[currChar]++;
  }
  for(int i = 0; i < ASCII; ++i) {
    if(frequencyY[i] != frequencyX[i]) return false;
  }
  return true;
}

int main() {
  string x, y;
  while(cin >> x >> y) cout << checkPermutation(x, y) << endl;
}

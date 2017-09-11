#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Description: Given two strings, write a function to check if they are one edit
             (or zero) away. One edit means: insert, remove or replace one
             character.
Time Complexity: O(n)
Space Complexity: O(n)
*/

#define ASCII 128

/*bool oneWay(string &x, string &y) {
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
  int diff = 0;
  for(int i = 0; i < ASCII; ++i) {
    diff += abs(frequencyX[i] - frequencyY[i]);
  }
  return diff <= 1;
}*/

int main() {
  string x, y;
  while(cin >> x >> y) cout << oneWay(x, y) << endl;
}

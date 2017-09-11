#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Description: Implement and algorithm to determine if a string has all unique
characters. What if you cannot use additional data structures.?

Time Complexity: O(n)
Space Complexity: O(n)
*/

#define ASCII 128

bool isUnique(string &word) {
  vector<int> frequency(ASCII, 0);
  for(int i = 0; i < word.size(); ++i) {
    int currChar = word[i];
    frequency[currChar]++;
    if(frequency[currChar] > 1) return false;
  }
  return true;
}

int main() {
  string x;
  while(cin >> x) cout << isUnique(x) << endl;
}

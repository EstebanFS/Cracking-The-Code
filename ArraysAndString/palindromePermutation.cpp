#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <ctype.h>

using namespace std;

/*
Description: Given a string, write a function to check if it is a permutation
             of a palindrome.
Time Complexity: O(n)
Space Complexity: O(n)
*/

#define ASCII 128

bool checkPalindromePermutation(string &x) {
  vector<int> frequency(ASCII, 0);
  for(int i = 0; i < x.size(); ++i) {
    int currChar = tolower(x[i]);
    if(currChar == ' ') continue;
    frequency[currChar]++;
  }
  int oddNumber = 0;
  for(int i = 0; i < ASCII; ++i) {
    if(frequency[i] % 2 == 1) oddNumber++;
    if(oddNumber > 1) return false;
  }
  return true;
}

int main() {
  string line;
  while(getline(cin, line)) cout << checkPalindromePermutation(line) << endl;
}

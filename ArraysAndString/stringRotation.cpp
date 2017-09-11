#include <iostream>
#include <string>

using namespace std;

/*
Description: Given two strings s1 and s2, write code to check if s2 is a
             rotation of s1 using only one call to isSubstring;

Time Complexity: O(n) //Assumming isSubstring is O(n)}
Space Complexity: O(n)
*/

bool isSubstring(string &x, string &y) {
  size_t found = x.find(y);
  return (found != string::npos);
}

bool isARotation(string &x, string &y) {
  string searchString = x + x;
  return isSubstring(searchString, y);
}


int main() {
  string x, y;
  while(cin >> x >> y) cout << isARotation(x, y) << endl;
}

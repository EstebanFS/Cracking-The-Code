#include <iostream>
#include <string>

using namespace std;

/*
Description: Write a method to replace all spaces in a string with '%20'.

Time complexity: O(n).
Space complexity: O(1).
*/

string URLify(string &x, int &trueLength) {
  string replaceString = "%20", ans;
  for(int i = 0; i < x.size() && i < trueLength; ++i) {
    char currChar = x[i];
    if(currChar == ' ') ans += replaceString;
    else ans += currChar;
  }
  return ans;
}

int main() {
  string x;
  int length;
  getline(cin, x);
  cin >> length;
  cout << URLify(x, length) << endl;
}

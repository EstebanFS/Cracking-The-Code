#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
  Description: Write an algorithm such that if an element in an MxN matrix is 0,
               its entire row and column are set to 0.

  Time Complexity: O(n * n)
  Space Complexity: O(n)
*/

void fillColumns(vector<string> &m, vector<bool> &zero) {
  int rowSize = m.size();
  for(int i = 0; i < zero.size(); ++i) {
    if(zero[i]) {
      for(int j = 0; j < rowSize; ++j) m[j][i] = '0';
    }
  }
}

void fillRows(vector<string> &m, vector<bool> &zero) {
  int columnSize = m[0].size();
  for(int i = 0; i < zero.size(); ++i) {
    if(zero[i]) {
      for(int j = 0; j < columnSize; ++j) m[i][j] = '0';
    }
  }
}

void convertToZeroM(vector<string> &m) {
  int rowSize = m.size();
  int columnSize = m[0].size();
  vector<bool> zeroRows(rowSize, false);
  vector<bool> zeroColumns(columnSize, false);
  for(int i = 0; i < rowSize; ++i) {
    for(int j = 0; j < columnSize; ++j) {
      if(m[i][j] == '0') {
        zeroRows[i] = zeroColumns[j] = true;
      }
    }
  }
  fillRows(m, zeroRows);
  fillColumns(m, zeroColumns);
}

int main() {
  int n;
  cin >> n;
  vector<string> matrix(n);
  for(int i = 0; i < n; ++i) cin >> matrix[i];
  convertToZeroM(matrix);
  cout << "-----------------" << endl;
  for(int i = 0; i < n; ++i) cout << matrix[i] << endl;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Description: Given a NxN matrix, write method to rotate the image by 90
             degrees.

Time Complexity: O(n * n)
Space Complexity: O(n * n);

Example:

Original Matrix:  1 2 3
                  4 5 6
                  7 8 9

  RotatedMatrix:  7 4 1
                  8 5 2
                  9 6 3
*/

#define D(x) cout << #x << " = " << x << endl

int mirrorEdge(int x, int limit) {
  return abs(limit - x);
}

vector<string> rotateMatrix(vector<string> &m) {
  int rowSize = m.size();
  int columnSize = m[0].size();
  vector<string> rotatedMatrix = m;
  for(int i = 0; i < rowSize; ++i) {
    for(int j = 0; j < columnSize; ++j) {
      int rotatedIndexI = mirrorEdge(i, rowSize - 1);
      rotatedMatrix[j][rotatedIndexI] = m[i][j];
    }
  }
  return rotatedMatrix;
}

int main() {
  int n;
  cin >> n;
  vector<string> matrix(n), rotatedMatrix;
  for(int i = 0; i < n; ++i) cin >> matrix[i];
  rotatedMatrix = rotateMatrix(matrix);
  cout << "--------------" << endl;
  for(int i = 0; i < n; ++i) cout << rotatedMatrix[i] << endl;
}

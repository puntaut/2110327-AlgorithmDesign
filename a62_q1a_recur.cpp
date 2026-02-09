#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void recur(vector<vector<int>> &m, int row, int col, int a, int b) {
    if (a == 0) {
        // cout << "a:" << a << " b:" << b << "\n";
        m[row][col] = b;
        return;
    }
    int len = pow(2, a);
    recur(m, row, col, a-1, b);
    for (int i = 0; i < len/2; i++) {
        for (int j = 0; j < len/2; j++) {
            int x = m[row + i][col + j];
            m[row + i][col + len/2 + j] = x - 1;
            m[row + len/2 + i][col + j] = x + 1;
            m[row + len/2 + i][col + len/2 + j] = x;
        }
    }
}

int main() {
    int a, b;
    cin >> a >> b;
    int n = pow(2,a);
    vector<vector<int>> m(n, vector<int> (n));
    recur(m,0,0,a,b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}

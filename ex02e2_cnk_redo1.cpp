#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> m(n+1, vector<int>(n+1));
    for (int col = 0; col <= k; col++) {
        for (int row = col; row <= col + n-k; row++) {
            if (col == 0 || row == col) m[row][col] = 1;
            else m[row][col] = m[row-1][col] + m[row-1][col-1];
        }
    }
    cout << m[n][k] << "\n";
    
}

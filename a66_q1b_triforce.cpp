#include <iostream>
#include <vector>

using namespace std;

int dog(int a, int b, int c, int d) {
    if (a * b * c == 0 || d != 0) return 0;
    int count[4] = {0};
    count[a]++;
    count[b]++;
    count[c]++;
    if (count[0] != 0) return 0;
    for (int i = 0; i < 4; i++) {
        if (count[i] >= 2) return i;
    }
    return 0;
}

int triforce(vector<vector<int>> &matrix, int a, int b, int len) {
    if (len == 2) {
        return dog(matrix[a][b], matrix[a][b+1], matrix[a+1][b], matrix[a+1][b+1]);
    }
    for (int i = 0; i < (len/2)*(len/2); i++) {
        if (matrix[a + len/2 + i/(len/2)][b + len/2 + i%(len/2)] != 0) return 0;
    }
    // cout << "test\n";
    int x1 = triforce(matrix, a, b, len/2);
    int x2 = triforce(matrix, a, b + len/2, len/2);
    int x3 = triforce(matrix, a + len/2, b, len/2);
    return dog(x1, x2, x3, 0);
}

int main() {
    vector<int> sol(3);
    for (int p = 0; p < 3; p++) {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n);
        for (int i = 0; i < n; i++) {
            matrix[i] = vector<int> (n);
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        sol[p] =triforce(matrix, 0, 0, n);
    }
    for (int i = 0; i < 3; i++) {
        cout << sol[i] << "\n";
    }
}

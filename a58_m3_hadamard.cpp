#include <iostream>
#include <vector>

using namespace std;

void recur(vector<int> &result, vector<int> &v, int row, int col, int len, bool isNeg) {
    if (len == 1) {
        int x = (isNeg) ? -v[col] : v[col];
        if (col == 0) {
            result[row] = x;
            return;
        } else {
            result[row] = result[row] + x;
            return;
        }
    }
    // cout << "test: " << "row:" << row << " col:" << col << "\n";
    recur(result, v, row, col, len/2, isNeg);
    recur(result, v, row+len/2, col+len/2, len/2, !isNeg);
    for (int i = 0; i < len/2; i++) {
        int a = result[row + i];
        int b = result[row + len/2 + i];
        result[row + i] = a - b;
        result[row + len/2 + i] = a + b;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> result(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    recur(result, v, 0, 0, n, false);
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";


}

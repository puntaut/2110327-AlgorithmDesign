#include <iostream>
#include <vector>

using namespace std;

int cnk(vector<vector<int>> &m, int n, int k) {
    if (m[n][k] != -1) {
        return m[n][k];
    } else if (k == 0 || k == n) {
        m[n][k] = 1;
        return 1;
    }
    int r = cnk(m, n-1, k-1) + cnk(m, n-1, k);
    m[n][k] = r;
    return r;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> m(n+1, vector<int>(n+1, -1));
    cout << cnk(m, n, k) << "\n";
}

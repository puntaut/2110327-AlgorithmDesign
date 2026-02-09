#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(vector<int> &s, int i, int j) {
    return (s[j] - s[i-1]);
}

int mcs(vector<int> &s, int a, int b) {
    if (a == b) return sum(s, a, a);
    int m = (a + b) >> 1;
    int mx1 = mcs(s, a, m);
    int mx2 = mcs(s, m+1, b);
    int mx_col = sum(s, a, m);
    int mx_row = sum(s, m+1, m+1);
    for (int i = a + 1; i <= m; i++) {
        if (sum(s, i, m) > mx_col) mx_col = sum(s, i, m);
    }
    for (int j = m + 2; j <= b; j++) {
        if (sum(s, m+1, j) > mx_row) mx_row = sum(s, m+1, j);
    }
    int mx3 = mx_col + mx_row;
    return max(max(mx1, mx2), mx3);
}

int main() {
    int n;
    cin >> n;
    vector<int> s(n+1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s[i] = s[i-1] + x;
    }
    cout << mcs(s, 1, n) << "\n";
}

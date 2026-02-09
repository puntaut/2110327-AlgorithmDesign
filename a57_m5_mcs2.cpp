#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum(vector<int> &s, int i, int j) {
    return s[j] - s[i-1];
}

int max_of_3(int a, int b, int c) {
    return max(max(a, b), c);
}

int min_of_3(int a, int b, int c) {
    return min(min(a, b), c);
}

pair<int,int> mcs(vector<int> &s, int a, int b, int n) {
    if (a == b) return make_pair(sum(s, a, a), sum(s, a, a));
    int m = (a + b) / 2;
    auto p1 = mcs(s, a, m, n);
    auto p2 = mcs(s, m+1, b, n);
    int max1 = p1.first;
    int max2 = p2.first;
    int min1 = p1.second;
    int min2 = p2.second;

    if (b != n) {
        int max_col = sum(s, a, m);
        int min_col = sum(s, a, m);
        for (int i = a + 1; i <= m; i++) {
            max_col = (sum(s, i, m) > max_col) ? sum(s, i, m) : max_col;
            min_col = (sum(s, i, m) < min_col) ? sum(s, i, m) : min_col;
        }
        int max_row = sum(s, m+1, m+1);
        int min_row = sum(s, m+1, m+1);
        for (int j = m + 2; j <= b; j++) {
            max_row = (sum(s, m+1, j) > max_row) ? sum(s, m+1, j) : max_row;
            min_row = (sum(s, m+1, j) < min_row) ? sum(s, m+1, j) : min_row;
        }
        int max3 = max_col + max_row;
        int min3 = min_col + min_row;
        int mx = max_of_3(max1, max2, max3);
        int mn = min_of_3(min1, min2, min3);
        return (make_pair(mx, mn));
    } else {
        int max_col = sum(s, a, m);
        int max_row = sum(s, m+1, m+1);
        for (int i = a + 1; i <= m; i++) {
            max_col = (sum(s, i, m) > max_col) ? sum(s, i, m) : max_col;
        }
        for (int j = m + 2; j <= b; j++) {
            max_row = (sum(s, m+1, j) > max_row) ? sum(s, m+1, j) : max_row;
        }
        int max3 = max_col + max_row;
        int mx = max_of_3(max1, max2, max3);

        int min_col = sum(s, a+1, m);
        int min_row = sum(s, m+1, m+1);
        for (int i = a + 2; i <= m; i++) {
            min_col = (sum(s, i, m) < min_col) ? sum(s, i, m) : min_col;
        }
        for (int j = m + 2; j <= b - 1; j++) {
            min_row = (sum(s, m+1, j) < min_row) ? sum(s, m+1, j) : min_row;
        }
        int fi_col = sum(s, a, m);
        int fi_row = sum(s, m+1, b);

        int min3 = min_of_3(min_col + min_row, fi_col + min_row, min_col + fi_row);
        int mn = min_of_3(min1, min2, min3);
        return (make_pair(mx, mn));
    }

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
    auto p = mcs(s, 1, n, n);
    int mx = p.first;
    int mn = p.second;
    if (n == 2) {
        cout << mx << "\n";
    } else {
        cout << max(mx, sum(s,1,n) - mn) << "\n";
    }
}

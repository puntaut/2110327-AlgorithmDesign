#include <iostream>
#include <vector>

using namespace std;

void bsn(vector<int> &v, int a, int b, int k, int &ans) {
    int m = (a + b) >> 1;
    if (a == b) {
        // cout << "1";
        if (v[a] <= k) ans = v[a];
        return;
    }
    if (v[m] <= k) {
        ans = v[m];
        // cout << "2";
        bsn(v, m + 1, b, k, ans);
    } else {
        // cout << "3";
        bsn(v, a, m, k, ans);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; i++) {
        int e;
        cin >> e;
        v.push_back(e);
    }
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        int ans = -1;
        bsn(v, 0, n - 1, q, ans);
        cout << ans << "\n";
    }
}

#include <iostream>
#include <vector>

using namespace std;

void bsnr(vector<int> &v, int a, int b, int k, int &ans) {
    int m = (a + b) >> 1;
    if (a >= b) {
        if (v[m] <= k) ans = m;
        return;
    }
    if (v[m] <= k) {
        ans = m;
        // cout << " m = " << m << " a = " << a << " b = " << b << "\n";
        // cout << "test1";
        bsnr(v, m + 1, b, k, ans);
    } else {
        // cout << "test2";
        bsnr(v, a, m - 1, k, ans);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for (int i = 0; i < m; i++) {
        int ans = -1;
        int q;
        cin >> q;
        bsnr(v, 0, n - 1, q, ans);
        cout << ans << "\n";
    }
}

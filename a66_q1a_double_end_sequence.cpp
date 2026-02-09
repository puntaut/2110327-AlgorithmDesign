#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int sum_ij(vector<int> &s, int i, int j) {
    return s[j] - s[i-1];
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    vector<int> s(n+1);
    unordered_map<int, pair<int, int>> u; 
    int mx_global;
    int mx_local;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v[i] = x;
        s[i] = s[i-1] + x;
        if (i == 1) {
            mx_local = v[i];
            mx_global = mx_local;
            u[x] = make_pair(i, mx_local);
            continue;
        }
        if (u.find(x) == u.end()) {
            mx_local = v[i];
            mx_global = max(mx_local, mx_global);
            u[x] = make_pair(i, mx_local);
        } else {
            int low_i = u[x].first;
            mx_local = max(u[x].second, sum_ij(s, low_i, i));
            mx_global = max(mx_local, mx_global);
            if (s[i] < s[low_i]) {
                u[x].first = i;
            }
            u[x].second = mx_local;
        }
    }
    cout << mx_global << "\n";

}

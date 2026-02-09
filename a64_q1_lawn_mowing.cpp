#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll sum_ij(vector<ll> &s, ll i, ll j) {
    return (i == 0) ? s[j] : s[j] - s[i-1];
}

ll cost(vector<ll> &s, ll i, ll j, ll k) {
    return (sum_ij(s, i, j) + (j - i + 1) * k);
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> v(n);
    vector<ll> s(n);
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v[i] = x;
        s[i] = (i == 0) ? x : x + s[i-1];
    } 
    for (ll i = 0; i < m; i++) {
        ll from, budget;
        cin >> from >> budget;
        ll to = n - 1;

        ll a = from;
        ll b = to;
        ll sol;
        bool isFound = false;
        while (a <= b) {
            ll m = (a + b) >> 1;
            if (cost(s, from, m, k) <= budget) {
                sol = m;
                isFound = true;
                a = m + 1;
            } else {
                b = m - 1;
            }
        }
        if (isFound) {
            cout << sum_ij(s, from, sol) << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
}

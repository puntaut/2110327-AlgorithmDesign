#include <iostream>
#include <vector>
#include <cmath>

#define ll long long

using namespace std;

ll recur(vector<ll> &v, ll len, ll r, ll c) {
    if (len == 2) return v[2*r + c];
    if (r < len/2 && c < len/2) {
        return recur(v, len/2, r, c);
    } else if (r < len/2 && c >= len/2) {
        return recur(v, len/2, c-len/2, r);
    } else if (r >= len/2 && c < len/2) {
        return -recur(v, len/2, r-len/2, c);
    } else {
        return -recur(v, len/2, c-len/2, r-len/2);
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> v(4);
    for (ll i = 0; i < 4; i++) {
        cin >> v[i];
    }

    ll len = pow(2,n);
    vector<ll> result(m);
    for (ll i = 0; i < m; i++) {
        ll r, c;
        cin >> r >> c;
        result[i] = recur(v, len, r-1, c-1);
    }
    for (ll i = 0; i < m; i++) cout << result[i] << "\n";
}

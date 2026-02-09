#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

pair<ll, ll> thanos(vector<ll> &v, ll pos_a, ll pos_b, ll A, ll B) {
    auto it1 = lower_bound(v.begin(),v.end(), pos_a);
    auto it2 = upper_bound(v.begin(), v.end(), pos_b);

    ll len = pos_b - pos_a + 1;
    ll count = it2 - it1;

    if (count == 0) return make_pair(0, A);
    if (pos_a == pos_b) {
        return make_pair(count, B * count);
    }
    auto p1 = thanos(v, pos_a, pos_b - len/2, A, B);
    auto p2 = thanos(v, pos_a + len/2, pos_b, A, B);
    ll count1 = p1.first;
    ll count2 = p2.first;
    ll cost1 = p1.second;
    ll cost2 = p2.second;
    ll cost3 = B * (count1 + count2) * len;
    cost3 = (cost3 < (cost1 + cost2)) ? cost3 : (cost1 + cost2);
    return make_pair(count1 + count2, cost3);
}


int main() {
    ll p, k, A, B;
    cin >> p >> k >> A >> B;
    ll n = pow(2, p);
    vector<ll> v(k);
    for (ll i = 0; i < k; i++) {
        ll pos;
        cin >> pos;
        v[i] = pos;
    }
    sort(v.begin(), v.end());
    cout << thanos(v, 1, n, A, B).second << "\n";
}


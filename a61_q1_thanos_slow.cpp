#include <iostream>
#include <cmath>
#include <vector>

#define ll long long

using namespace std;

pair<ll, ll> thanos(vector<ll> &v, ll begin, ll len, ll A, ll B) {
    if (len == 1) {
        if (v[begin] == 0) { return make_pair(0, A);}
        else { return make_pair(v[begin], B * v[begin]);}
    }
    auto p1 = thanos(v, begin, len/2, A, B);
    auto p2 = thanos(v, begin + len/2, len/2, A, B);
    ll count1 = p1.first;
    ll count2 = p2.first;
    ll cost1 = p1.second;
    ll cost2 = p2.second;
    ll cost3;
    if (count1 + count2 == 0){
        cost3 = A;
        return make_pair(0, cost3);
    } else {
        cost3 = B * (count1 + count2) * len;
        return make_pair(count1 + count2, (cost3 < (cost1 + cost2)) ? cost3 : (cost1 + cost2));
    }
    
}

int main() {
    ll p, k, A, B;
    cin >> p >> k >> A >> B;
    ll n = pow(2,p);
    vector<ll> v(n); // n = 2^p
    for (ll i = 0; i < k; i++) {
        ll pos;
        cin >> pos;
        v[pos-1]++;
    }
    cout << thanos(v, 0, n, A, B).second << "\n";
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

#define pii pair<int, int>

using namespace std;

int distance(pii a, pii b) {
    return (pow(a.first-b.first, 2) + pow(a.second-b.second, 2));
}

int brute_force(vector<pii> &v, int a, int len) {
    int mn = distance(v[a], v[a+1]);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            mn = min(mn, distance(v[a+i], v[a+j]));
        }
    }
    return mn;
}

int recur(vector<pii> &v, int a, int len) {
    if (len <= 3) {
        return brute_force(v, a, len);
    }
    int m = a + len/2;
    int d1 = recur(v, a, len/2);
    int d2 = recur(v, a+len/2, len/2);
    int mn = min(d1, d2);
    int x = v[a + len/2].first;
    int i_l = lower_bound(v.begin(), v.begin()+m, make_pair(x-mn, INT_MIN)) - v.begin();
    int i_r = upper_bound(v.begin()+m, v.end(), make_pair(x+mn, INT_MIN)) - v.begin();
    if (i_r - i_l + 1 >= 2) {
        return min(mn, brute_force(v, i_l, i_r - i_l + 1));
    } else {
        return mn;
    }
}

int main() {
    int n;
    cin >> n;
    vector<pii> v(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }
    
    sort(v.begin(), v.end(), [](pii &p1, pii &p2) -> bool {
            return (p1.first == p2.first) ? p1.second < p2.second : p1.first < p2.first;
            });
    cout << recur(v, 0, v.size()) << "\n";

}

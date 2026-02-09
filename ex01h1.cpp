// 1 2 2 3 3 4 4 4 5 5
// 5 6 6 6 6 7 7 7 7 8
// 8 8 8 9 9 9 9 9 A A
// A A A B B B B B 
//
// 1 2 3 4 5 6 7 8 9 10 11 12-15 16-19 20-23
//   2 3 4 5 6 7 8 9 10 11 12-15 16-19 20-23
//       4 5 6 7 8 9 10 11 12-15 16-19 20-23
//           6 7 8 9 10 11 12-15 16-19 20-23
//                 9 10 11 12-15 16-19 20-23
//                         12-15 16-19 20-23
//                               16-19 20-23
//                                     20-23
#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int main() {
    vector<ll> v(800000);
    v[1] = 1;
    v[2] = 3;
    v[3] = 5;
    for (int i = 4; i <= 800000; i++) {
        int k = lower_bound(v.begin(), v.begin()+i, i) - v.begin();
        // int height = v[i] - v[i-1];
        v[i] = v[i-1] + k;
    }
    // cout << "last pos:" << v.back() << "\n";
    int n;
    cin >> n;
    // for (int i = 0; i < v.size(); i++) {
    //     cout << v[i] << " ";
    // }
    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        auto it = lower_bound(v.begin(), v.end(), pos);
        int ans = it - v.begin();
        cout << ans << "\n";
    }
}

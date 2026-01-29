#include <iostream>
#include <map>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n, q;
    cin >> n >> q;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int xi, ci;
        cin >> xi >> ci;
        m[xi] += ci;
    }

    int count = 0;
    map<int, int> idx2val;

    for (auto x : m) {
        // cout << "first: " << x.first << "second: " << x.second << "\n";
        count += m[x.first];
        idx2val[count] = x.first;
    }
    for (int i = 0; i < q; i++) {
        int qi;
        cin >> qi;
        qi = qi - 1;

        auto it = idx2val.upper_bound(qi);
        cout << it->second << "\n";
    }
}

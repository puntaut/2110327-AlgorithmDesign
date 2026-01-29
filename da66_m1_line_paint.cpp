#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    map<int, int> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        b += 1;
        if (m.size() == 0) {
            m[a] = b;
        } else {
            auto it = m.lower_bound(a);
            if (it != m.begin()) {
                auto it_l = prev(it);
                if (a <= it_l->second) {
                    a = min(it_l->first, a);
                    b = max(it_l->second, b);
                    m.erase(it_l);
                }
            }
            while (it != m.end()) {
                if (it->first <= b) {
                    b = max(it->second, b);
                    auto tmp = it++;
                    m.erase(tmp);
                } else {
                    break;
                }
            }
            m[a] = b;
        }
    }
    for (auto p : m) {
        cout << p.first << " " << p.second - 1 << " ";
    }
    cout << "\n";

}


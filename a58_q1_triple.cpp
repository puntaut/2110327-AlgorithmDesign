#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        bool found = false;
        for (int i1 = 0; i1 < n - 2; i1++) {
            int sum2 = q - v[i1];
            int i2 = i1 + 1;
            int i3 = n - 1;
            while (i2 < i3) {
                int sum_x = v[i2] + v[i3];
                if (sum_x == sum2) {
                    found = true;
                    break;
                } else if (sum_x < sum2) {
                    i2++;
                } else {
                    i3--;
                }
            }
            if (found) break;
        }
        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

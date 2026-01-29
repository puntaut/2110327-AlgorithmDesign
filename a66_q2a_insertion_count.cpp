#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> V(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        V[i] = x;
    }

    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        int count = 0;
        for (auto vi : V) {
            if (q == vi) {
                break;
            } else if (vi > q){
                count++;
            }
        }
        cout << count << "\n";
    }

}

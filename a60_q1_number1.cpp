#include <iostream>
#include <vector>

using namespace std;

void cal(vector<int> &range, int n, int k) {
    // cout << "k:" << k << "\n";
    if (n == 1) {
        range[k] = 1;
        return;
    }
    cal(range, n/2, k+1);
    range[k] = 2*range[k+1] + 1;
}

int recur(vector<int> &range, int n, int pos, int k) {
    if (pos == 0) return 0;
    if (n == 1) return 1;
    if (pos <= range[k]/2) {
        return recur(range, n/2, pos, k+1);
    } else if (pos == range[k]/2 + 1) {
        return (n/2) + (n%2);
    } else {
        return (n/2) + (n%2) + recur(range, n/2, pos-range[k]/2-1, k+1);
    }
}

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> range(40);
    int k = 0;
    cal(range, n, 0);

    // for (auto x : range) if (x != 0) cout << x << " ";

    // cout << "\n";
    int count = recur(range, n, r, 0) - recur(range, n, l-1, 0);
    cout << count << "\n";
}

#include <iostream>
#include <vector>

using namespace std;

char recur(vector<int> &v, int n, int k) {
    if (n <= v[k-1]) {
        return recur(v, n, k-1);
    } else if (n <= v[k] - v[k-1]) {
        if (n - v[k-1] == 1) return 'g';
        else return 'a';
    } else {
        return recur(v, n - (v[k] - v[k-1]), k-1);
    }
}

int main() {
    int n;
    vector<int> v(30);
    cin >> n;
    for (int i = 0; i < 30; i++) {
        if (i == 0) {
            v[i] = 3;
        } else {
            v[i] = (i+3) + 2*v[i-1];
        }
    }
    int k = lower_bound(v.begin(), v.end(), n) - v.begin();
    cout << recur(v, n, k) << "\n";

}

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool divoc(vector<bool> &v, int a, int len, bool isFlipped) {
    if (len == 2) {
        if (!isFlipped) {
            return !v[a] && v[a+1];
        } else {
            return v[a] && !v[a+1];
        }
    }
    if (isFlipped) {
        if (divoc(v, a, len/2, isFlipped)) {
            return divoc(v, a+len/2, len/2, isFlipped) ||
                divoc(v, a+len/2, len/2, !isFlipped);
        } else {
            return false;
        }
    } else {
        if (divoc(v, a+len/2, len/2, isFlipped)) {
            return divoc(v, a, len/2, isFlipped) ||
                divoc(v, a, len/2, !isFlipped);
        } else {
            return false;
        }

    }
}

int main() {
    int m, k;
    cin >> m >> k;
    int n = pow(2, k);
    vector<bool> v(n);
    
    for (int round = 0; round < m; round++) {
        for (int i = 0; i < n; i++) {
            bool x;
            cin >> x;
            v[i] = x;
        }
        if (divoc(v, 0, n, false)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}


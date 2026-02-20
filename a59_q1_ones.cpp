#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int recur(vector<int> &v, int n) {
    n = abs(n);
    if (n == 0) return 0;
    else if (n == 1) return 1;
    else if (n == 2) return 2;
    else if (n == 3) return 3;
    else if (n == 4) return 4;
    else if (n == 5) return 5;
    else if (n == 6) return 6;
    else if (n == 7) return 6;
    else if (n == 8) return 5;
    else if (n == 9) return 4;
    else if (n == 10) return 3;
    else if (n == 11) return 2;
    int i = upper_bound(v.begin(),v.end(), n) - v.begin();
    // cout << "v[i-1]:" << v[i-1] << " ";
    // cout << "n:" << n << " ";
    // cout << "i:" << i << "\n";

    int x1 = recur(v, n % v[i-1]) + (n/v[i-1])*(i-1);
    if (v[i] - n < n) {
        int x2 = recur(v, n - v[i]) + i;
        return min(x1, x2);
    } else {
        return x1;
    }

}

int main() {
    int n;
    cin >> n;
    vector<int> v(11);
    for (int i = 1; i <= 10; i++) {
        v[i] = (pow(10, i) - 1) / 9;
    }
    cout << recur(v, n) << "\n";
}

#include <iostream>

using namespace std;


int poww(int x, int n, int k) {
    x %= k;
    if (n == 0) return 1;
    if (n == 1) return x;
    int xn2 = poww(x, n/2, k) % k;
    if (n % 2 == 0) {
        return (xn2 * xn2) % k;
    } else {
        return (((xn2 * xn2) % k) * x) % k;
    }
}

int main() {
    int x, n, k;
    cin >> x >> n >> k;
    cout << poww(x, n, k) << "\n";
}

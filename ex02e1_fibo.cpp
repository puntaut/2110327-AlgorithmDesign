#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int v1;
    int v2;
    int r;
    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            r = 0;
            continue;
        } else if (i == 1) {
            v2 = r;
            r = 1;
            continue;
        } else {
            v1 = v2;
            v2 = r;
            r = v1 + v2;
            continue;
        }
    }
    cout << r << "\n";
}

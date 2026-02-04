#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int divoc(vector<bool> &v, int start, int len, bool &ans) {
    if (len == 2) {
        if (v[start] == false && v[start + 1] == false) return 0;
        if (v[start] == false && v[start + 1] == true) return 1;
        if (v[start] == true && v[start + 1] == true) return 2;
        return 1;
    }
    int x1 = divoc(v, start, len/2, ans);
    int x2 = divoc(v, start + len/2, len/2, ans);
    if (abs(x1 - x2) > 1) ans = false;
    // cout << "len = " << len << ", ";
    // cout << "x1 - x2 = " << x1 - x2 << "\n";
    return x1 + x2;

}

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> virus(pow(2,k));
    vector<bool> ans_v(n); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < pow(2,k); j++) {
            bool x;
            cin >> x;
            virus[j] = x;
        }
        bool ans = true;
        divoc(virus, 0, pow(2,k), ans);
        ans_v[i] = ans;
    }
    for (int i = 0; i < n; i++) {
        cout << ((ans_v[i]) ? "yes" : "no") << "\n";
    }
}

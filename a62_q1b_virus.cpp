#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool dovic(vector<bool> &v, int len, int start, bool isReverse) {
    if (len == 2) {
        if (isReverse) {
            return v[start] == true && v[start + 1] == false;
        } else {
            return v[start] == false && v[start + 1] == true;
        }
    }
    
    bool A = dovic(v, len/2, start, isReverse);
    bool B = dovic(v, len/2, start, !isReverse);
    bool C = dovic(v, len/2, start + len/2, isReverse);
    bool D = dovic(v, len/2, start + len/2, !isReverse);
    // cout << "len = " << len << ", start = " << start << ": ";
    // cout << A << B << C << " " << ((A || B) && C) << "\n";
    if (!isReverse) {
        return ((A || B) && C);
    } else {
        return ((C || D) && A);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> virus(pow(2, k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < pow(2,k); j++) {
            bool x;
            cin >> x;
            virus[j] = x;
        }
        // cout << "READ DONE\n";
        // for (auto xi : virus) cout << xi;
        // cout << "\n";
        bool isReverse = false;
        if (dovic(virus, pow(2,k), 0, isReverse)) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}

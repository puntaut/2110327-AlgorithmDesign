#include <iostream>
#include <vector>

using namespace std;

void recur(int cap, int len, int white_count, int white_cap, vector<bool> &sol) {
    if (len < cap) {
        // cout << "len : "<< len << "\n";
        if (white_count < white_cap) {
            sol[len] = true;
            recur(cap, len + 1, white_count + 1, white_cap, sol);
            sol[len] = false;
        }
        if (len-white_count < cap - white_cap) {
            sol[len] = false;
            recur(cap, len + 1, white_count, white_cap, sol);
        }
    } else {
        // cout << "size : " << sol.size() << "\n";
        for (auto b : sol) {
            if (b) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << "\n";
    }
}

int main() {
    int n, m;
    cin >> m >> n;
    vector<bool> sol(n);
    recur(n, 0, 0, m, sol);

}


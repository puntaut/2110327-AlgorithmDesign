#include <iostream>
#include <vector>
#include <map>

using namespace std;

void recur(int n, vector<int> &sol, int len, vector<bool> &used, map<int, vector<int>> &mp) {
    if (len < n) {
        for (int i = 0; i < n; i++) {
            bool not_pass = false;
            if (used[i] == false) {
                // check for constraint
                auto it = mp.find(i);
                if (it != mp.end()) {
                    for (auto bf : it->second) {
                        if (used[bf] == false) 
                            not_pass = true;
                            break;
                    }
                }
                if (not_pass) continue;

                used[i] = true;
                sol[len] = i;
                recur(n, sol, len + 1, used, mp);
                used[i] = false;
            }
        }
    } else {
        for (int x : sol) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> v(n);
    vector<int> sol(n);
    map<int, vector<int>> mp;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        mp[b].push_back(a);
    }
    recur(n, sol, 0, v, mp);
}

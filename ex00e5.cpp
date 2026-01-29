#include <iostream>
#include <vector>

using namespace std;

void recur(int n, int m, int len, vector<bool> &used, int max, int count) {
    if (len < n) {
        used[len] = false;
        recur(n, m, len + 1, used, max, 0);
        used[len] = true;
        recur(n, m, len + 1, used, (count + 1 > max ? count + 1 : max), count + 1);
    } else {
        if (max >= m) {
            for (auto b : used) 
                    cout << ((b) ? "1" : "0");
            cout << "\n";
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> used(n);
    recur(n, m, 0, used, 0, 0);

}

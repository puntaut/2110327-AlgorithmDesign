#include <iostream>

using namespace std;

int VAR = 16777216;

int main() {
    int x;
    int len;
    cin >> x;
    queue<pair<int, int>> q;

    if (x == 0) {
        cout << "0";
    } else {
        q.push(make_pair(x, 0));
    }

    while (!q.empty()) {
        auto p = q.front();

        // cout << "test x = " << p.first;

        int x1 = (p.first + 1) % VAR;
        if (x1 == 0) {
            cout << p.second + 1;
            break;
        } else {
            q.push(make_pair(x1, p.second + 1));
        }
        int x2 = (p.first * 2) % VAR; 
        if (x2 == 0) {
            cout << p.second + 1;
            break;
        } else {
            q.push(make_pair(x2, p.second + 1));
        }
        q.pop();
    }
    
}

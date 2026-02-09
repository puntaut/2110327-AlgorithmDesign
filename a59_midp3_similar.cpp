#include <iostream>
#include <string>

using namespace std;

bool recur(string &s1, string &s2, int len, int a1, int a2) {
    if (len == 1) {
        return s1[a1] == s2[a2];
    }
    bool A = recur(s1, s2, len/2, a1, a2);
    if (A) {
        bool B = recur(s1, s2, len/2, a1+len/2, a2+len/2);
        if (A && B) return true;
    }
    bool C = recur(s1, s2, len/2, a1, a2+len/2);
    if (C) {
        bool D = recur(s1, s2, len/2, a1+len/2, a2);
        return C && D;
    } else {
        return false;
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    if (recur(s1, s2, n, 0, 0)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

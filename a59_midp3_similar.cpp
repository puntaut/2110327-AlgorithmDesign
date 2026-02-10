#include <iostream>
#include <string>

using namespace std;

string merge(string &s, int a, int len) {
    if (len % 2) {
        return s.substr(a, len);
    }
    string s1 = merge(s, a, len/2);
    string s2 = merge(s, a+len/2, len/2);
    return (s1 <= s2) ? (s1 + s2) : (s2 + s1);
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    if (merge(s1, 0, s1.size()) == merge(s2, 0, s2.size())) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

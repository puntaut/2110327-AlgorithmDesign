#include <iostream>
#include <algorithm>
#include <vector>

#define point pair<int, int>

using namespace std;

vector<point> findPareto(vector<point> &v, int a, int b) {
    if (a == b) return {v[a]};
    int m = (a + b) >> 1;
    vector<point> pareto_right_v = findPareto(v, a, m);
    vector<point> pareto_left_v = findPareto(v, m+1, b);
    int y_mx = pareto_right_v.back().second;
    for (auto p : pareto_left_v) {
        if (p.second > y_mx) {
            // cout << "yep" << a << " "<< b <<"\n";
            pareto_right_v.push_back(p);
        }
    }
    return pareto_right_v;
}

int main() {
    int n;
    cin >> n;
    vector<point> v;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), [] (point &A, point &B) -> bool {
            return (A.first == B.first) ? A.second > B.second : A.first > B.first;
        });
    // for (auto p : v) {
    //     cout << "x:"<< p.first << " y:"<< p.second << "\n";
    // }
    auto sol = findPareto(v, 0, n-1);
    cout << sol.size() << "\n";

}

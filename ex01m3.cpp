#include <vector>
#include <iostream>
#include <algorithm>

#define LL long long 

using namespace std;

int main() {
    int N, A;
    cin >> N >> A;
    vector<int> v(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int ti;
        cin >> ti;
        v[i] = ti;
    }

    for (int i = 0; i < A; i++) {
        LL ci;
        cin >> ci;
        LL a = 0;
        LL b = (*min_element(v.begin(),v.end())) * (ci);
        LL sol_t;
        while (a <= b) {
            LL count = 0;
            LL m = a + (b-a)/2;
            for (int j = 0; j < N; j++) {
                count += m/v[j] + 1;
            }

            if (count >= ci) {
                sol_t = m;
                b = m - 1;
            } else {
                a = m + 1;
            }
        }
        cout << sol_t << "\n";
    }
}

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, int start, int m, int stop, vector<int> &tmp, int &count) {
    int i1 = start;
    int i2 = m + 1;
    for (int i = start; i <= stop; i++) {
        if (i1 > m) { tmp[i] = v[i2++]; continue; }
        if (i2 > stop) { tmp[i] = v[i1++]; continue; }

        if (v[i1] <= v[i2]) {
            tmp[i] = v[i1++];
        } else {
            tmp[i] = v[i2++];
            count += m - i1 + 1;
        }
    }
    for (int i = start; i <= stop; i++) v[i] = tmp[i];
}

void merge_sort(vector<int> &v, int start, int stop, vector<int> &tmp, int &count) {
    if (start < stop) {
        int m = (start + stop) >> 1; // divide by 2
        merge_sort(v, start, m, tmp, count);
        merge_sort(v, m + 1, stop, tmp, count);
        merge(v, start, m, stop, tmp, count);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> tmp(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int count = 0;
    merge_sort(v, 0, n - 1, tmp, count);
    cout << count << "\n";
}

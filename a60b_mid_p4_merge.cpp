#include <iostream>
#include <vector>

using namespace std;

void mergesort(vector<int> &v, int a, int b, vector<int> &tmp, int &count) {
    bool is_sort = true;
    if (a == b || a == b - 1) return;
    for (int i = 0; i <= b - a - 2; i++) {
        if (v[i] > v[i+1]) {
            is_sort = false;
            break;
        }
    }
    if (is_sort) return;

    int m = (a + b) >> 1;

}

int main() {

}

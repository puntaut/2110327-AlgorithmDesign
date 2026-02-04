#include <iostream>
#include <vector>

using namespace std;

vector<int> mat_mul(vector<int> A, vector<int> B, int k) {
    vector<int> tmp(4);
    tmp[0] = ((A[0]%k) * (B[0]%k) + (A[1]%k) * (B[2]%k)) % k;
    tmp[1] = ((A[0]%k) * (B[1]%k) + (A[1]%k) * (B[3]%k)) % k;
    tmp[2] = ((A[2]%k) * (B[0]%k) + (A[3]%k) * (B[2]%k)) % k;
    tmp[3] = ((A[2]%k) * (B[1]%k) + (A[3]%k) * (B[3]%k)) % k;
    return tmp;
}

vector<int> mat_pow(vector<int> A, int n, int k) {
    if (n == 1) return A;
    vector<int> An2 = mat_pow(A, n/2, k);
    if (n % 2 == 0) {
        return mat_mul(An2, An2, k);
    } else {
        return mat_mul(mat_mul(An2, An2, k), A, k);
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> A(4);
    vector<int> result(4);
    for (int i = 0; i < 4; i++) {
        cin >> A[i];
    }
    result = mat_pow(A, n, k);
    for (int i = 0; i < 4; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";
}

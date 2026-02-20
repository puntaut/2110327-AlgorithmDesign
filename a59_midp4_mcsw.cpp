#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    deque<int> deq;
    vector<int> s(n+1);
    deq.push_back(0);

    int mcs;
    for (int i = 1; i < n+1; i++) {
        int x;
        cin >> x;
        s[i] = s[i-1] + x; // w = i - (i - w + 1) + 1 
        if (!deq.empty() && deq.front() < i - w + 1) {
            deq.pop_front();
        }

        if (i == 1) {
            mcs = s[i] - s[i-1];
        } else {
            mcs = max(s[i]-s[deq.front()], mcs);
        }

        while(!deq.empty() && s[i] <= s[deq.back()]) {
            deq.pop_back();
        }

        deq.push_back(i);
    }
    cout << mcs << "\n";

}

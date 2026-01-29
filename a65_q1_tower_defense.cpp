#include <iostream>
#include <vector>

using namespace std;

int n, n_monster, n_turret, range;
int total_health, min_health;

void recur(int len, vector<int> &pos_turret, vector<int> &map_health, int total_health, int &min_health) {
    if (len != n_turret) {
        int a, b;
        a = (pos_turret[len] - range < 0) ? 0 : pos_turret[len] - range;
        b = (pos_turret[len] + range >= n - 1) ? n - 1 : pos_turret[len] + range;
        bool found = false;
        // cout << "a: " << a << ", b: " << b << "\n";
        for (int i = a; i <= b; i++) {
            if (map_health[i] != 0) {
                map_health[i] -= 1;
                recur(len + 1, pos_turret, map_health, total_health - 1, min_health);
                map_health[i] += 1;
                found = true;
                // cout << "turret : " << pos_turret[len] << "\n";
            }
        }
        if (!found) recur(len + 1, pos_turret, map_health, total_health, min_health);

    } else {
        if (total_health < min_health) min_health = total_health;
    }
}

int main() {
    cin >> n >> n_monster >> n_turret >> range;
    vector<int> pos_monster(n_monster);
    vector<int> map_health(n);
    vector<int> pos_turret(n_turret);
    for (int i = 0; i < n_monster; i++) {
        int x1;
        cin >> x1;
        pos_monster[i] = x1 - 1;
    }

    for (int i = 0; i < n_monster; i++) {
        int health;
        cin >> health;
        map_health[pos_monster[i]] += health;
        total_health += health;
    }

    for (int i = 0; i < n_turret; i++) {
        int x2;
        cin >> x2;
        pos_turret[i] = x2-1;
    }
    min_health = total_health;
    recur(0, pos_turret, map_health, total_health, min_health);
    cout << min_health;


}

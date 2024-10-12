#include <bits/stdc++.h>
#define ll long long int

using namespace std;

// Függvény, ami kalkulálja a jutalmat
ll solve(vector<vector<ll>>& tasks, ll N) {
    // Rendezzük a feladatokat időtartamuk szerint növekvő sorrendbe
    sort(tasks.begin(), tasks.end()); // Rendezés az első elem szerint (időtartam)

    // Változó az eddig eltelt idő nyomon követésére
    ll currentTime = 0;

    // Változó a jutalmak teljes összegének tárolására
    ll totalReward = 0;

    // Ismételjük meg az összes feladatot, és számítsuk ki a teljes jutalmat
    for (int i = 0; i < N; i++) {
        currentTime += tasks[i][0]; // Adjuk hozzá a feladat időtartamát az aktuális időhöz
        totalReward += (tasks[i][1] - currentTime); // Jutalom = határidő – befejezési idő
    }

    return totalReward;
}

int main() {
    // Feladatok száma
    ll N;
    cin >> N;

    // Olvassuk be a feladatok időtartamát és határidejét
    vector<vector<ll>> tasks(N, vector<ll>(2));
    for (int i = 0; i < N; i++) {
        cin >> tasks[i][0] >> tasks[i][1];
    }

    // Az eredmény kiiratása
    cout << solve(tasks, N) << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int editDistance(const string &s1, const string &s2) {
    int n = s1.length();
    int m = s2.length();

    // Hozzunk létre egy 2D tömböt a szerkesztési távolságok tárolásához
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    // Inicializáljuk az első sort és oszlopot
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i;  // Az összes karakter törlésének költsége az s1-ből
    }
    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j;  // Az összes karakter hozzáadásának költsége az s1-hez
    }

    // Tömb kitöltése
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];  // Nincs szükség műveletre
            } else {
                dp[i][j] = min({dp[i - 1][j] + 1,    // Törlés
                                dp[i][j - 1] + 1,    // Beillesztés
                                dp[i - 1][j - 1] + 1} // Helyettesítés
                );
            }
        }
    }

    return dp[n][m];
}

int main() {
    string s1, s2;

    // Input stringek
    cin >> s1;
    cin >> s2;

    // Számoljuk ki és írjuk ki a szerkesztési távolságot
    cout << editDistance(s1, s2) << endl;

    return 0;
}

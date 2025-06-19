/*-----------------------------
        Author : TgX.2
       11Ti - K28 - CHV
-----------------------------*/

#include <bits/stdc++.h>
using namespace std;

#ifdef TGX
#include "D:\egoist\debug.h"
#else 
#define debug(...)
#endif

#define FOR(i, a, b)       for (int i = (a), _b = (b); i <= _b; i += 1)
#define FORD(i, a, b)      for (int i = (a), _b = (b); i >= _b; i -= 1)

#define fi                 first
#define se                 second
#define pb                 push_back
#define len(x)             (int)((x).size())
#define all(x)             (x).begin(), (x).end()

#define _                  << " " <<
#define __                 << "\n"
#define ___                << " "

#define ______________TgX______________ main()
#define int                long long
#define intmax             1e9
#define intmin            -1e9
#define llongmax           1e18
#define llongmin          -1e18
#define memo(a, val)       memset((a), (val), sizeof((a)))

template<typename T1, typename T2> bool mini(T1 &a, T2 b)
    {if (a > b) a = b; else return 0; return 1;}

template<typename T1, typename T2> bool maxi(T1 &a, T2 b)
    {if (a < b) a = b; else return 0; return 1;}
/*-----------------------------*/

const int maxn = 1007;
int n, kk, a[maxn], b[maxn];

int dp[10][maxn][maxn];

void process() {
    cin >> n >> kk;
    FOR(i, 1, n) cin >> a[i];
    FOR(i, 1, n) cin >> b[i];

    FOR(k, 1, kk) FOR(i, 0, n + 1) FOR(j, 0, n + 1)
    	dp[k][i][j] = llongmin;

    FOR(k, 1, kk) FOR(i, 1, n) FOR(j, 1, n) {
    	maxi(dp[k][i][j], dp[k][i - 1][j]);
    	maxi(dp[k][i][j], dp[k][i][j - 1]);
    	maxi(dp[k][i][j], dp[k][i - 1][j - 1]);
    	maxi(dp[k][i][j], dp[k - 1][i - 1][j - 1] + a[i] * b[j]);
    }

    cout << dp[kk][n][n];
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("kseqgame.inp", "r")) {
        freopen("kseqgame.inp", "r", stdin);
        freopen("kseqgame.out", "w", stdout);
    }
    process();
    cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC __ ;
}


/*==============================+
|INPUT                          |
--------------------------------|

================================+
|OUTPUT                         |
--------------------------------|

===============================*/
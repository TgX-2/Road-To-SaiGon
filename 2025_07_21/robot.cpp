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

const int maxn = 57;
int n, m, k, a[maxn][maxn];

int dp[maxn][maxn][maxn];
void dijk() {
	FOR(i, 0, n + 1) FOR(j, 0, m + 1) FOR(kk, 0, k + 1) dp[i][j][kk] = intmin;
	dp[1][1][0] = 0;
		FOR(kk, 0, k) {
	FOR(i, 1, n) FOR(j, 1, m) {
			if (j != 1) maxi(dp[i][j][kk], dp[i][j - 1][kk] + a[i][j]);
			if (i != 1) maxi(dp[i][j][kk], dp[i - 1][j][kk] + a[i][j]);
			if (kk != 0) {
				if (j != m) maxi(dp[i][j][kk], dp[i][j + 1][kk - 1] + a[i][j]);
				if (i != n) maxi(dp[i][j][kk], dp[i + 1][j][kk - 1] + a[i][j]);
			}
			// if (kk != 0 and (j != m or i != n)) dp[i][j][kk] = max(dp[i][j][kk], max(dp[i + 1][j][kk - 1], dp[i][j + 1][kk - 1]) + a[i][j]);
	}
		}
	int ans = intmin;
	FOR(kk, 0, k) maxi(ans, dp[n][m][kk]);
	cout << ans;
}	

void process() {
    cin >> n >> m >> k;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];
    dijk();
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("robot.inp", "r")) {
        freopen("robot.inp", "r", stdin);
        freopen("robot.out", "w", stdout);
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
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

const int maxn = 2e4 + 7;
const int maxm = 5000;

int n, c, a[maxn];
int dp[maxn][maxm + 7];

void process() {
    cin >> n >> c;
    FOR(i, 1, n) cin >> a[i];

    memset(dp, 0x3f, sizeof dp);
    FOR(j, a[1], n) dp[1][j] = (j - a[1]) * (j - a[1]);

    FOR(i, 2, n) {
    	int mmin = llongmax;
    	FOR(j, a[i - 1], maxm) {
    		mini(mmin, dp[i - 1][j] - j * c);
    		if (j >= a[i]) mini(dp[i][j], mmin + j * c + (j - a[i]) * (j - a[i]));
    	}

    	mmin = llongmax;
    	FORD(j, maxm, a[i]) {
    		mini(mmin, dp[i - 1][j] + j * c);
    		mini(dp[i][j], mmin - j * c + (j - a[i]) * (j - a[i]));
    	}
    }

  	// FOR(i, 1, n) {
  	// 	FOR(j, a[i], maxm) {
	//   		int l = a[i - 1], r = min(maxm, a[i + 1] + 100);
	//   		FOR(k, 1, 15) {
	//   			int mid1 = l + (r - l) / 3;
	//   			int mid2 = r - (r - l) / 3;
	//   			if (get(i, j, mid1) >= get(i, j, mid2)) l = mid1;
	//   			else r = mid2;
	//   		}

	//   		int ans = (l + r) / 2;
	//   		// if (j <= 10) cout << ans ___ ;
	//   		dp[i][j] = min({c * abs(j - ans) + dp[i - 1][ans] + (j - a[i]) * (j - a[i]),
	//   					  c * abs(j - l) + dp[i - 1][l] + (j - a[i]) * (j - a[i]),
	//   					  c * abs(j - r) + dp[i - 1][r] + (j - a[i]) * (j - a[i])});
  	// 	}

  	// 	// cout __ ;
  	// 	// FOR(j, 1, 10) cout << cur[j] ___ ;
  	// 	// cout __ ;
  	// 	// cout __ ;
  	// 	FOR(j, 1, 20) cout << dp[i][j] ___ ;
  	// 	cout __ ;
  	// 	// FOR(j, 1, maxm)
  	// 	// 	pre[j] = cur[j];
  	// }

  	int ans = llongmax;
  	FOR(i, a[n], maxm) mini(ans, dp[n][i]);
  	cout << ans;

}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    if (fopen("micost.inp", "r")) {
        freopen("micost.inp", "r", stdin);
        freopen("micost.out", "w", stdout);
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
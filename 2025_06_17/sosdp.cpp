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

const int maxn = 20;
int n, a[(1 << maxn)];
int dp[maxn][(1 << maxn)];

void process() {
    cin >> n;
    FOR(i, 0, (1 << n) - 1) cin >> a[i];

    for(int mask = 0; mask <= (1 << n) - 1; mask++) {
    	dp[0][mask] = a[mask];
    	for(int k = 1; k <= n; k++) {
    		if (mask & (1 << (k - 1))) 
    			dp[k][mask] = dp[k - 1][mask] + dp[k - 1][mask ^ (1 << (k - 1))];
    		else dp[k][mask] = dp[k - 1][mask];
    	}
    }

    FOR(i, 0, (1 << n) - 1) cout << dp[n][i] ___ ;

}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("sosdp.inp", "r")) {
        freopen("sosdp.inp", "r", stdin);
        freopen("sosdp.out", "w", stdout);
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
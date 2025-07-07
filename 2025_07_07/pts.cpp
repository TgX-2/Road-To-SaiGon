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

const int mod = 1e9 + 7;
int poww(int a, int b) {
	if (b == 0) return 1;
	int x = poww(a, b / 2);
	if (b & 1) return ((x * x) % mod * a) % mod;
	return (x * x) % mod;
}

const int maxn = 1e5 + 7;
int n;
int dp[maxn];
vector<int> val;

void process() {
	cin >> n;
	for(int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			val.pb(i);
			if (i != n / i) val.pb(n / i);
		}
	}


	sort(all(val));

	FORD(i, len(val) - 1, 0) {
		dp[val[i]] = poww(2, n / val[i] - 1);
		FOR(j, i + 1, len(val) - 1) {
			if (val[j] % val[i] == 0) 
				dp[val[i]] = (dp[val[i]] - dp[val[j]] + mod) % mod;
		}
	}

	cout << dp[1];
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("pts.inp", "r")) {
        freopen("pts.inp", "r", stdin);
        freopen("pts.out", "w", stdout);
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
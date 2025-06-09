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

int x, l, r;
int f[35][3];
int a[35];

int dp(int id, bool isless) {
	if (id < 0) return 1;
	if (~f[id][isless]) return f[id][isless];

	int ans = 0;
	bool lim = (isless ? a[id] : 1);	
	FOR(i, 0, lim) {
		bool nisless = (i == lim ? isless : 0);
		if (i == 1) ans += dp(id - 1, nisless);
		else if ((x & (1 << id)) == 0) 
			ans += dp(id - 1, nisless);
	}
	return f[id][isless] = ans;
}

int get(int x){
	FOR(i, 0, 33) FOR(j, 0, 1) f[i][j] = -1;
	FOR(i, 0, 31) a[i] = (x & (1 << i));
	return dp(31, 1);
}

void process() {
    int t; cin >> t;
    while(t--) {
		cin >> x >> l >> r;	
		cout << get(r) - get(l - 1) __ ;
    }
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("or.inp", "r")) {
        freopen("or.inp", "r", stdin);
        freopen("or.out", "w", stdout);
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
10
11
100
101

1 : 1

===============================*/
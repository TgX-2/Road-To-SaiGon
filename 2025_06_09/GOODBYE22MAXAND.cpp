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

int x, l, r, k;
int f[35][3];
int a[35];

int dp(int id, bool isless) {
	if (id < 0) return 1;
	if (~f[id][isless]) return f[id][isless];

	int ans = 0;
	bool lim = (isless ? a[id] : 1);	
	FOR(i, 0, lim) {
		if (i == 0 and (x & (1 << id)) != 0) continue;
		bool nisless = (i == lim ? isless : 0);
		ans += dp(id - 1, nisless);
	}
	return f[id][isless] = ans;
}

int get(int val){
	FOR(i, 0, 22) FOR(j, 0, 1) f[i][j] = -1;
	FOR(i, 0, 20) a[i] = (((val >> i) & 1));
	return dp(20, 1);
}

void process() {
    int t; cin >> t;
    while(t--) {
    	cin >> l >> r >> k;

    	x = 0;
    	FORD(i, 20, 0) {
    		x |= (1 << i);
    		int cost = get(r) - get(l - 1);
    		// cout << cost __ ;
    		if (cost == 0 or r - l + 1 - cost > k) x ^= (1 << i);
    		// cout << bitset<20>(x) __ ;
    	}
    	cout << x __ ;
    }
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("bai3.inp", "r")) {
        freopen("bai3.inp", "r", stdin);
        freopen("bai3.out", "w", stdout);
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
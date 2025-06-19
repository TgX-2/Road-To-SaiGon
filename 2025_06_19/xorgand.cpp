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

const int maxn = 2e5 + 7;
const int maxk = 32;

int n, q, a[maxn];
int bit[maxn][maxk], cc[maxn];

void process() {
	cin >> n;	
	FOR(i, 1, n) cin >> a[i];

	FOR(i, 1, n) {
		FOR(j, 0, 30) bit[i][j] = bit[i - 1][j];
		cc[i] = cc[i - 1];
		if (a[i] == 0) cc[i]++;
		else bit[i][31 - __builtin_clz(a[i])]++;
	}

	cin >> q;    
	while(q--) {
		int l, r, x; cin >> l >> r >> x;
		if (x == 0) cout << (r - l + 1) - (cc[r] - cc[l - 1]) __ ;
		else cout << (r - l + 1) - (bit[r][31 - __builtin_clz(x)] - bit[l - 1][31 - __builtin_clz(x)]) __ ;
	}
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("xorgand.inp", "r")) {
        freopen("xorgand.inp", "r", stdin);
        freopen("xorgand.out", "w", stdout);
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
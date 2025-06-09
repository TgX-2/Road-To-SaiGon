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

int t, d;
string s;
int f[22][(1 << 7)];
int a[22];

int dp(int id, int mask) {
	if (id > len(s)) return (mask == 0);
	if (~f[id][mask]) return f[id][mask];

	int ans = 0;

	FOR(i, 0, 9) {
		int cur = i + (mask & 1);
		if (cur <= a[id]) (ans += dp(id + 1, mask >> 1)) %= mod;
		else (ans += dp(id + 1, (mask >> 1) | (1 << (d - 1)))) %= mod;
	}

	return f[id][mask] = ans; 
}

int get() {
	int idx = 1;
	FORD(i, len(s) - 1, 0) {
		a[idx] = (s[i] - '0');
		idx++;
	}

	idx--;
	memo(f, -1);
	return dp(1, 0);
}

void process() {
	cin >> t >> d;
	while(t--) {
		cin >> s;	

		cout << (get() - 2 + mod) % mod __ ;
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

===============================*/

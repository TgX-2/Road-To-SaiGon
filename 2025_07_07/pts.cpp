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

int n;

int ans = 0;
vector<int> val;

bool check() {
	if (len(val) == 1) {
		if (n == 1) return 1;
		return 0;
	}

	FOR(i, 0, len(val) - 1) FOR(j, 0, len(val) - 1) if (i != j) 
		if (__gcd(val[i], val[j]) != 1) return 0;
	return 1; 
}

void dfs(int x) {
	if (x == 0) {
		sort(all(val));
		if (check()) ans++;
	}

	FOR(i, 1, x) {
		val.pb(i);
		dfs(x - i);
		val.pop_back();
	}
}

const int mod = 1e9 + 7;
int poww(int a, int b) {
	if (b == 0) return 1;
	int x = poww(a, b / 2);
	if (b & 1) return ((x * x) % mod * a) % mod;
	return (x * x) % mod;
}

void process() {
	cin >> n;
	if (n == 1 or n == 2) return cout << 1, void();
	cout << (poww(2, n - 1) - 1 + mod) % mod;

    // cin >> n;
	// FOR(i, 5, 15) {
	// 	n = i;
	// 	ans = 0;
	//     val.clear();
	//     dfs(n);
	//     cout << ans ___ ;

	//     // cout << (1 - 2 * n + 2 * n * n) / ((1 - n) * (1 - 2 * n)) __ ;
	// }

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
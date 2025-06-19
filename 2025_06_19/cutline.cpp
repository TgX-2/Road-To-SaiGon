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
const int mod  = 1e9 + 7;
const int base = 31;
int n, m;
char a[maxn][maxn];

int poww[maxn], hhash[maxn][maxn];

int Get(int id, int l, int r) {
	return (hhash[r][id] - hhash[l - 1][id] * poww[r - l + 1] + mod * mod) % mod;
}

void RabinKarp() {
	poww[0] = 1;
	FOR(i, 1, max(n, m)) poww[i] = (poww[i - 1] * base) % mod; 

	FOR(j, 1, m) {
		FOR(i, 1, n) hhash[i][j] = (hhash[i - 1][j] * base + a[i][j] - 'a' + 1) % mod;
	}
}

bool check(int mid) {
	unordered_set<int> s;
	FOR(i, 1, m) {
		int x = Get(i, mid + 1, n);
		if (s.find(x) != s.end()) return 0;	
		s.insert(x);
		// if (x != tar) return 1;
	}
	return 1;
}

void process() {
    cin >> n >> m;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];

    RabinKarp();
    // cout << check(3);
    // return;

    int l = 1, r = n - 1, ans = 0;
    while(l <= r) {
    	int mid = (l + r) >> 1;
    	if (check(mid)) {
    		ans = mid;
    		l = mid + 1;
    	} else r = mid - 1;
    }

    cout << ans;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("cutline.inp", "r")) {
        freopen("cutline.inp", "r", stdin);
        freopen("cutline.out", "w", stdout);
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
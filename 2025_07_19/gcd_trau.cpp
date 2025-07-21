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
int n, q, a[maxn];

int st[maxn][30];
void build() {
	FOR(i, 1, n) st[i][0] = a[i];
	for(int j = 1; (1 << j) <= n; j++)
		for(int i = 1; i + (1 << j) - 1 <= n; i++)
			st[i][j] = __gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int get(int l, int r) {
	int k = __lg(r - l + 1);
	return __gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

namespace sub1 {

	int f(int l, int r, int x) {
		int ans = 0;
		FOR(i, l, r) FOR(j, i, r) {
			if (get(i, j) >= x) ans++;
		}
		return ans;
	}

	void sol() {
		build();

		while(q--) {
			int l, r, x; cin >> l >> r >> x;
			cout << f(l, r, x) __ ;
		}
	}
};

namespace sub2 {

	int cal(int u, int v, int x) {
		int l = u, r = v, ans = -1;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if (get(u, mid) >= x) {
				ans = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
		return ans;
	}

	int f(int l, int r, int x) {
		int ans = 0;
		FOR(i, l, r) {
			int j = cal(i, r, x);
			if (j != -1) ans += (j - i + 1);
		}
		return ans;
	}

	void sol() {
		build();
		while(q--) {
			int l, r, x; cin >> l >> r >> x;
			cout << f(l, r, x) __ ;
		}
	}
};

void process() {
    cin >> n >> q;
    FOR(i, 1, n) cin >> a[i];

	sub1::sol();
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("gcd.inp", "r")) {
        freopen("gcd.inp", "r", stdin);
        freopen("gcd.ans", "w", stdout);
    }
    process();
    cerr << "Time trau: " << 1.0 * clock() / CLOCKS_PER_SEC __ ;
}


/*==============================+
|INPUT                          |
--------------------------------|

================================+
|OUTPUT                         |
--------------------------------|

===============================*/
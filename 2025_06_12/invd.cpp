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
int n, d, a[maxn];

namespace sub1 {
	void sol() {
		int ans = 0;
		FOR(i, 1, n - 2) FOR(j, i + 1, n - 1) FOR(k, j + 1, n) {
			if (a[i] - d >= a[j] and a[j] - d >= a[k]) ans++;
		}
		cout << ans;
	}
};

int seg[maxn << 2], lazy[maxn << 2];

void down(int id) {
	int x = lazy[id];
	seg[id << 1] += x;
	seg[id << 1 | 1] += x;
	lazy[id << 1] += x;
	lazy[id << 1 | 1] += x;
	lazy[id] = 0;
}

void build(int id, int l, int r) {
	if (l == r) return seg[id] = 0, void();
	int mid = (l + r) >> 1;
	build(id << 1, l, mid);
	build(id << 1 | 1, mid + 1, r);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

void update(int id, int l, int r, int u, int v, int val) { 
	if (v < l or r < u) return;
	if (u <= l and r <= v) {
		seg[id] += val;
		lazy[id] += val;
		return;
	}
	down(id);
	int mid = (l + r) >> 1;
	update(id << 1, l, mid, u, v, val);
	update(id << 1 | 1, mid + 1, r, u, v, val);
	seg[id] = seg[id << 1] + seg[id << 1 | 1];
}

int get(int id, int l, int r, int u, int v) {
	if (v < l or r < u) return 0;
	if (u <= l and r <= v) return seg[id];
	down(id);
	int mid = (l + r) >> 1;
	return get(id << 1, l, mid, u, v) + get(id << 1 | 1, mid + 1, r, u, v);
}

namespace sub2 {
	int b[maxn];

	vector<int> val;

	int getidx(const int &x) {
		return lower_bound(all(val), x) - val.begin() + 1;
	}

	void sol() {
		if (n < 3) return cout << 0, void();


		FOR(i, 1, n) {
			val.pb(a[i]);
			// val.pb(a[i] + d);
		}

		sort(all(val));
		val.erase(unique(all(val)), val.end());

		// int m = val[len(val) - 1];
		int m = 200000;
		// cout << val __ ;	
		build(1, 1, m);

		FOR(i, 1, n) {
			// debug(getidx(a[i] + d) - 1);
			b[i] = get(1, 1, m, getidx(a[i] + d), m);
			update(1, 1, m, getidx(a[i]), getidx(a[i]), 1);

			// FOR(j, 1, m) cout << get(1, 1, m, j, j) ___ ;
			// cout __ ;
		}

		// FOR(i, 1, n) cout << b[i] ___ ;
		// cout __ ;

		build(1, 1, m);
		int ans = 0;
		FOR(i, 1, n) {
			ans += get(1, 1, m, getidx(a[i] + d), m);
			update(1, 1, m, getidx(a[i]), getidx(a[i]), b[i]);
		}

		cout << ans;
	}
};	

void process() {
    cin >> n >> d;
    FOR(i, 1, n) cin >> a[i];

    if (n <= 400) sub1::sol();
    else sub2::sol();

}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("invd.inp", "r")) {
        freopen("invd.inp", "r", stdin);
        freopen("invd.out", "w", stdout);
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
2 8 6 4 2
1 4 3 2 1
===============================*/
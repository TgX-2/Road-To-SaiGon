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

const int maxn = 1e5 + 7;
int n, m, q;
vector<int> g[maxn];

int val[maxn];
int ans[maxn];

vector<int> euler, dep, fir;
void dfsLCA(int u, int pre, int d) {
	fir[u] = len(euler);
	euler.pb(u);
	dep.pb(d);

	for(const int &v : g[u]) if (v != pre) {
		dfsLCA(v, u, d + 1);
		euler.pb(u);
		dep.pb(d);
	}
}

#define mmin(x, y) (dep[x] < dep[y] ? x : y)

int st[maxn << 1][25];
void buildSparseTable() {
	int m = len(euler);
	FOR(i, 0, m - 1) st[i][0] = i;

	for(int j = 1; (1 << j) <= m; j++)
		for(int i = 0; i + (1 << j) <= m; i++)
			st[i][j] = mmin(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int get(int l, int r) {
	int k = __lg(r - l + 1);
	return mmin(st[l][k], st[r - (1 << k) + 1][k]);
}

int getLCA(int u, int v) {
	int l = fir[u], r = fir[v];
	if (l > r) swap(l, r);
	return euler[get(l, r)];

}

void dfs1(int u, int pre) {
	for(const int &v : g[u]) if (v != pre) {
		dfs1(v, u);
		val[u] += val[v];
	}
}

void dfs2(int u, int pre) {
	for(const int &v : g[u]) if (v != pre) {
		ans[v] = ans[u] + val[v];
		dfs2(v, u);
	}
}


void process() {
	cin >> n >> m >> q;
	FOR(i, 2, n) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}    

	fir.assign(n + 7, -1);
	dfsLCA(1, 0, 0);
	buildSparseTable();

	FOR(i, 1, m) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		int k = getLCA(a, b);

		val[a]++;
		val[b]++;
		val[k] -= 2;

		int ac = getLCA(a, c);
		int bc = getLCA(b, c);
		int ad = getLCA(a, d);
		int bd = getLCA(b, d);

		if (ac == k) c = bc;
		else if (bc == k) c = ac;
		else c = k;

		if (ad == k) d = bd;
		else if (bd == k) d = ad;
		else d = k;

		// cout << c _ d __ ; 

		k = getLCA(c, d);

		val[c]--;
		val[d]--;
		val[k] += 2;
	}

	dfs1(1, 0);
	// FOR(i, 1, n) cout << val[i] ___ ;
	// cout __ ;
	ans[1] = val[1];

	dfs2(1, 0);

	// FOR(i, 1, n) cout << ans[i] ___ ;
	// cout __ ;


	FOR(i, 1, q) {
		int u, v; cin >> u >> v;
		int k = getLCA(u, v);
		cout << (ans[u] + ans[v] - 2 * ans[k]) __ ;
	}
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("tree.inp", "r")) {
        freopen("tree.inp", "r", stdin);
        freopen("tree.out", "w", stdout);
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
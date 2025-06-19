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
int n, m;
int ans[maxn];
vector<array<int, 3>> edge, q;

bool cmp1(const array<int, 3> &a, const array<int, 3> &b) {
	return a[2] > b[2];
}

bool cmp2(const array<int, 3> &a, const array<int, 3> &b) {
	return a[0] > b[0];
}

int par[maxn], child[maxn];
void init() {
	FOR(i, 1, n) {
		par[i] = i;
		child[i] = 1;
	}
}

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

int get(int u) {
	return child[find(u)];
}

void merge(int u, int v) {
	int a = find(u), b = find(v);
	if (a == b) return;
	if (child[a] > child[b]) swap(a, b);
	child[a] += child[b];
	par[b] = a;
}

void process() {
    cin >> n >> m;
    FOR(i, 2, n) {
    	int u, v, w; cin >> u >> v >> w;
    	edge.pb({u, v, w});
    }

    sort(all(edge), cmp1);

    FOR(i, 1, m) {
    	int k, v; cin >> k >> v;
    	q.pb({k, v, i});
    }

    sort(all(q), cmp2);

    init();

    int idx = 0;
    // while(1) {
    // 	if (idx > n) break;
    // 	if (edge[0][2] >= q[idx][0]) break;
    // 	idx++;
    // }

    FOR(i, 0, n - 2) {
    	if (i == 0 or edge[i][2] != edge[i - 1][2]) {
    		while(1) {
    			if (idx >= m) break;
    			if (q[idx][0] <= edge[i][2]) break;
    			ans[q[idx][2]] = get(q[idx][1]);
    			idx++;
    		}
    	} 

		// cout << "merge : " << edge[i] __ ;
		merge(edge[i][0], edge[i][1]);
    }

    // debug(idx);
    FOR(i, idx, m - 1) ans[q[i][2]] = get(q[idx][1]);

    FOR(i, 1, m) cout << ans[i] - 1 __ ;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("qkgraph.inp", "r")) {
        freopen("qkgraph.inp", "r", stdin);
        freopen("qkgraph.out", "w", stdout);
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
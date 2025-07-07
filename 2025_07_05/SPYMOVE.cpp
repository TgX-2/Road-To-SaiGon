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
int n, m, k;
int a[maxn], b[maxn];
vector<int> g[maxn];

namespace sub1 {
	int dis[maxn];
	void dijk(int sta) {
		FOR(i, 0, n + 1) dis[i] = intmax;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		q.push({0, sta});
		dis[sta] = 0;

		while(!q.empty()) {
			pair<int, int> top = q.top(); q.pop();
			int cost = top.fi, u = top.se;
			if (cost != dis[u]) continue;

			for(const int &v : g[u]) if (a[v] == -1) {
				if (dis[v] > dis[u] + 1) {	
					dis[v] = dis[u] + 1;
					q.push({dis[v], v});
				}
			}
		}
	}


	void sol() {
		dijk(1);
		FOR(i, 1, n) {
			if (dis[i] == intmax) cout << "-1" ___ ;
			else cout << dis[i] ___ ;
		}
	}
};

void process() {
    cin >> n >> m >> k;
    FOR(i, 1, n) cin >> a[i];

    bool issub1 = 1;
    FOR(i, 1, n) {
    	cin >> b[i];
    	if (b[i] != -1) issub1 = 0;
    }

    FOR(i, 1, m) {
    	int u, v; cin >> u >> v;
    	g[u].pb(v);
    	g[v].pb(u);
    }

    if (a[1] != -1) {
    	FOR(i, 1, n) cout << "-1" ___ ;
    	return;
    }

   	if (issub1 == 1) sub1::sol();
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("SPYMOVE.inp", "r")) {
        freopen("SPYMOVE.inp", "r", stdin);
        freopen("SPYMOVE.out", "w", stdout);
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
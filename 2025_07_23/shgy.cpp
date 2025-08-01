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

const int maxn = 5007;
int n, m;
vector<int> g[maxn];
char typ[maxn];

int dis[maxn][maxn];
void dijk(int sta) {
	FOR(i, 0, n + 1) dis[sta][i] = llongmax;
	dis[sta][sta] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({0, sta});
	while(!q.empty()) {
		pair<int, int> top = q.top(); q.pop();
		int cost = top.fi, u = top.se;
		if (cost != dis[sta][u]) continue;
		for(const int &v : g[u]) {
			int w = (typ[sta] == typ[v] ? 1 : 4);
			if (dis[sta][v] > dis[sta][u] + w) {
				dis[sta][v] = dis[sta][u] + w;
				q.push({dis[sta][v], v});
			}
		}
	}
}

void process() {
    cin >> n >> m;
    vector<int> a, b;
    FOR(i, 1, n) {
    	cin >> typ[i];
    	if (typ[i] == 'G') a.pb(i);
    	else b.pb(i);
    }

    FOR(i, 1, m) {
    	int u, v; cin >> u >> v;
    	g[u].pb(v);
    	g[v].pb(u);
    }

    FOR(i, 1, n) dijk(i);

    int ansa = 0;
    FOR(i, 0, len(a) - 2) FOR(j, i + 1, len(a) - 1) ansa += dis[a[j]][a[i]];
    int ansb = 0;
    FOR(i, 0, len(b) - 2) FOR(j, i + 1, len(b) - 1) ansb += dis[b[j]][b[i]];

    cout << ansa _ ansb __ ;

}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("shgy.inp", "r")) {
        freopen("shgy.inp", "r", stdin);
        freopen("shgy.out", "w", stdout);
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
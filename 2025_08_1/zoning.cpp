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
int deg[maxn];
vector<int> g[maxn];
unordered_map<int, bool> f[maxn];

int scc = 0, cnt = 0, low[maxn], num[maxn];
bool deleted[maxn];
stack<int> s;

pair<int, int> sccdeg[maxn];

// void cal(const vector<int> &v)  {
// 	vector<int> deg(n + 7, 0);
// 	// cout << v __ ;
// 	if (len(v) == 1) {
// 		sccdeg[v[0]] = {v[0], 1};
// 		return;
// 	}

// 	int aa = len(v);
// 	for(int i = 0; i <= len(v) - 2; i++) for(int j = i + 1; j <= len(v) - 1; j++) {
// 		if (f[v[i]][v[j]] == 1) {
// 			// cout << i << "->" << j __ ;
// 			deg[i]++;
// 			deg[j]++;
// 			sccdeg[v[i]] = {v[i], deg[i]};
// 			sccdeg[v[j]] = {v[j], deg[j]};
// 		}
// 	}
// }


bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.se > b.se;
}

// void dfs(int u, int pre) {
//     low[u] = num[u] = ++cnt;
//     s.push(u);
//     for(const int &v : g[u]) if (v != pre) {
//         if (deleted[v]) continue;
//         if (num[v]) mini(low[u], num[v]);
//         else {
//             dfs(v, u);
//             mini(low[u], low[v]);
//         }
//     }
//     if (low[u] == num[u]) {
//         scc++;
//         int v;
//         vector<int> vv;
//         do {
//             v = s.top(); 
//             vv.pb(v);
//             s.pop();
//             deleted[v] = 1;
//         } while(v != u);
//         cal(vv);
//     }
// }

int child[maxn], par[maxn];
bool vis[maxn];

void init()  {
	FOR(i, 1, n) {
		par[i] = i;
		child[i] = 1;
	}
}

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

void merge(int u, int v) {
	int a = find(u);
	int b = find(v);
	if (a == b) return;
	if (child[a] < child[b]) swap(a, b);
	child[a] += child[b];
	par[b] = a;
}

bool is[maxn];
void build() {
	set<pair<int, int>> s;
	FOR(i, 1, n) s.insert({deg[i], i});

	// cout << s __ ;
	int idx = 0;
	while(!s.empty()) {
		pair<int, int> top = *s.begin(); s.erase(s.begin());
		sccdeg[++idx] = {top.se, top.fi};

		int v = top.se, cnt = top.fi;
		is[v] = 1;

		for(const int &u : g[v]) if (is[u] == 0) {
			s.erase({deg[u], u});
			deg[u]--;
			s.insert({deg[u], u});
		}
	}
}

void process() {
    cin >> n >> m;
    FOR(i, 1, m) {
    	int u, v; cin >> u >> v;
    	g[u].pb(v); 
    	g[v].pb(u); 
    	deg[u]++;
    	deg[v]++;
    	f[u][v] = f[v][u] = 1;
    }

    // FOR(i,1,n) if (!num[i]) {
    //     dfs(i, i);
    // }

    build();

    // sort(sccdeg + 1, sccdeg + 1 + n, cmp);
    FOR(i, 1, n) cout << sccdeg[i] __ ;

    // return;

    init();
    int ans = llongmin;
    FORD(i, n, 1) {
    	int v = sccdeg[i].fi, cnt = sccdeg[i].se;
    	// cout << v _ cnt __ ;
    	vis[v] = 1;

    	for(const int &u : g[v]) {
    		if (vis[u] == 0) continue;
    		merge(u, v);
    		// cout << v _ u _ cnt _ child[find(v)] __ ;	
    		maxi(ans, cnt * child[find(v)]); 
    	}
    }
    // FOR(i, 1, n) cout << child[i] ___ ; cout __ ;
    cout << ans;
}


/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("zoning.inp", "r")) {
        freopen("zoning.inp", "r", stdin);
        freopen("zoning.out", "w", stdout);
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
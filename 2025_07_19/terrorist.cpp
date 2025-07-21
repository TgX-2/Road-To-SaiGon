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
int n, m;
vector<int> g[maxn];
int cntedge[maxn];

class LCA {
private:
    vector<int> euler, dep, fir, val, ans;
    vector<vector<int>> st;
    int n;
    vector<int> h;

    void dfs(int u, int pre, int d, const vector<int> g[]) {
        fir[u] = len(euler);
        euler.pb(u);
        dep.pb(d);
        h[u] = h[pre] + 1;

        val[u] = val[pre] + 1;
        ans[u] = ans[pre] + cntedge[u];

        for(const int &v : g[u]) if (v != pre) {
            dfs(v, u, d + 1, g);
            euler.pb(u);
            dep.pb(d);
        }
    }

    #define mmin(x, y) (dep[x] < dep[y] ? x : y)

    void buildSparseTable() {
        int m = len(dep);
        int maxK = log2(m) + 7;
        st.assign(m + 7, vector<int>(maxK));
        FOR(i, 0, m - 1) st[i][0] = i;

        for(int j = 1; (1 << j) <= m; j++) {
            for(int i = 0; i + (1 << j) <= m; i++) {
                st[i][j] = mmin(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int getSparseTable(int l, int r) {
        int k = r - l + 1;
        int logK = log2(k);
        return mmin(st[l][logK], st[r - (1 << logK) + 1][logK]);
    }

public:
    LCA(int _n, int root, const vector<int> g[]) {
    	n = _n;
        fir.assign(n + 7, -1);
        h.assign(n + 7, 0);
        val.assign(n + 7, 0);
        ans.assign(n + 7, 0);
        dfs(root, 0, 0, g);
        buildSparseTable();
    }

    int getDis(int u, int v) {
        int k = getLCA(u, v);
        return h[u] + h[v] - 2 * h[k];
    }

    int getLCA(int u, int v) {
        int l = fir[u];
        int r = fir[v];
        if (l > r) swap(l, r);
        return euler[getSparseTable(l, r)];
    }

    int getVal(int u, int v) {
    	int k = getLCA(u, v);
    	return val[u] + val[v] - 2 * val[k];
    }

    int getAns(int u, int v) {
    	int k = getLCA(u, v);
    	return ans[u] + ans[v] - 2 * ans[k];
    }
};

namespace sub12 {
	void sol() {
		LCA lca(n, 1, g);
		int q; cin >> q;
		while(q--) {
			int u, v; cin >> u >> v;
			int ans = lca.getVal(u, v);
			cout << ans _ ans __ ;	
		}
	}
};	

namespace sub34 {
	int scc = 0, cnt = 0, low[maxn], num[maxn];
	bool deleted[maxn];
	stack<int> s;

	int idx[maxn];
	unordered_set<int> tmp[maxn];
	vector<int> cg[maxn];

	void dfs(int u, int pre) {
	    low[u] = num[u] = ++cnt;
	    s.push(u);
	    for(const int &v : g[u]) if (v != pre) {
	        if (deleted[v]) continue;
	        if (num[v]) mini(low[u], num[v]);
	        else {
	            dfs(v, u);
	            mini(low[u], low[v]);
	        }
	    }
	    if (low[u] == num[u]) {
	        scc++;
	        int v;
	        do {
	            v = s.top();
	            idx[v] = scc;
	            s.pop();
	            deleted[v] = 1;
	        } while(v != u);
	    }
	}

	void sol() {
		dfs(1, 0);

		int m = scc;
		FOR(i, 1, n) {
			for(const int &j : g[i]) {
				if (idx[i] != idx[j]) tmp[idx[i]].insert(idx[j]);
				else cntedge[idx[i]]++;
			}
		}

		FOR(i, 1, m) cntedge[i] /= 2;

		FOR(i, 1, m) for(const int &j : tmp[i])
			cg[i].pb(j);

		LCA lca(m, 1, cg);

		int q; cin >> q;
		while(q--) {
			int u, v; cin >> u >> v;
			u = idx[u];
			v = idx[v];

			int ansa = lca.getVal(u, v);
			int ansb = ansa + lca.getAns(u, v);

			if (u == v) ansb += cntedge[u];

			cout << ansa _ ansb __ ;
		}
	}
};


void process() {
    cin >> n >> m;
    FOR(i, 1, m) {
    	int u, v; cin >> u >> v;
    	g[u].pb(v);
    	g[v].pb(u);
    }

    if (m == n - 1) sub12::sol();
    else sub34::sol();
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("terrorist.inp", "r")) {
        freopen("terrorist.inp", "r", stdin);
        freopen("terrorist.out", "w", stdout);
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
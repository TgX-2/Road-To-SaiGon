// /*-----------------------------
//         Author : TgX.2
//        11Ti - K28 - CHV
// -----------------------------*/

// #include <bits/stdc++.h>
// using namespace std;

// #ifdef TGX
// #include "D:\egoist\debug.h"
// #else 
// #define debug(...)
// #endif

// #define FOR(i, a, b)       for (int i = (a), _b = (b); i <= _b; i += 1)
// #define FORD(i, a, b)      for (int i = (a), _b = (b); i >= _b; i -= 1)

// #define fi                 first
// #define se                 second
// #define pb                 push_back
// #define len(x)             (int)((x).size())
// #define all(x)             (x).begin(), (x).end()

// #define _                  << " " <<
// #define __                 << "\n"
// #define ___                << " "

// #define ______________TgX______________ main()
// #define int                long long
// #define intmax             1e9
// #define intmin            -1e9
// #define llongmax           1e18
// #define llongmin          -1e18
// #define memo(a, val)       memset((a), (val), sizeof((a)))

// template<typename T1, typename T2> bool mini(T1 &a, T2 b)
//     {if (a > b) a = b; else return 0; return 1;}

// template<typename T1, typename T2> bool maxi(T1 &a, T2 b)
//     {if (a < b) a = b; else return 0; return 1;}
// /*-----------------------------*/

// const int maxn = 2e5 + 7;
// int n, m, q, a[maxn];
// vector<int> g[maxn];
// vector<array<int, 3>> edge;

// int child[maxn], par[maxn];
// void init() {
// 	FOR(i, 1, n) {
// 		child[i] = 1;
// 		par[i] = i;
// 	}
// }

// int find(int u) {
// 	return (u == par[u] ? u : par[u] = find(par[u]));
// }

// bool merge(int u, int v) {
// 	int a = find(u);
// 	int b = find(v);
// 	if (a == b) return 0;
// 	if (child[a] > child[b]) swap(a, b);
// 	child[a] += child[b];
// 	par[b] = a;
// 	return 1;
// }

// // struct HeavyLightDecomposition {
// //     int child[maxn], par[maxn];
// //     int hld[maxn], hldd[maxn], dep[maxn], id[maxn], fin[maxn], sta[maxn];
// //     int inn[maxn], out[maxn];
// //     int cnt = 1, cntt = 0, n;
    
// //     void dfs(int u, int pre) {
// //         child[u] = 1;
// //         par[u] = pre;
// //         for(int v : g[u]) if (v != pre) {
// //             dfs(v, u);
// //             child[u] += child[v];
// //         }
// //     }

// //     void build_hld(int u, int pre, bool inchain) {
// //         hldd[u] = hldd[pre];
// //         if (!inchain) hldd[u]++;
// //         dep[u] = dep[pre] + 1;

// //         hld[cnt] = u;
// //         id[u] = cnt;        
// //         sta[u] = cnt++;
// //         if (inchain) sta[u] = sta[pre];

// //         inn[u] = ++cntt;

// //         int c = -1;
// //         for(int v : g[u]) if (v != pre) 
// //             if (c == -1 or child[v] > child[c])
// //                 c = v;
        
// //         if (c != -1)
// //             build_hld(c, u, 1);
// //         for(int v : g[u]) if (v != pre and v != c)
// //             build_hld(v, u, 0);

// //         if (c == -1) fin[u] = cnt - 1;
// //         else fin[u] = fin[c];

// //         out[u] = cntt;
// //     }

// //     int hldpar(int u) {
// //         return par[hld[sta[u]]];
// //     }
    
// //     int hldpos(int u) {
// //         return id[hld[sta[u]]];
// //     }

// //     int lca(int u, int v) {
// //         if (hldd[v] > hldd[u]) swap(u, v);
// //         while(hldd[u] > hldd[v])
// //             u = hldpar(u);
// //         while(sta[u] != sta[v]) {
// //             u = hldpar(u);
// //             v = hldpar(v);
// //         }

// //         if (dep[u] > dep[v])
// //             swap(u, v);
// //         return u;
// //     }

// //     void build() {
// //         dfs(1, 0);
// //         build_hld(1, 0, 0);
// //     }
// // } hld;

// // int f(int a, int b) {
// // 	return max(a, b);
// // }

// // struct SegmentTreeLazy {
// //     struct Node {
// //         int val, lazy;
// //     };
// //     Node seg[maxn << 2];
// //     void down(int id) {
// //         int x = seg[id].lazy;
// //         seg[id << 1].val += x;
// //         seg[id << 1].lazy += x;
// //         seg[id << 1 | 1].val += x;
// //         seg[id << 1 | 1].lazy += x;
// //         seg[id].lazy = 0;
// //     }

// //     void build(int id, int l, int r, int data[], int f(int, int)) {
// //         if (l == r) return seg[id].val = data[hld.hld[l]], void();
// //         int mid = (l + r) >> 1;
// //         build(id << 1, l, mid, data, f);
// //         build(id << 1 | 1, mid + 1, r, data, f);
// //         seg[id].val = f(seg[id << 1].val, seg[id << 1 | 1].val);
// //     }

// //     int get(int id, int l, int r, int u, int v, int f(int, int)) {
// //         if (v < l or r < u) return intmin;
// //         if (u <= l and r <= v) return seg[id].val;
// //         down(id);
// //         int mid = (l + r) >> 1;
// //         return f(get(id << 1, l, mid, u, v, f), get(id << 1 | 1, mid + 1, r, u, v, f));
// //     }

// //     int get(int l, int r, int f(int, int)) {
// //         return get(1, 1, n, l, r, f);
// //     }

// // } st;

// // int q_get(int u, int v, int f(int, int)) {
// // 	int k = hld.lca(u, v);
// // 	// cout << k __ ;
// // 	int ans = intmin;
// // 	while(hld.sta[u] != hld.sta[k]) {
// // 		// debug(u);
// // 		ans = f(ans, st.get(hld.hldpos(u), hld.id[u], f));
// // 		u = hld.hldpar(u);
// // 	}
// // 	while(hld.sta[v] != hld.sta[k]) {
// // 		// debug(v);
// // 		ans = f(ans, st.get(hld.hldpos(v), hld.id[v], f));
// // 		v = hld.hldpar(v);
// // 	}
// // 	if (hld.dep[u] < hld.dep[v])
// // 		ans = f(ans, st.get(hld.id[u], hld.id[v], f));
// // 	else  
// // 		ans = f(ans, st.get(hld.id[v], hld.id[u], f));
// // 	return ans;
// // }

// vector<int> euler, dep, fir;
// vector<vector<int>> st;
// vector<int> h;
// int cnt = 0;
// int inn[maxn], out[maxn];

// void dfs(int u, int pre, int d) {
// 	par[u] = pre;
// 	inn[u] = ++cnt;
// 	child[u] = 1;
//     fir[u] = len(euler);
//     euler.pb(u);
//     dep.pb(d);
//     h[u] = h[pre] + 1;
    
//     for(const int &v : g[u]) if (v != pre) {
//         dfs(v, u, d + 1);
//         child[u] += child[v];
//         euler.pb(u);
//         dep.pb(d);
//     }
//     out[u] = cnt;
// }

// #define mmin(x, y) (dep[x] < dep[y] ? x : y)

// void buildSparseTable() {
//     int m = len(dep);
//     int maxK = log2(m) + 7;
//     st.assign(m + 7, vector<int>(maxK));
//     FOR(i, 0, m - 1) st[i][0] = i;

//     for(int j = 1; (1 << j) <= m; j++) {
//         for(int i = 0; i + (1 << j) <= m; i++) {
//             st[i][j] = mmin(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
//         }
//     }
// }

// int getSparseTable(int l, int r) {
//     int k = r - l + 1;
//     int logK = log2(k);

//     return mmin(st[l][logK], st[r - (1 << logK) + 1][logK]);
// }

// int getLCA(int u, int v) {
//     int l = fir[u];
//     int r = fir[v];
//     if (l > r) swap(l, r);
//     return euler[getSparseTable(l, r)];
// }

// int getDis(int u, int v) {
//     int k = getLCA(u, v);
//     return h[u] + h[v] - 2 * h[k];
// }

// bool cmp(const int &u, const int &v) {
// 	return inn[u] < inn[v];	
// }

// bool inside(const int &u, const int &v) {
// 	return inn[u] <= inn[v] and out[v] <= out[u];
// }
	
// vector<int> minig[maxn];
// int b[maxn];
// stack<int> stac;

// void compress(int l, int r) {
// 	int k = (r - l + 1);
// 	FOR(i, 1, k) b[i] = l + i - 1;

//     sort(b + 1, b + 1 + k, cmp);
    
//     FOR(i, 1, k - 1) b[i+k] = getLCA(b[i], b[i + 1]);
   

//     k = 2 * k - 1; 
//     sort(b + 1, b + 1 + k, cmp); 
//     k = unique(b + 1, b + 1 + k) - b - 1; 

//     while(!stac.empty()) stac.pop();
//     stac.push(b[1]);
          
//     for(int i = 2; i <= k; ++i){
//         while(!inside(stac.top(), b[i])){
//             stac.pop();
//         }
//         minig[stac.top()].push_back(b[i]);
//         stac.push(b[i]);
//     }

//    	FOR(i, 1, k) {
//    		cout << minig[b[i]] __ ;
//         minig[b[i]].clear(); 
//    	}
    
// }

// void process() {
//     cin >> n >> m >> q;
//     if (n > 50) return;

//     init();

//     FOR(i, 1, m) {
//     	int u, v; cin >> u >> v;
//     	if (merge(u, v)) {
//     		edge.pb({u, v, i});
//     		// cout << u _ v _ i __ ;
//     		g[u].pb(v);
//     		g[v].pb(u);
//     	}
//     }

//     memo(child, 0);
//     memo(par, 0);

//     fir.assign(n + 7, -1);
//     h.assign(n + 7, 0);
//     dfs(1, 0, 0);
//     buildSparseTable();
    
//     // hld.build();

//     for (const array<int, 3> &val : edge) {
//     	int u = val[0], v = val[1], w = val[2];
//     	// cout << u _ v _ w __ ;
//     	if (par[u] == v) a[u] = w;
//     	else a[v] = w;
//     }

//     while(q--){
//     	int l, r; cin >> l >> r;
//     	compress(l, r);
//     }

//     // st.build(1, 1, n, a, f);
//     // cout << st.get(1, 2, f) __ ;

//     // while(q--)  {
//     // 	int u, v; cin >> u >> v;
//     // 	if (u == v) cout << 0 ___ ;
//     // 	else {
//     // 		int ans = q_get(u, v, f);
//     // 		if (ans == intmin) cout << 0 ___ ;
//     // 		else cout << ans ___ ;
//     // 	}
//     // }


//     // FOR(i, 1, n) cout << a[i] ___ ;
    
// }



// /*-----------------------------*/
// ______________TgX______________ {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);  
//     if (fopen("chiso.inp", "r")) {
//         freopen("chiso.inp", "r", stdin);
//         freopen("chiso.out", "w", stdout);
//     }
//     process();
//     cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC __ ;
// }


// /*==============================+
// |INPUT                          |
// --------------------------------|

// ================================+
// |OUTPUT                         |
// --------------------------------|

// ===============================*/

/*-----------------------------
        Author : TgX.2
       11Ti - K28 - CHV
-----------------------------*/

#include <bits/stdc++.h>
using   namespace std;

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

struct custom {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template<class T1, class T2> using cmap = unordered_map<T1, T2, custom>;

template<typename T1, typename T2> 
bool mini(T1 &a, T2 b)
    {if (a > b) a = b; else return 0; return 1;}

template<typename T1, typename T2> 
bool maxi(T1 &a, T2 b)
    {if (a < b) a = b; else return 0; return 1;}
/*-----------------------------*/

const int maxn = 2e5 + 7;
int n, m, q, a[maxn];
vector<int> g[maxn];

int child[maxn], par[maxn];
void init() {
	FOR(i, 1, n) {
		child[i] = 1;
		par[i] = i;
		g[i].pb(i);
	}
}

int find(int u) {
	return (u == par[u] ? u : par[u] = find(par[u]));
}

int tar;

void bui(int u, int v) {
	for(const int &k : g[v]) {
		if (k - 1 >= 1 and find(k - 1) == u) a[k - 1] = tar;
		if (k + 1 <= n and find(k + 1) == u) a[k]     = tar;
		g[u].pb(k);
	}
}

void merge(int u, int v) {
	int a = find(u);
	int b = find(v);
	if (a == b) return;
	if (child[a] < child[b]) swap(a, b);

	bui(a, b);

	child[a] += child[b];
	par[b] = a;
}

int st[maxn][25];
void build() {
	FOR(i, 1, n) st[i][0] = a[i];
	for(int j = 1; (1 << j) <= n; j++) 
		for(int i = 1; i + (1 << j) - 1 <= n; i++)
			st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int get(int l, int r) {
	int k = __lg(r - l + 1);
	return max(st[l][k], st[r - (1 << k) + 1][k]);
}

void process() {
	cin >> n >> m >> q;
	init();
	FOR(i, 1, m) {
		int u, v; cin >> u >> v;
		tar = i;
		merge(u, v);
	}	

	// FOR(i, 1, n) cout << a[i] ___ ; cout __ ;

	build();
	while(q--) {
		int u, v; cin >> u >> v;
		if (u == v) cout << 0 ___ ;
		else cout << get(u, v - 1) ___ ;
	}
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    if (fopen("chiso.inp", "r")) {
        freopen("chiso.inp", "r", stdin);
        freopen("chiso.out", "w", stdout);
    }
    process();
    cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." __ ;
}

1 0
1 2
0 1

i > j 
j > k 
k < i

/*==============================+
|INPUT                          |
--------------------------------|

================================+
|OUTPUT                         |
--------------------------------|

===============================*/

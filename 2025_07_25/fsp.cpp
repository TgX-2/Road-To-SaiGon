#include<bits/stdc++.h>
using namespace std;
#define int long long

#ifdef TGX
#include "D:\egoist\debug.h"
#else 
#define debug(...)
#endif

const int maxn = 80007;
int n;
vector<pair<int, int>> g[maxn];

int dp[maxn];
bool vis[maxn];

int child[maxn];
int dfs(int u, int pre) {
    child[u] = 1;
    for(const pair<int, int> &val : g[u]) {
        int v = val.first, w = val.second;
        if (v == pre or vis[v]) continue;
        child[u] += dfs(v, u);
    }
    return child[u];
}

int fivecent(int u, int pre, int total) {
    for(const pair<int, int> &val : g[u]) {
        int v = val.first, w = val.second;
        if (v == pre or vis[v]) continue;
        if (child[v] > total / 2) return fivecent(v, u, total);
    }
    return u;
}

vector<pair<int, int>> centdist[maxn];
void app(int u, int pre, int dist, int cent) {
    centdist[u].push_back({cent, dist});
    for(const pair<int, int> &val : g[u]) {
        int v = val.first, w = val.second;
        if (v == pre or vis[v]) continue;
        app(v, u, dist + w, cent);
    }
}

void build(int u, int pre) {
    int total = dfs(u, 0);
    int cent = fivecent(u, 0, total);
    if (pre == 0) pre = cent;

    vis[cent] = 1;

    app(cent, 0, 0, cent);
    for(const pair<int, int> &val : g[u]) {
        int v = val.first, w = val.second;
        if (!vis[v]) build(v, cent);
    }
}

unordered_map<int, int> best;

void ins(int u) {
    for(const pair<int, int> &val : centdist[u]) {
        int cent = val.first, dist = val.second;
        int candidate = dp[u] + dist;
        if (!best.count(cent) or candidate < best[cent]) 
            best[cent] = candidate;
    }
}

int get(int u) {
    int ans = 1e18;
    for(const pair<int, int> &val : centdist[u]) {
        int cent = val.first, dist = val.second;
        if (best.count(cent)) ans = min(ans, best[cent] + dist);
    }
    return ans;
}

void process() {
    cin >> n;
    for(int i = 2; i <= n; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    build(1, 0);

    for(int i = 0; i <= n + 1; i++) dp[i] = 1e18;
    dp[1] = 0;
    
    ins(1);
    for(int i = 2; i <= n; i++) {
        dp[i] = get(i);
        ins(i);
    }


    for(int i = 1; i <= n; i++) {
        if (dp[i] >= 1e18 / 2) cout << 0 << " ";
        else cout << dp[i] << " ";
    }
    
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("temp.inp", "r")) {
        freopen("temp.inp", "r", stdin);
        freopen("temp.out", "w", stdout);
    } else {
        freopen("fsp.inp", "r", stdin);
        freopen("fsp.out", "w", stdout);
    }
    process();
    cerr << "Time : " << clock() * 1.0 / CLOCKS_PER_SEC << " ms.\n";
}
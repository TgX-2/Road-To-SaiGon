#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 20007;

int n, m, k;
int s1, s2, t;

vector<pair<int, int>> g[maxn]; 
int st[maxn], l[maxn], r[maxn];
bool used[maxn];

vector<array<int, 3>> specedge;

int d1[maxn], d2[maxn];

void dijk(int start, int d[]) {
	for(int i = 0; i <= n + 1; i++) d[i] = 1e18;
    d[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, start});

    while (!q.empty()) {
        pair<int, int> top = q.top(); q.pop();
        int dist_u = top.first;
        int u = top.second;

        if (dist_u != d[u]) continue;

        for(const pair<int, int> &val : g[u]) {
        	int v = val.first, w = val.second;

            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
}

main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if (fopen("temp.inp", "r")) {
        freopen("temp.inp", "r", stdin);
        freopen("temp.out", "w", stdout);
    }

    cin >> n >> m >> k >> s1 >> s2 >> t;

    for(int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
    }

    for (int i = 1; i <= k; ++i) {
        int u, v; cin >> u >> v >> l[i] >> r[i];
        st[i] = u;

        int idx = (int)(g[u].size());
        g[u].push_back({v, r[i]});
        specedge.push_back({u, idx, r[i]});
    }

    while (1) {
        dijk(s1, d1);
        dijk(s2, d2);

        bool changed = 0;

        for (int i = 1; i <= k; ++i) {
            if (!used[i] and d1[st[i]] <= d2[st[i]]) {
                used[i] = 1;

                int u = specedge[i - 1][0];
                int idx = specedge[i - 1][1];

                g[u][idx].second = l[i];
                changed = 1;
            }
        }

        if (!changed) break;
    }

    if (d1[t] < d2[t]) {
        cout << "WIN\n";
    } else if (d1[t] > d2[t]) {
        cout << "LOSE\n";
        return 0;
    } else {
        cout << "DRAW\n";
    }

    for (int i = 1; i <= k; ++i) {
        int u = specedge[i - 1][0];
        int idx = specedge[i - 1][1];
        cout << g[u][idx].second << " ";
    }
    cout << '\n';

    cerr << "Time : " << clock() * 1.0 / CLOCKS_PER_SEC << " ms." << endl;
    return 0;
}

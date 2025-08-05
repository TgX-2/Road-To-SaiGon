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

const int maxn = 2007;
const int mod  = 1e9 + 7;
int n, k;
string a[maxn];

bool check(const string &a, const string &b) {
	bool is = 0;
	FOR(i, 0, len(a) - 1) {
		if (a[i] != b[i]) {
			if (is == 1) return 0;
			is = 1;
		}
	}
	return 1;
}

vector<int> g[maxn];

int dis[maxn], cnt[maxn];

void bfs() {
	FOR(i, 1, n - 1) FOR(j, i + 1, n) {
		if (check(a[i], a[j])) {
			g[i].pb(j);
			g[j].pb(i);
		}
	}

	FOR(i, 0, n + 1) dis[i] = -1;
	dis[1] = 0;
	cnt[1] = 1;

    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(const int &v : g[u]){
            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                cnt[v] = cnt[u];
                q.push(v);
            } else if(dis[v] == dis[u] + 1) {
            	cnt[v] += cnt[u];
            	cnt[v] %= mod;
            }
        }
    }

    if (dis[n] == -1) return cout << "-1 -1", void();

    cout << dis[n] ___ ;
    if (cnt[n] == 0) cout << -1;
    else cout << cnt[n];
}

void process() {
    cin >> n >> k;
    cin >> a[1] >> a[n + 2];
    if (a[1] == a[n + 2]) return cout << 0 _ 1, void();
    
    FOR(i, 2, n + 1) cin >> a[i];
    n += 2;
    bfs();
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("cconvert.inp", "r")) {
        freopen("cconvert.inp", "r", stdin);
        freopen("cconvert.out", "w", stdout);
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
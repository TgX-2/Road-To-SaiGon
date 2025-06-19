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
#define FORC(i, a, b, c)   for (int i = (a), _b = (b), _c = (c); i <= _b; i += _c)

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

const int maxn = 7e4 + 7;
int n, k;
vector<int> g[maxn];
int deg[maxn];

int dis[maxn];
void build(int u, int pre) {
    if (deg[u] == 1) return;
    dis[u] = n;

    for(const int &v : g[u]) if (v != pre) {
        build(v, u);
        mini(dis[u], dis[v] + 1);
    }
}

int dp(int u, int pre, int d) {
    if (d >= dis[u]) return 1;

    int ans = 0;
    for(const int &v : g[u]) if (v != pre)
        ans += dp(v, u, d + 1);
    return ans;
}

void process() {
    cin >> n;

    FOR(i, 2, n) {
        int x, y; cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
        deg[x]++;
        deg[y]++;
    }

    FOR(k, 1, n) {
    	memo(dis, 0);
	    build(k, -1);
	    cout << dp(k, -1, 0) __ ;
    }
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    if (fopen("tentrom.inp", "r")) {
        freopen("tentrom.inp", "r", stdin);
        freopen("tentrom.out", "w", stdout);
    }
    process();
    cerr << "Time : " << clock() * 1.0 / CLOCKS_PER_SEC << "s\n";
}


/*==============================+
|INPUT                          |
--------------------------------|

================================+
|OUTPUT                         |
--------------------------------|

===============================*/
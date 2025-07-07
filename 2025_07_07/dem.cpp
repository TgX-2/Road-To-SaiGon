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

const int maxn = 407;
int n;
pair<int, int> a[maxn];
bool is[4007][4007];

void process() {
    cin >> n;
    vector<int> val;

    FOR(i, 1, n) {
    	int x, y; cin >> x >> y;
    	val.pb(x); val.pb(y);
    	a[i] = {x, y};
    }
    sort(all(val));
    val.erase(unique(all(val)), val.end());

    FOR(i, 1, n) {
    	a[i].fi = lower_bound(all(val), a[i].fi) - val.begin();
    	a[i].se = lower_bound(all(val), a[i].se) - val.begin();
    	is[a[i].fi][a[i].se] = 1;
    }

    int ans = 0;

    FOR(i, 1, n - 1) FOR(j, i + 1, n) {
    	if (is[a[i].fi][a[j].se] == 1 and is[a[j].fi][a[i].se] == 1) {
    		if (a[i].fi != a[j].fi and a[i].se != a[j].se) 
    			ans++;
    			// cout << a[i] _ a[j] __ ;
    	}
    }

    cout << ans / 2;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("dem.inp", "r")) {
        freopen("dem.inp", "r", stdin);
        freopen("dem.out", "w", stdout);
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
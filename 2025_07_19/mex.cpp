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


void process() {
    int t; cin >> t;

    while(t--){
        int m, n; cin >> m >> n;
        int total = m * n;

        vector<pair<int, int>> pos(total, {-1, -1});
    
        FOR(i, 0, m - 1) FOR(j, 0, n - 1) {
            int x; cin >> x;
            if(0 <= x and x < total)
                pos[x] = {i, j};
        }
    
        int miss = 0;
        while(miss < total and pos[miss].fi != -1)
            miss++;
        
        set<pair<int, int>> s;
        int ans = miss;
        FOR(i, 0, miss - 1) {
            int r = pos[i].fi;
            int c = pos[i].se;

            auto it = s.lower_bound({r, c});
            if(it != s.begin()){
                auto itl = prev(it);
                if(itl->se > c){
                    ans = i;
                    break;
                }
            }

            if(it != s.end()){
                auto itr = it;
                if(itr->se < c){
                    ans = i;
                    break;
                }
            }
            s.insert({r, c});
        }
        cout << ans __ ;
    }
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("mex.inp", "r")) {
        freopen("mex.inp", "r", stdin);
        freopen("mex.out", "w", stdout);
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
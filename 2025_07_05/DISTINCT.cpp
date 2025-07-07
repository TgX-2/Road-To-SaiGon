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

const int maxn = 1e6 + 7;

int n;
string s;

namespace sub1 {
    map<string, int> cnt;

    string compress(int l, int r) {
        vector<char> app;
        FOR(i, l, r) app.pb(s[i]);
        sort(all(app));
        app.erase(unique(all(app)), app.end());
        string ans = "";
        for(const char &val : app) ans = ans + val;
        return ans;
    }

    void sol() {
        s = " " + s;
        FOR(i, 1, n) FOR(j, i, n) {
            string f = compress(i, j);
            cnt[f]++;
        }

        cout << len(cnt) + 1;
    }
};

const int mmask = (1 << 26);
namespace subful {
    vector<bool> is(mmask, 0);

    void sol() {
        is[0] = 1;
        int cnt = 1;

        if (n == 0) return cout << 1, void();


        vector<vector<int>> nextt(26, vector<int>(n + 7, n));
        FOR(c, 0, 25) {
            char target = 'a' + c;
            int last = n;
            FORD(i, n - 1, 0) {
                if (s[i] == target)
                    last = i;
                
                nextt[c][i] = last;
            }
        }

        FOR(l, 0, n - 1) {
            vector<bool> seen(26, 1);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

            FOR(c, 0, 25) {
                int pos = nextt[c][l + 1];
                if (pos < n)
                    q.push({pos, c});
            }

            int mask = 0;
            int c0 = s[l] - 'a';
            mask |= (1 << c0);
            seen[c0] = 0;

            while (!q.empty() and !seen[q.top().se]) q.pop();

            if (!is[mask]) {
                is[mask] = 1;
                ++cnt;
            }

            while (!q.empty()) {
                pair<int, int> top = q.top(); q.pop();
                int pos = top.fi;
                int c_letter = top.se;

                mask |= (1 << c_letter);
                seen[c_letter] = 0;

                while (!q.empty() and !seen[q.top().se]) q.pop();
        

                if (!is[mask]) {
                    is[mask] = 1;
                    cnt++;
                }
            }
        }

        cout << cnt __ ;
    }

};

void process() {
    cin >> s;
    n = len(s);

    // sub1::sol();    
    subful::sol();
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("DISTINCT.inp", "r")) {
        freopen("DISTINCT.inp", "r", stdin);
        freopen("DISTINCT.out", "w", stdout);
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
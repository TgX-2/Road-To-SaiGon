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

const int maxn = 1007;
int n, m, b, a[maxn][maxn];

int mmax[maxn][maxn], mmin[maxn][maxn];

void process() {
    cin >> n >> m >> b;
    FOR(i, 1, n) FOR(j, 1, m) cin >> a[i][j];

    FOR(i, 0, n + 1) FOR(j, 0, m + 1) {
    	mmax[i][j] = llongmin;
    	mmin[i][j] = llongmax;
    }

    FOR(i, 1, m) {
    	mmax[0][i] = b;
    	mmin[0][i] = b;
    }

    FOR(i, 1, n) FOR(j, 1, m) {
    	if (j != 1) {
    		if (a[i][j] == 0) {
    			maxi(mmax[i][j], (mmax[i - 1][j - 1] + 1) / 2);
    			mini(mmin[i][j], (mmin[i - 1][j - 1] + 1) / 2);
    		} else {
				maxi(mmax[i][j],  mmax[i - 1][j - 1] + a[i][j]);
				mini(mmin[i][j],  mmin[i - 1][j - 1] + a[i][j]);
    		}   
    	}

		if (a[i][j] == 0) {
			maxi(mmax[i][j], (mmax[i - 1][j] + 1) / 2);
			mini(mmin[i][j], (mmin[i - 1][j] + 1) / 2);
		} else {
			maxi(mmax[i][j],  mmax[i - 1][j] + a[i][j]);
			mini(mmin[i][j],  mmin[i - 1][j] + a[i][j]);
		}   
    	
    	if (j != m) {
    		if (a[i][j] == 0) {
    			maxi(mmax[i][j], (mmax[i - 1][j + 1] + 1) / 2);
    			mini(mmin[i][j], (mmin[i - 1][j + 1] + 1) / 2);
			} else {
				maxi(mmax[i][j],  mmax[i - 1][j + 1] + a[i][j]);
				mini(mmin[i][j],  mmin[i - 1][j + 1] + a[i][j]);
			}   
    	}
    }

    int ansmmin = llongmax, ansmmax = llongmin;
 	FOR(j, 1, m) {
 		maxi(ansmmax, mmax[n][j]);
 		mini(ansmmin, mmin[n][j]);
 	}   
 	cout << ansmmin __ ;
 	cout << ansmmax;
    // FOR(i, 1, n) FOR(j, 1, m) cout << mmin[i][j] << " \n"[j == m];
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("game.inp", "r")) {
        freopen("game.inp", "r", stdin);
        freopen("game.out", "w", stdout);
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
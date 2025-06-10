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

const double circle = 2.0 * acos(-1.0);
const double prec   = 1e-9;
const int maxn = 10007;
int n, a[maxn];

double angle(const double &r, const double &d) {
	return 2.0 * asin(d / (2.0 * r));
}

bool checkInside(const double &r) {
	double ang = 0.0;

	FOR(i, 1, n) {
		// cout << angle(r, a[i]) __ ;
		ang += angle(r, a[i]);
	}

	// cout << circle __ ;
	// cout << ang __ ;

	if (ang >= circle) return 0;
	return 1;
}	

int bsIn(const double &r) {
	double ang = 0.0;
	FOR(i, 1, n) ang += angle(r, a[i]);
	if (ang > circle + prec) return -1;
	else if (ang < circle - prec) return 1;
	return 0;
}

int bsNotIn(const double &r) {
	double ang = 0.0;
	FOR(i, 1, n) ang += angle(r, a[i]);
	if (ang > circle + prec) return 1;
	else if (ang < circle - prec) return -1;
	return 0;

}

double angg[maxn];
void build(const double &r, bool isIn) {
	angg[1] = 0.0;
	FOR(i, 1, n) {
		angg[i + 1] = angg[i] + angle(r, a[i]);
	}
}


void process() {
	cout << fixed << setprecision(6);

    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n, greater<int>());

    int sum = 0;
    FOR(i, 1, n) sum += a[i];

    if (a[1] > sum) return cout << "NO SOLUTION", void();

    bool isIn = checkInside(a[1] * 1.0 / 2);

    if (isIn == 0) {
    	double l = a[1] * 1.0 / 2, r = a[1];
    	while(bsIn(r) == -1) {
    		l = r;
    		r = r * 2.0;
    	}

    	// cout << bsIn(1.591003) __ ;

    	double ans = 0.0;
    	while(1) {
    		// cout << r _ l __ ;
    		double mid = (l + r) / 2;
    		int x = bsIn(mid);
    		if (x == 0) {
    			ans = mid;
    			build(mid, 0);
    			break;
    		}

    		if (x == -1) l = mid;
    		if (x == 1) r = mid;
    	}

    	// cout << ans;
    	// cout << r __ ;
    	// FOR(i, 1, n) cout << angg[i] __ ;
    	// cout __ ;

	    FOR(i, 1, n) {
	    	cout << (ans * cos(angg[i])) _ (ans * sin(angg[i])) __ ;
	    }
    }


}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("polygon.inp", "r")) {
        freopen("polygon.inp", "r", stdin);
        freopen("polygon.out", "w", stdout);
    }
    process();
    cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC __ ;
}


/*==============================+
|INPUT                          |
--------------------------------|

-2367.52595905779 585.759721631969
1466.41258383288 -1948.82727615236
2438.91238430142 0

-2367.513313 585.828555
1466.340188 -1948.887076
2438.916639 -0.097953

================================+
|OUTPUT                         |
--------------------------------|

===============================*/
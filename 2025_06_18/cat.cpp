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

int m, n, k;
array<int, 4> a[maxn];

vector<array<int, 4>> cur;
pair<double, double> getInter(const array<int, 4> &a, const array<int, 4> &b) {
	int x1 = a[0], y1 = a[1];
	int x2 = a[2], y2 = a[3];
	int x3 = b[0], y3 = b[1];
	int x4 = b[2], y4 = b[3];

	int a1 = y2 - y1, a2 = y4 - y3;
	int b1 = x1 - x2, b2 = x3 - x4;
	int c1 = -(x1 * a1 + y1 * b1);
	int c2 = -(x3 * a2 + y3 * b2);

	double d = a1 * b2 - a2 * b1;
	if (d == 0) return {-1, -1};

	int dx = b1 * c2 - b2 * c1;
	int dy = c1 * a2 - c2 * a1;

    if(x1 > x2 or (x1 == x2 and y1 > y2)) swap(x1, x2), swap(y1, y2);
    if(x3 > x4 or (x3 == x4 and y3 > y4)) swap(x3, x4), swap(y3, y4);

	pair<double, double> ans = {-1, -1};
	ans.fi = dx * 1.0 / d;
	ans.se = dy * 1.0 / d;


    if(x1 <  x2 and (ans.fi <= x1 or x2 <= ans.fi)) return {-1, -1};
    if(x1 == x2 and (ans.se <= y1 or y2 <= ans.se)) return {-1, -1};
    if(x3 <  x4 and (ans.fi <= x3 or x4 <= ans.fi)) return {-1, -1};
    if(x3 == x4 and (ans.se <= y3 or y4 <= ans.se)) return {-1, -1};

	return ans;
}

int add(const array<int, 4> &line) {
	set<pair<double, double>> s;

	for(const array<int, 4> &val : cur) {
		pair<double, double> inter = getInter(val, line);
		if (inter.fi != -1 and inter.se != -1) s.insert(inter);
	}

	cur.pb(line);
	return len(s);
}

void process() {
	cin >> n >> m;
    cin >> k;

    int ans = 0;

    FOR(i, 1, k) {
    	int x1, y1; cin >> x1 >> y1;
    	int x2, y2; cin >> x2 >> y2;

    	if (i == 1) {
    		ans += 2;
    		cur.pb({x1, y1, x2, y2});
    		continue;
    	}

    	int x = add({x1, y1, x2, y2});
    	ans += x + 1;
    }
    
    cout << ans;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("cat.inp", "r")) {
        freopen("cat.inp", "r", stdin);
        freopen("cat.out", "w", stdout);
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
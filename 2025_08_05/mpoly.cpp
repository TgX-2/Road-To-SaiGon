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

int n, a[10];

int sqr(const int &x) {
	return x * x;
}

bool scp(const int &x) {
	int xx = sqrt(x);
	return (xx * xx == x);
}

int ccw(const pair<int, int> &a, const pair<int, int> &b, const pair<int, int> &c) {
    int s = (b.fi - a.fi) * (c.se - a.se) - (c.fi - a.fi) * (b.se - a.se);
    if (s < 0) return -1;
    if (s == 0) return 0;
    return 1;
}

set<pair<int, int>> candidate(int x, const pair<int, int> &pre, const pair<int, int> &cur) {
	set<pair<int, int>> ans;
	int xa = cur.fi, ya = cur.se;
	FOR(dx, -x, x) {
		int dy = sqr(x) - sqr(dx);
		if (scp(dy)) {
			for(const int sign : {-1, 1}) {
				int xb = xa + dx;
				int yb = ya + sign * sqrt(dy);
				if (ccw(pre, cur, {xb, yb}) >= 0) ans.insert({xb, yb});
			}
		}
	}
	return ans;
}

vector<pair<int, int>> chose;

float dis(const pair<int, int> &a, const pair<int, int> &b) {
	int dx = abs(a.fi - b.fi);
	int dy = abs(a.se - b.se);
	return sqrt(sqr(dx) + sqr(dy));
}


bool checkConvex(vector<pair<int, int>> a) {
    int n = a.size();
    if (n < 3) return 0; 

    int sign = 0;
    for (int i = 0; i < n; ++i) {
        auto &p = a[i];
        auto &q = a[(i + 1) % n];
        auto &r = a[(i + 2) % n];

        int cross = (q.fi - p.fi) * (r.se - p.se) - 
                    (r.fi - p.fi) * (q.se - p.se);

        if (cross != 0) {
            if (sign == 0)
                sign = (cross > 0 ? 1 : -1);
            else if ((cross > 0 ? 1 : -1) != sign)
                return 0; 
        }
    }
    return 1;
}

int cal(vector<pair<int, int>> a) {
    int n = a.size();
    if (n < 3) return -1;

    long long area = 0;
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += 1LL * (a[i].first * a[j].second) - 1LL * (a[j].first * a[i].second);
    }

    double result = abs(area) / 2.0;
    return result;
}

bool checkInt(float x) {
    const float EPS = 1e-6;
    return fabs(x - round(x)) < EPS;
}

int ans = 0;


void dfs(int id, const pair<int, int> &pre, const pair<int, int> &cur) {
	if (id == n) {
		if (dis(cur, {0, 0}) == a[n] * 1.0) {
			if (checkConvex(chose)) {
				int x = cal(chose);
				if (checkInt(x)) maxi(ans, x);
			}
		} 
		// cout << chose __ ;
		return;
	}


	set<pair<int, int>> candi = candidate(a[id], pre, cur);
	for(const pair<int, int> &val : candi) {

		if (ccw(chose[1], chose[0], val) == 1) continue; 

		chose.pb({val});
		dfs(id + 1, cur, val);
		chose.pop_back();
	}
}

void process() {
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    // sort(a + 1, a + 1 + n);

    cout << candidate(5, {-100, 0}, {0, 0});
    return;

    chose.pb({0, 0});
    // dfs(1, {-300, 0}, {0, 0});

    do { 
 		dfs(1, {-300, 0}, {0, 0});
    } while(next_permutation(a + 1, a + 1 + n));

    cout << ans;
}



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    if (fopen("mpoly.inp", "r")) {
        freopen("mpoly.inp", "r", stdin);
        freopen("mpoly.out", "w", stdout);
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
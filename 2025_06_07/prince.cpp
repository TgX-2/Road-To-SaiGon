/*-----------------------------
        Author : TgX.2
       11Ti - K28 - CHV
-----------------------------*/

#include <bits/stdc++.h>
using namespace std;

#ifdef TGX
#include "debug.h"
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

const int maxn = 1e5 + 7;
int n, k;

struct pos {
	int x, y;
	int cheo1, cheo2;
	int dir[4];

	pos() : x(0), y(0), cheo1(0), cheo2(0) {}
	pos(int x, int y, int cheo1, int cheo2) : x(x), y(y), cheo1(cheo1), cheo2(cheo2) {
		FOR(i, 0, 3) dir[i] = -1;
	}
};
pos a[maxn];
char b[maxn];

bool cmp1(const int &i, const int &j) {
	if (a[i].cheo1 != a[j].cheo1) return a[i].cheo1 < a[j].cheo1;
	return a[i].cheo2 < a[j].cheo2;
}

bool cmp2(const int &i, const int &j) {
	if (a[i].cheo2 != a[j].cheo2) return a[i].cheo2 < a[j].cheo2;
	return a[i].cheo1 < a[j].cheo1;
}

int id[maxn];

void compress() {
	iota(id + 1, id + 1 + n, 1);

	sort(id + 1, id + 1 + n, cmp1);
	FOR(i, 2, n) {
		if (a[id[i - 1]].cheo1 == a[id[i]].cheo1) {
			a[id[i - 1]].dir[1] = id[i];
			a[id[i]].dir[2] = id[i - 1];
		}
	}

	sort(id + 1, id + 1 + n, cmp2);
	FOR(i, 2, n) {
		if (a[id[i - 1]].cheo2 == a[id[i]].cheo2) {
			a[id[i - 1]].dir[0] = id[i];
			a[id[i]].dir[3] = id[i - 1];
		}
	}

	// FOR(i, 1, n) {
	// 	cout << i << " : " __ ;
	// 	FOR(j, 0, 3) cout << a[i].dir[j] ___ ;
	// 	cout __ ;
	// }
}

void process() {
 	cin >> n >> k;
 	FOR(i, 1, k) {
 		char x; cin >> x;
 		b[i] = 	x;
 	}

 	FOR(i, 1, n) {
 		int x, y; cin >> x >> y;
 		int cheo1 = x + y;
 		int cheo2 = x - y;
 		a[i] = pos(x, y, cheo1, cheo2);
 	}

 	compress();


	int cur = 1;
    FOR(i, 1, k) {
        int nxt = a[cur].dir[b[i] - 'A'];
        if(nxt == -1) continue;
        FOR(j, 0, 3) {
            if(a[cur].dir[j] == -1) continue;
            a[a[cur].dir[j]].dir[3 - j] = a[cur].dir[3 - j];
        }
        cur = nxt;
    }
    cout << a[cur].x _ a[cur].y;
}




/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    if (fopen("prince.inp", "r")) {
        freopen("prince.inp", "r", stdin);
        freopen("prince.out", "w", stdout);
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
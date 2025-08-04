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

int l, r;

vector<bool> check(110, 1);
void sieve() {
    check[0] = check[1] = 0;
    for(int i = 2; i <= 109; i++) 
        if (check[i] == 1) 
            for(int j = i * i; j <= 109; j += i) check[j] = 0;
}


int cal(int x) {
    int ans = 0;
    while(x) {
        ans += (x % 10);
        x /= 10;
    }
    return ans;
}

int rev(int x) {
    int ans = 0;
    while(x) {
        ans = ans * 10 + (x % 10);
        x /= 10;
    }
    return ans;
}


int poww[15];

void process() {
    sieve();
    poww[0] = 1;
    FOR(i, 1, 12) poww[i] = poww[i - 1] * 10;

    cin >> l >> r;

    int ans = 0;
    FOR(i, 2, 9) if (l <= i and i <= r and check[i] == 1) ans++;
    FOR(i, 1, 1000000) {
        int n = log10(i);
        int c = cal(i); 

        int x = i * poww[n + 1] + rev(i);
        if (l <= x and x <= r and check[c + c] == 1) ans++;

        FOR(d, 0, 9) {
            int x = (i * 10 + d) * poww[n + 1] + rev(i);
            int val = c + d + c;
            if (l <= x and x <= r and check[val] == 1) {
                // cout << x __ ;
                ans++;
            }
        }
    }
    cout << ans;
}   



/*-----------------------------*/
______________TgX______________ {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    if (fopen("palinprime.inp", "r")) {
        freopen("palinprime.inp", "r", stdin);
        freopen("palinprime.out", "w", stdout);
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
101
111
131
151
191
212
232
272
292
313
353
373
434
454
494
515
535
575
595
616
656
676
737
757
797
818
838
878
919
959
===============================*/
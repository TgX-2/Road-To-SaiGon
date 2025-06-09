/*------------------------------
        Author : TgX.2
       12Ti - K28 - CHV
------------------------------*/

#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define len(x) (int)((x).size())

#define int long long
#define intmax 1e9
#define intmin -1e9
#define llongmax 1e18
#define llongmin -1e18

#define _ << " " << 
#define __ << " " 
#define ___ << " "

template<typename T1, typename T2> bool maxi(T1 &a, T2 b)
  { if (a < b) a = b; else return 0; return 1; }
template<typename T1, typename T2> bool mini(T1 &a, T2 b) 
  { if (a > b) a = b; else return 0; return 1; }
/*----------------------------*/


void process() {
  int a; cin >> a;
  cout << a;
}


/*----------------------------*/
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  if (fopen("temp.inp", "r")) {
    freopen("temp.inp", "r", stdin);
    freopen("temp.out", "w",stdout);
  }
  process();
  cerr << "Time : " <<  clock() * 1.0 / CLOCKS_PER_SEC << " ms." __ ;
}
/*=============================+
| INTPUT                       |
-------------------------------+

+==============================+
| OUTPUT                       |
-------------------------------+

==============================*/






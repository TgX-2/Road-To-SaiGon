#include <bits/stdc++.h>

using namespace std;

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define rf if(fopen(name".inp", "r")) {freopen(name".inp", "r", stdin); freopen(name".out", "w", stdout);}
#define rd ({int x = 0; int c = getchar(), n = 0; for(; !isdigit(c); c = getchar()) n = (c == '-'); for(; isdigit(c); c = getchar()) x = x * 10 + c - '0'; n ? -x : x;})

#define bit(i, mask) (((mask) >> (i)) & 1)
#define on(i, mask) ((mask)  (1LL << (i)))
#define off(i, mask) ((mask) & (~(1LL << (i))))

#define ll long long
#define fi first
#define se second
#define pii pair<int, int>
#define vii vector<int>
#define all(a) (a).begin(), (a).end()
#define len(x) ((int)(x).size())
#define pb push_back
#define endl '\n'
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)

#define name "palinprime"

template<typename T1, typename T2> bool mini(T1 &a, T2 b)
    {if(a > b) a = b; else return 0; return 1;}
template<typename T1, typename T2> bool maxi(T1 &a, T2 b)
    {if(a < b) a = b; else return 0; return 1;}

const int mod = 1e9+7;
const int inf = 1e9+9;
const ll oo = 1e18l+7;
const int M = 5e5+6;
const int N = 1e6+5;
const int LOG = 31 - __builtin_clz(N);

ll l, r, pw[20];
bool p[10000];

void in(){
    cin >> l >> r;
}

void sieve(){
    p[0] = p[1] = 1;
    for(int i = 2; i * i <= 1000; i++){
        if(p[i] == 0) for(int j = i * i; j <= 1000; j += i) p[j] = 1;
    }
}

int get(int x){
    int d = 0;
    while(x > 0){
        d++;
        x /= 10;
    }
    return d;
}

int rv(int x){
    int d = 0;
    while(x > 0){
        d = d * 10 + x % 10;
        x /= 10;
    }
    return d;
}

bool check(ll x){
    int d = 0;
    while(x > 0){
        d += x % 10;
        x /= 10;
    }
    return (p[d] == 0);
}   

void proc(){
    sieve();
    pw[0] = 1;
    for(int i = 1; i <= 10; i++) pw[i] = pw[i - 1] * 10;
    ll res = 0;
    for(int i = 1; i <= 9; i++) res += (check(i) && l <= i && i <= r);
    for(int i = 1; i <= 1000000; i++){
        int d = get(i);
        ll w = 1LL * i * pw[d] + rv(i);
        res += (l <= w && w <= r && check(w));
        if(d == 6) continue;
        for(int j = 0; j <= 9; j++){
            w = 1LL * (i * 10 + j) * pw[d] + rv(i);
            res += (l <= w && w <= r && check(w));
        }
    }
    cout << res;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    rf

    int test = 1;
    //cin >> test;

    while(test--){
        in();
        proc();
    }

    cerr << "Time elapsed: " << TIME << "s" << endl;
    return 0;
}


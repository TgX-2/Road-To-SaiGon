#include<bits/stdc++.h>
using namespace std;
#define int long long

#ifdef TGX
#include "D:\egoist\debug.h"
#else 
#define debug(...)
#endif



void process() {

}

main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if (fopen("temp.inp", "r")) {
		freopen("temp.inp", "r", stdin);
		freopen("temp.out", "w", stdout);
	} else {
		freopen("fourdiv.inp", "r", stdin);
		freopen("fourdiv.out", "w", stdout);
	}
	process();
	cerr << "Time : " << clock() * 1.0 / CLOCKS_PER_SEC << " ms.\n";
}
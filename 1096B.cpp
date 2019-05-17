#include <cstdio>
#include <algorithm>
#include <stack>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <cmath>

#define MAXN 1000005
#define ll long long
#define ull unsigned long long
#define all(c) (c).begin(),(c).end()
#define sz(a) int((a).size())
#define pb push_back
#define io freopen("input.inp","r",stdin);

using namespace std;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
const ll MOD = 998244353;
int n;
int a[MAXN];
int main()
{
    io;
    scanf("%d",&n);
    string s;
    cin >> s;
    for (int i = 1 ; i <= n ;++i) a[i] = s[i - 1];
    int vt, vt2;
    ll res = 2LL;
    bool kt = false;
    for (int i = 2 ; i <= n ;++i)
    {
        if (a[i] != a[i - 1])
        {
            res = (ll)(i - 1);
            vt = i - 1;
            kt = true;
            break;
        }
    }
    if (!kt) res = (ll)(n * (n + 1) / 2) % MOD;
    else
    {
        for (int i = n - 1 ; i >= 1;--i)
        {
            if ((a[i] != a[i + 1]) || (i <= vt))
            {
                res = ((res % MOD ) + (ll)(n - i) % MOD) % MOD ;
                vt2 = n - i;
                break;
            }
        }
        if (a[1] == a[n]) res = ((res % MOD) + (ll)(vt * vt2) % MOD) % MOD;
        res++;
    }
    printf("%lld",res % MOD);
	return 0;
}

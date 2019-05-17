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

#define MAXN 100005
#define ll long long
#define ull unsigned long long
#define all(c) (c).begin(),(c).end()
#define sz(a) int((a).size())
#define pb push_back
#define io freopen("input.inp","r",stdin);

using namespace std;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
ll f[MAXN],d[MAXN];
vector <int> a[MAXN];
int n;
void dfs(int x, int x1, int h)
{
    if (a[x].size() > 0)
    {
        if (h % 2 == 0)
        {
            ll tg = f[a[x][0]];
            if (tg < f[x1]) {cout << -1; exit(0);}
            for (int i = 1 ; i < a[x].size() ; i++)
                if (f[a[x][i]] < f[x1]) {cout << -1; exit(0);}
                else tg = min(tg ,f[a[x][i]]);
            d[x] = tg - f[x1];
            f[x] = f[x1] + d[x];
            for (int v  : a[x]) dfs(v , x, h + 1);
        }
        else
        {
            if ( x != 1 ) d[x] = f[x] - f[x1];
            for (int v  : a[x]) dfs(v , x, h + 1);
        }
    }
    else
    {
        if (h%2 == 0 ) d[x] = 0LL;
        else d[x] = f[x] - f[x1];
    }
}
int main()
{
    io;
    scanf("%d",&n);
    for (int i = 2 ; i <= n  ;i++)
    {
        int y;
        scanf("%d",&y);
        a[y].pb(i);
    }
    for (int i = 1 ; i <= n ; i++) scanf("%lld",&f[i]);
    d[1] = f[1];
    dfs(1, -1, 1);
    ll res = 0LL;
    for (int i = 1 ; i <= n ; i++) res += d[i];
    printf("%lld", res);
    return 0;
}

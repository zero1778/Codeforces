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

struct ioi
{
    int fi,se,tt;
};
vector <ioi> a[MAXN];
bool Edge[MAXN],ok[MAXN];
int n,m;
int edge[MAXN];
bool dfs(int x)
{
    for (ioi v : a[x])
    {
        if (Edge[v.tt]) continue;
        if (ok[v.fi]) return true;
        ok[v.fi] = true;
        bool t = dfs(v.fi);
        ok[v.fi] = false;
        if (t == true) return true;
    }
    return false;
}
int res[MAXN];
bool check(int x,int &N)
{
    N = 0;
    for (int i = 1 ; i <= m ; i++)
        if (edge[i] <= x) Edge[i] = true;
    ok[1] = true;
    bool t = dfs(1);
    for (int i = 1 ; i <= m ; i++)
        if (edge[i] <= x)
        {
            Edge[i] = false;
            res[++N] = i;
        }
    return t;
}
int main()
{
    io;
    scanf("%d%d",&n,&m);
    int mink = 1e9, maxk = 0;
    for (int i = 1 ; i <= m ;i++)
    {
        int x,y,k;
        scanf("%d%d%d",&x,&y,&k);
        mink = min(k, mink);
        maxk = max(k ,maxk);
        ioi v;
        v.fi = y, v.se = k, v.tt = i;
        a[x].pb(v);
        edge[i] = k;
    }
    int N;
    while (mink <= maxk)
    {
        int tg = (mink + maxk) >> 1;
        if (!check(tg, N)) maxk = tg - 1;
        else mink = tg + 1;
    }
    printf("%d %d\n",mink,N);
    for (int i = 0 ; i < N ;i++) printf("%d ",res[i + 1]);
	return 0;
}

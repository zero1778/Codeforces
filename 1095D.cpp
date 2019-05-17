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

#define MAXN 200005
#define ll long long
#define ull unsigned long long
#define all(c) (c).begin(),(c).end()
#define sz(a) int((a).size())
#define pb push_back
#define io freopen("input.inp","r",stdin);

using namespace std;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;

int n;
vector <int> a[MAXN];
bool ok[MAXN];
int pre[MAXN];
bool check = false;
void dfs(int x)
{
    int u = a[x][0];
    int v = a[x][1];
    if (v == a[u][0] || v == a[u][1])
    {
        if (u == 1) return;
        if (v == 1) printf("%d", u);
        else printf("%d %d ",u , v), dfs(v);
    }
    else
    {
        if (v == 1) return;
        if (u == 1) printf("%d", v);
        else printf("%d %d ",v , u), dfs(u);
    }
}
int main()
{
    io;
    scanf("%d",&n);
    for (int i = 1 ; i <= n ; i++)
    {
        int x, y;
        scanf("%d%d",&x,&y);
        a[i].pb(x), a[i].pb(y);
    }
    if (n == 3)
    {
        printf("1 2 3");
        exit(0);
    }
    printf("1 ");
    dfs(1);
	return 0;
}

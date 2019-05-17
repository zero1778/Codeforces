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
#define fi first
#define se second
using namespace std;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;

struct ioi
{
    int fi,se;
    int tt;
};
ioi a[MAXN];
int res[MAXN];
bool cmp(ioi a, ioi b) { return (a.fi < b.fi || (a.fi == b.fi && a.se < b.se));}
int main()
{
    io;
    int q;
    scanf("%d",&q);
    while (q--)
    {
        int n;
        scanf("%d",&n);
        for (int i = 1; i <= n ;i++) scanf("%d%d",&a[i].fi, &a[i].se), a[i].tt = i;
        sort(a + 1, a + 1 + n,cmp);
        bool ok = false;
        int i ;
        int maxr = a[1].se;
        for (i = 2 ;i <= n ;i++)
            if (a[i].fi > maxr)
            {
                ok = true;
                break;
            }
            else maxr = max(maxr, a[i].se);

        if (ok)
        {
            for (int j = 1 ; j < i ; j++) res[a[j].tt] = 1;
            for (int j = i ; j <= n ; j++) res[a[j].tt] = 2;
            for (int i = 1 ; i <= n ; i++) printf("%d ",res[i]);
        }
        else cout << "-1";
        cout << "\n";
    }
	return 0;
}

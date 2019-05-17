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
#define io freopen("input.inp","r",stdin); //freopen("output.out","w",stdout);

using namespace std;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
int n;
ll t;
ll a[MAXN];
int F(ll x, int l, int r)
{
    while (l <= r)
    {
        int tp = (l + r)>>1;
        if (a[tp] - x >= t) r = tp - 1;
        else l = tp + 1;
    }
    return l;
}
int main()
{
    io;
    cin.tie(NULL);
    cin >> n >> t;
    int res = 0;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = n / 2 + 1;
    for (int i = 1; i <= n / 2 ;i++)
    {
        int vt = F(a[i], l , n);
        if (a[vt] - a[i] >= t) res++;
        else break;
        l = vt + 1;
    }
    cout << res;
	return 0;
}

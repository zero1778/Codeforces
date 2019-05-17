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
#include <iomanip>

#define MAXN 1000005
#define ll long long
#define db double
#define ull unsigned long long
#define all(c) (c).begin(),(c).end()
#define sz(a) int((a).size())
#define pb push_back
#define io freopen("input.inp","r",stdin); //freopen("input.inp","r",stdin);

using namespace std;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;

ll n,m,k;
ll a[MAXN];
int main()
{
    io;
    scanf("%lld%lld%lld",&n,&k,&m);
    for (int i = 1 ; i <= n ;i++) scanf("%lld",&a[i]);
    sort(a + 1, a + 1 + n);
    for (int i = 1 ; i <= n ;i++) a[i] += a[i - 1];
    long double res = 0.00;
    for (int i = 0 ; i <= min(n - 1,m) ; i++)
    {
        long db t = (long db)(a[n] - a[i] + min(m - i, k*(n - i)));
        res = max(res, (long db)(t / (long db)(n - i)));

    }
    printf("%.20Lf", res);
	return 0;
}

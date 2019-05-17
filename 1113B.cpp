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
ll a[MAXN];
int n ;
int main()
{
    io;
    cin.tie(NULL);
    cin >> n;
    ll res = 0LL;

    for (int i = 1; i <= n ; i++) cin >> a[i], res += a[i];
    sort(a + 1, a + 1 + n);

    ll ans = res;
    for (int i = 2 ; i <= n ;i++)
    {
        int j;
        for (j = int(sqrt(a[i])) + 1; j >= 2; j--)
            if (a[i] % j == 0) break;
        ll x = min((ll)j , a[i] / j);
        ll y = a[i] / x;
        ans = min(ans, res - a[1] - a[i] + y + x*a[1]);
    }

    cout << ans;
	return 0;
}

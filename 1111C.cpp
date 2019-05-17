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
#define db double
#define ll long long
#define ull unsigned long long
#define all(c) (c).begin(),(c).end()
#define sz(a) int((a).size())
#define pb push_back
#define io freopen("input.inp","r",stdin); //freopen("input.inp","r",stdin);

using namespace std;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;

ll n, k, A,B;
vector <ll> T;

ll Find(ll l, ll r)
{
    ll i = lower_bound(T.begin(), T.end(), l) - T.begin();
    ll j = upper_bound(T.begin(), T.end(), r) - T.begin();
    j--;
    ll x = j - i + 1;
    if (l == r)
    {
        if (binary_search(T.begin() , T.end(), l)) return B*x;
        else return A;
    }
    ll mid = (l + r) >> 1;
    if (x == 0) return A;
    return min(B*(ll)x*(r - l + 1), Find(l, mid) + Find(mid + 1,r));
}
int main()
{
    io;
    scanf("%lld%lld%lld%lld",&n,&k,&A,&B);
    for (int i = 1 ; i <= k; i++)
    {
        ll x;
        scanf("%lld",&x);
        T.pb(x);
    }
    sort(T.begin(), T.end());
    ll x = 1 << n;
    printf("%lld",Find(1, x));
	return 0;
}

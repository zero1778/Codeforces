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

#define MAXN 300005
#define ll long long
#define ull unsigned long long
#define all(c) (c).begin(),(c).end()
#define sz(a) int((a).size())
#define pb push_back
#define io freopen("input.inp","r",stdin); //freopen("output.out","w",stdout);

using namespace std;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
ii a[MAXN];
int n;
bool ok[MAXN];
int better[MAXN], loser[MAXN];
int main()
{
    io;
    cin.tie(NULL);
    cin >> n;
    for (int i = 1 ; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1 ; i <=  n ; i++) better[i] = i + 1, loser[n - i + 1] = n - i;
    int l = 1 ,r = n;
    int res = 1e9;
    for (int i = 1 ; i < n ;i++)
    {
        while (ok[l]) l = better[l];
        while (ok[r]) r = loser[r];
        int vt = a[i].second;
        int vl = max(abs(vt - l) , abs(vt - r));
        if (vl != 0) (res = min(res , (a[i].first) / vl));
        ok[vt] = true;
        better[loser[vt]] = better[vt];
        loser[better[vt]] = loser[vt];
    }
    cout << res;
	return 0;
}

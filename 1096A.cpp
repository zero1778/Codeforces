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

int main()
{
    io;
    int t;
    scanf("%d",&t);
    while (t--)
    {
        ll l ,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld %lld\n",l,l * 2);
    }
	return 0;
}

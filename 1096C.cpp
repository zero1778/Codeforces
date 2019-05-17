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
        int n, res;
        scanf("%d",&n);
        int tg = __gcd(n , 180);
        if ( n >= 180) res = -1;
        else
        {
            res = 180 / tg;
            int ans = n / tg;
            if (ans + 1 == res) res *= 2;
        }
        printf("%d\n" , res);
    }
	return 0;
}

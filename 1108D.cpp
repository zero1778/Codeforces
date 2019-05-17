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

int n;
int a[MAXN];

int main()
{
    io;
    scanf("%d",&n);
    for (int i = 0 ; i <= n;i++)
    {
        char x;
        scanf("%c",&x);
        switch (x)
        {
            case 'R' : a[i] = 1; break;
            case 'G' : a[i] = 2; break;
            case 'B' : a[i] = 3; break;
        }
    }
    a[n + 1] = a[n - 1] + 1;
    if (a[n + 1] == 4) a[n + 1] = 1;
    int sl = 1, res = 0;
    for (int i = 2; i <= n;i++)
    {
        if (a[i] != a[i - 1])
        {
            res += sl / 2;
            sl = 1;
        }
        else
        {
            sl++;
            int x = a[i - 1], y = a[i + 1];
            if (x > y) x += y, y = x - y, x = x - y;
            if (x == 1 && y == 2) a[i] = 3;
            if (x == 1 && y == 3) a[i] = 2;
            if (x == 2 && y == 3) a[i] = 1;
            if (x == y)
            {
                a[i] = x + 1;
                if (a[i] == 4) a[i] = 1;
            }
        }
    }
    res += sl / 2;
    printf("%d\n",res);
    for (int i = 1 ; i <= n ;i++)
    {
        switch (a[i])
        {
            case 1 : printf("R"); break;
            case 2 : printf("G"); break;
            case 3 : printf("B"); break;
        }
    }
	return 0;
}

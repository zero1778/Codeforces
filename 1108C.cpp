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

int a[MAXN];
int st[6] = {123,132,213,231,312,321};
string kt[6] = {"RGB", "RBG", "GRB" , "GBR", "BRG" , "BGR"};
int n;

int dis(int x ,int y)
{
    int res = 0;
    while (x % 10 == 0) x /= 10 ,y /= 10;

    while (x > 0)
    {
        int t = x % 10;
        if (t != y%10) res++;
        x /= 10; y /= 10;
    }
    return res;
}
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
    int vt;
    int ans = 1e9;
    for (int j = 0 ; j < 6 ; j++)
    {
        int res = 0;
        for (int i = 1; i <= n ;i += 3)
        {
            int t = a[i]*100 + a[i + 1]*10 + a[i + 2];
            res += dis(t, st[j]);
        }

        if (res < ans)
        {
            ans = res;
            vt = j;
        }
    }
    printf("%d\n",ans);
    for (int i = 1 ; i <= n ; i += 3)
    {
        if (n - i == 0) cout << kt[vt][0];
        else
            if (n - i == 1) cout << kt[vt][0] << kt[vt][1];
            else cout << kt[vt];
    }
	return 0;

}

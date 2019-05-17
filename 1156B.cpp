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

#define MAXN 100005
#define ll long long
#define ull unsigned long long
#define all(c) (c).begin(),(c).end()
#define sz(a) int((a).size())
#define pb push_back
#define io freopen("input.inp","r",stdin); //freopen("output.out","w",stdout);

using namespace std;
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
int n,m;
bool ok[200];
map <int,char> ok1;

bool dfs(int x, vector <int> *a, int num)
{
    if (num == n)
    {
        cout << ok1[x];
        return true;
    }
    for (int v : a[x])
    {
        if (ok[v]) continue;
        ok[v] = true;
        int t = dfs(v, a, num + 1);
        ok[v] = false;
        if (t)
        {
            cout << ok1[x];
            return true;
        }
    }
    return false;
}

int main()
{
    io;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        n = s.size();
        vector <int> a[n];
        for (int i = 0 ; i < n; i++)
        {
            ok[i] = false;
            ok1[i] = s[i];
            for (int j = i + 1 ; j < n ; j++)
                if (abs(s[i] - s[j]) != 1)
                {
                    m += 2;
                    a[i].pb(j);
                    a[j].pb(i);
                }
        }
        int init = 0;
        for (int i = 0; i< n ;i++)
        {
            if (a[i].size() == 1)
            {
                init = i;
                break;
            }
        }
        ok[init] = true;
        int t1 = dfs(init, a, 1);
        if (!t1) cout << "No answer";
        cout <<"\n";
    }
	return 0;
}

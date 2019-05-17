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
    string s;
    cin >> s;

    bool ok = false;
    int res = 0;
    while (!ok)
    {
        s += '#';
        int sl = 1;
        string t = "";
        ok = true;
        for (int i = 1 ; i < s.size() ; i++)
        {
            if (s[i] != s[ i - 1 ])
            {
                if (sl > 1) ok = false;
                res += sl / 2;
                sl %= 2;
                if (sl == 1) t += s[i - 1];
                sl = 1;
            }
            else sl++;
        }
        s = t;
    }
    if (res % 2 == 1) cout <<"Yes";
    else cout << "No";
	return 0;
}

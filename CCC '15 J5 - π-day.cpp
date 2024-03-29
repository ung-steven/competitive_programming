#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;

const int INF = 0x3f3f3f3f;
#define MAXN 251
using namespace std;
int n, ans = 0,k;
int dp[MAXN][MAXN][MAXN];

int solve(int cur, int line, int left){
    if(dp[cur][line][left]) return dp[cur][line][left];
    if(line == 0){
        if (left == 0) return 1;
        return 0;
    }
    int a = 0;
    for(int i = cur; i <= (int)left/line; i++){
        a+=solve(i, line-1, left-i);
    }
    return dp[cur][line][left]=a;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    cout<<solve(1,k,n);
}

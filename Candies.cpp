#include <bits/stdc++.h>

#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define endl '\n'
#define exists(s, e) (s.find(e)!=s.end())
#define WHILE(n)
#define pb push_back
#define f first
#define s second
#define UNI(vec) vec.erase(std::unique(vec.begin(), vec.end()),vec.end());
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef long double ld;
typedef std::pair<int, int> pii;
typedef std::pair<int, pii> piii;

const int INF = 0x3f3f3f3f;
#define MAXN 101
using namespace std;
int n,k,ans;
int dp[MAXN][100001],a[MAXN];
int mod = 1000000007, sum[100001];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i =1; i <= n; i++){
        cin>>a[i];
        dp[i][0] = 1;//sum[i][0] = 1;
    }
    dp[0][0] = 1;//sum[0][0] = 1;
    for(int i = 1; i<= n; i++){
        for(int j = 0; j<=k; j++){
            sum[j] = sum[j-1] + dp[i-1][j];
            sum[j]%=mod;
            //cout<<sum[i-1][j]<<endl;
        }
        for(int j = 1; j <= k; j++){
            dp[i][j] = sum[j] - (j-a[i]-1>=0?sum[j-a[i]-1]:0);
            dp[i][j]%=mod;
            //sum[i][j] = sum[i][j-1] +dp[i][j];
        }
    }
    cout<<dp[n][k];



}

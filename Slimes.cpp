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

const ll INF = 0x3f3f3f3f;
#define MAXN 401
using namespace std;
ll n,m,ans;
ll dp[MAXN][MAXN], psa[MAXN];
vector<ll> a; bool b[MAXN];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    MEM(dp,INF);
    cin>>n; a.pb(0);
    for (int i =1,x; i <= n; i++){
        cin>>x;
        a.pb(x);
        psa[i] = psa[i-1] + x;
    }
    for(int i = 1; i <= n; i++){
        dp[i][i] = 0;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j+i <= n; j++){
            for(int k = j; k < i+j; k++){
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + psa[i+j] - psa[j-1]);
                //cout<<j<<" "<<k<<" "<<i+j<<endl;
                //cout<<psa[j-1]<<endl;
            }
        }
    }

    cout<<dp[1][n];



}

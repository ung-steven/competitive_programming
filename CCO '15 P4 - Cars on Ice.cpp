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
#define MAXN 2001
using namespace std;
int n,m,ans;
char b[MAXN][MAXN];
vector<int> a[MAXN];
vector<pii> c;

void solve(int x, int y){
    //cout<<x<<" "<<y<<endl;
    if(b[x][y] == 'N'){
        for(int i = y-1; i >= 1; i--){
            if(b[x][i]!='.') solve(x,i);
        }
    }
    if(b[x][y] == 'S'){
        for(int i = y+1; i <= n; i++){
            if(b[x][i]!='.') solve(x,i);
        }
    }
    if(b[x][y] == 'E'){
        for(int i = x+1; i <= m; i++){
            if(b[i][y]!='.') solve(i,y);
        }
    }
    if(b[x][y] == 'W'){
        for(int i = x-1; i >= 1; i--){
            if(b[i][y]!='.') solve(i,y);
        }
    }
    b[x][y] = '.';
    cout<<'('<<y-1<<','<<x-1<<')'<<endl;

}

int main(){
    //cin.sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i =1; i <= n; i++){
        for(int j=1;j<=m;j++){
            cin>>b[j][i];
            if(b[j][i] != '.') c.pb({j,i});
        }
    }
    for(pii i : c){
        if(b[i.f][i.s] != '.') solve(i.f,i.s);
    }



}
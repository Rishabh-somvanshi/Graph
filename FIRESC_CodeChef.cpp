Problem: https://www.codechef.com/LRNDSA08/problems/FIRESC
Editorial: https://discuss.codechef.com/t/firesc-editorial/1713

#include<bits/stdc++.h>
using namespace std;

#define pb(x) push_back(x)

const int N = 1e5+10;
const int mod = 1e9+7;

vector<int>g[N];
int vis[N];

int dfs(int node){
    vis[node] = 1;
    int count = 0;
    for(int u : g[node]){
        if(!vis[u]){
            count += dfs(u);
        }
    }
    return 1+count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        for(int i=1; i<=n; i++){
            g[i].clear();
            vis[i] = 0;
        }
        for(int i=0; i<m; i++){
            int x,y;
            cin >> x >> y;
            g[x].pb(y);
            g[y].pb(x);
        }
        vector<int> comp; 
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                int x = dfs(i);
                comp.pb(x);
            }
        }
        cout << comp.size() << " ";
        long long ans = 1;
        for(int i : comp){
            ans = ((ans%mod)*(i%mod))%mod;
        }
        cout << ans << endl;
    }
}

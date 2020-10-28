#include<bits/stdc++.h>
using namespace std;

/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
vector <int> dfs(vector<int> g[], int N)
{           vector<int>v;
            vector<bool>vis(N);
            stack<int>st;
            if(N)
                st.push(0);
            while(st.size())
            {   int x=st.top();st.pop();
                if(vis[x])
                    continue;
                v.push_back(x);vis[x]=true;
                for(int i=g[x].size()-1;i>=0;i--)
                {   if(!vis[g[x][i]])
                        st.push(g[x][i]);
                }
            }
            return v;
    
    // Your code here

}


// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends

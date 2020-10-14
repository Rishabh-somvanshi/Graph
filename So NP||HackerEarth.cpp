/*
Editorial: https://www.geeksforgeeks.org/maximum-number-of-edges-to-be-removed-to-contain-exactly-k-connected-components-in-the-graph/
Algo:
1.Count the number of connected components present in the given graph. Let the count be C.
2.If C is greater than K, print -1.
3.Else print M – N + K where N is the number f nodes, M is the number of edges and K is the required number of connected components.
/*

#include<bits/stdc++.h>

using namespace std;

vector<int> ar[1000001];
int vis[1000001];

void dfs(int node){

    vis[node]=1;

    for(int child : ar[node]){
        if(!vis[child])
            dfs(child);
    }
}

int main(){

    int n,m,a,b,k;
    cin>>n>>m>>k;

    for(int i=1;i<=m;i++){

        cin>>a>>b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }

    int cc=0;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
            cc++;
        }
    }

        if(cc>k)
            cout<<-1<<endl;
        else{
            cout<<m-n+k<<endl;
        }   
return 0;
}

/*there are easier solutions heck submissions*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int vertex,bool visit[],vector<int> gra[],stack<int> &st1) //standard Kosaraju's Algo part2
{
	visit[vertex] = true;
	
	for(int i=0;i<gra[vertex].size();++i)
	{
		int child = gra[vertex][i];
		if(visit[child] != true)
		dfs(child,visit,gra,st1);
	}
	
	st1.push(vertex);
	
}

void revDfs(int vertex,bool visit[],vector<int> gra[])  //standard Kosaraju's Algo part3
{
	visit[vertex] = true;
	
	for(int i=0;i<gra[vertex].size();++i)
	{
		int child = gra[vertex][i];
		if(visit[child] != true)
		revDfs(child,visit,gra);
	}
}

bool kosaraju(vector<int> gra[])  //standard Kosaraju's Algo part1
{
	bool visit[26] = {false};
	stack<int> st1;
	
	for(int i=0;i<26;++i)
	{
		if(visit[i] != true && gra[i].size()>0)
		dfs(i,visit,gra,st1);
	}
	
	vector<int> trans[26];
	
	for(int i=0;i<26;++i)
	{
		for(int j=0;j<gra[i].size();++j)
		{
			int child = gra[i][j];
			trans[child].push_back(i);
		}
	}
	
	int SCC = 0;
	for(int i=0;i<26;++i)
	visit[i] = false;
	
	while(!st1.empty())
	{
		int node = st1.top();
		st1.pop();
		
		if(visit[node] != true)
		{
			++SCC;
			revDfs(node,visit,trans);
		}
	}
	
	if(SCC == 1)
	return true;
	else
	return false;
}

void work()
{
	int n;
	cin>>n;
	
	vector<string> str(n);
	
	for(int i=0;i<n;++i)
	cin>>str[i];
	
	vector<int> gra[26];
	int inDegree[26] = {0},outDegree[26] = {0};
	
	for(int i=0;i<n;++i)
	{
		string temp = str[i];
		char st = temp[0],end = temp[temp.size()-1]; //creating the graph.....
		gra[st-'a'].push_back(end-'a'); //creating the graph.....
		++outDegree[st-'a']; 
		++inDegree[end-'a'];
	}
	
	bool res1 = kosaraju(gra); //standard Kosaraju's Algo called
	bool res2 = true;
	
	for(int i=0;i<26;++i)
	{
		if(inDegree[i] != outDegree[i]) //checking the equality of indegree and outdegree algo
		res2 = false;
	}
	
	if(res1 && res2)
	cout<<1;
	else
	cout<<0;
}

int main()
 {
	ll test;
	cin>>test;
	for(int i=0;i<test;++i)
	{
	    work();
	    cout<<"\n";
	}
	return 0;
}

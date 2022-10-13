//BFS dem so thanh phan lien thong
#include <bits/stdc++.h>
using namespace std;

int n,m,s,u,v;
int Free[1001];
int a[1001][1001];
queue <int> q;
int test;
int slt = 0;

void BFS(int s){
	q.push(s);
	Free[s]=1;
	
	while(!q.empty()){
		u = q.front();
		q.pop();
		for(int v=1;v<=n;v++){
			if(Free[v]==0 && a[u][v]==1){
				Free[v]=1;
				q.push(v);
			}	
		}
	}
}

int main(){
	cin>>test;
	for(int i=1; i<=test;i++){
		cin>>n>>m;
		
		memset(Free,0,sizeof(Free));
		memset(a,0,sizeof(a));
		
		for(int i=1;i<=m;i++){			
			cin>>u>>v;
			a[u][v]=1;
			a[v][u]=1;	
		}
		
		for (int i=1;i<=n;i++){
			if(Free[i]==0){
				slt++;
				BFS(i);
			}
		}
		cout<<"So thanh phan lien thong: "<<slt<<endl;
	}
	
	return 0;
}

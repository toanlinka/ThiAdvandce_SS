#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int n,m;
bool Free[101];
int f[101];
int moves = 0;
int d[101];
queue<int> q;

void BFS(int s){
	q.push(s);
	Free[s]=true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i=1;i<=6;i++){
			int v = u+i;
			if(v==100){
				cout<<"Ket qua: "<<d[u]+1<<endl;
				return;
			}
			
			if(v<100 && Free[v]==false){
				while(f[v]!=0 && Free[v]==false){
					Free[v]=true;
					v = f[v];
					
					if(v==100){
						cout<<"Ket qua: "<< d[u]+1<<endl;
						return;
					}
				}
				
				if(Free[v]==true){
					continue;
				}
				Free[v]=true;
				q.push(v);
				d[v]=d[u]+1;
			}
		}
	}
	cout<<-1<<endl;
}


int main(){
	memset(f,0,sizeof(f));
	
	cin>>n;
	for(int i=0;i<n;i++){
		int u, v;
		cin>>u>>v;
		f[u]=v;
	}
	
	cin>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		f[u]=v;
	}
	
	BFS(1);
	return 0;
}

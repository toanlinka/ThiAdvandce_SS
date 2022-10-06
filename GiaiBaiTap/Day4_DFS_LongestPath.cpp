#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int a[1001][1001];
int n,m,s,t,u,v;
int Free[100];
stack <int> st;

void DFS(int s){
	st.push(s);
	Free[s]=1;
	while(!st.empty()){
		u = st.top();
		st.pop();
		for(int v=1;v<=m;v++){
			if(a[u][v]==1 && Free[v]==0){
				Free[v]=1;
				st.push(u);
				st.push(v);
				break;
			}
		}
	}
}

int main(){
	cin>>n>>m>>s>>t;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=0;
		}
	}
	
	for(int i=1;i<m;i++){
		cin>>u>>v;
		a[u][v]=1;
		a[v][u]=1;
	}
	return 0;
}

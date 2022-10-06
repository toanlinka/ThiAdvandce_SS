#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int Free[100];
int a[100][100];

void DFS(int s){
	st.push(s);
	Free[s]=1;	
	while(!st.empty()){
		u = st.top();
		st.pop();
		for(int v=0;v<n;v++){
			if(a[u][v]==1){
				Free[v]=2;
				st.push(u);
				st.push(v);
				break;
			}		
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			a[i][j]=0;
		}
	}
	
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		a[u][v]=1;
		a[v][u]=1;
	}
	return 0;
}

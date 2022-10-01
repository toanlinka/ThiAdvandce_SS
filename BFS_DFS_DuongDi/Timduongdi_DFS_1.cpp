#include <bits/stdc++.h>
using namespace std;
int n,m,u,v,Test;
int a[1001][1001];
int s,t;
int Free[1001];
stack <int> st;
int Parent[1001];

void DFS(int s){
	st.push(s);
	Free[s]=1;	
	while(!st.empty()){
		u = st.top();
		st.pop();
		
		for(int v=1;v<=n;v++){
			if(Free[v]==0 && a[u][v]==1){
				Free[v]=1;
				Parent[v]=u;
				st.push(u);
				st.push(v);
				break;
			}		
		}
	}
}

void Path(int s, int t){
		for(int i=1;i<=n;i++){
			Free[i]=0;
			Parent[i]=0;
		}
		DFS(s);
		if(Free[t]==0){
			cout<<"Khong co duong di!";
		}
		else{
			vector <int> path;
			while(t!=s){
				path.push_back(t);
				t = Parent[t];
			}
			path.push_back(s);
			reverse(path.begin(),path.end());
			cout<<"Duong di: ";
			for(int i=0;i<path.size();i++){
				cout<<path[i]<<" ";
			}
		}
}

int main(){
		cin >> n >> m >> s >>t;
		for (int i=1; i<=n; i++)
		        for (int j=1; j<=n; j++)
		            a[i][j]=0;
		 
		for (int i=1; i<=m; i++)
		    {
		        cin >> u>> v;
		        a[u][v]=1;
		        a[v][u]=1;
		    }

		Path(s,t);
		return 0;
}

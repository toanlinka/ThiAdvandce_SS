//link: https://cses.fi/problemset/task/1666
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int n,m,a,b,k;
int Matrix[101][101];
int Free[101];
queue <int> q;
vector <int> re_front;
vector <int> temp;
vector <int> re_back;

void BFS(int s){
	temp.clear();
	temp.push_back(s);
	q.push(s);
	Free[s]=1;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int v=1;v<=n;v++){
			if(Matrix[u][v]==1&&Free[v]==0){
				q.push(v);
				Free[v]=1;
				temp.push_back(v);
			}
		}
	}
	re_front.push_back(temp.front());
	re_back.push_back(temp.back());
}

int main(){
	int slt =0;
	memset(Matrix,0,sizeof(Matrix));
	memset(Free,0,sizeof(Free));
	cin>>n>>m;
	
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		Matrix[a][b]=1;
		Matrix[b][a]=1;
	}
	
	for(int i=1;i<=n;i++){
		if(Free[i]==0){
			BFS(i);
			slt++;
		}
	}
	int road = slt -1;
	cout<<"Number Road: "<<road<<endl;
	int loop =1;
	while(loop<=road){
		cout<<re_back[loop-1]<<" "<<re_front[loop]<<endl;
		loop++;
	}
	
	
	return 0;
}

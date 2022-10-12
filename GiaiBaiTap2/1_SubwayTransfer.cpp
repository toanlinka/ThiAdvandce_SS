#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n,m,s,e,res;
vector<int> line_subway[1001];
vector<int> list_subway[10001];
int count_subway[1001];
int Free[10001];

void BFS(int s){
	queue<pair<int,int> > q;
	for(int u: list_subway[s]){
		for(int sub: line_subway[u]){
			if(Free[sub]==0){
				Free[sub]=1;
				pair <int,int> node = {sub,0};
				q.push(node);
			}
		}
	}
	while(!q.empty()){
		pair<int,int> top = q.front();
		q.pop();
		if(top.first == e){
			res = top.second;
			return;
		}
		for(int u:list_subway[top.first]){
			for(int sub: line_subway[u]){
				if(Free[sub]==0){
					Free[sub]=1;
					pair <int,int> node = {sub,top.second+1};
					q.push(node);
				}
			}
		}
	}
}

int main(){
	cin>>n>>m>>s>>e;
	for(int i=1;i<=m;i++){
		cin>>count_subway[i];
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=count_subway[i];j++){
			int a;
			cin>>a;
			line_subway[i].push_back(a);
			list_subway[a].push_back(i);
		}
	}
	res = -1;
	BFS(s);
	cout<<"Ket qua: "<<res;
	return 0;
}

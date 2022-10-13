#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int n;
int Free[15001];
int result[1];


vector <int> a[15001];

int BFS(int s){
	int sl = 0;
	queue <int> q;
	q.push(s);
	Free[s]=1;
	while(!q.empty()){
		int t = q.front();
		q.pop();
		sl++;
		for(int i: a[t]){
			if(Free[i]==0){
				q.push(i);
				Free[i]=1;
			}
		}
	}
	if(sl == 1){
		return - 1; 
	}
	return sl;
}

int main(){
	int min = 15000;
	int max =0;
	int node = 0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
		if(u>=node){
			node = u;
		}
		if(v>=node){
			node = v;
		}
	}
	
	for(int i=1;i<=node;i++){
		if(Free[i]==0){
			int temp;
			temp = BFS(i);
			if(temp>0){
				if(temp>max){
					max =temp;
				}
				if(temp<min){
					min = temp;
				}
			}
		}
	}
	result[0] = min;
	result[1] = max;
	cout<<"Ket qua: "<<result;
	return 0;
}

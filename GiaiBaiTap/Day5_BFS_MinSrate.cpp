#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int f,s,g,u,d;
int Free[1000001];
int Step[1000001];
vector <int> path;
queue<int> q;

int BFS(int s){
	q.push(s);
	Free[s]=1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int i=0;i<2;i++){
			int x1 = x+path[i];
			if(x1>=1 && x1<=f && Free[x1]==0){
				Step[x1]=Step[x]+1;
				q.push(x1);
				Free[x1]=1;
				if(x1==g){
					return Step[x1];
				}
			}
		}
	}
	return 0;
}

int main(){
	memset(Free,0,sizeof(Free));
	memset(Step,0,sizeof(Step));
	cin>>f>>s>>g>>u>>d;
	path.push_back(u);
	path.push_back(-d);

	int note =BFS(s);
	if(note==0){
		cout<<"use the stairs";
	}
	else{
		cout<<note;
	}
	return 0;
}

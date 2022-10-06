#include <iostream>
#include <vector>
//link: https://www.spoj.com/problems/HERDING/
#include <queue>
using namespace std;

int n,m;
int slt = 0;
int dx[]={0,-1,1,0};
int dy[]={-1,0,0,1};
char xy[]={'N','E','S','W'};
char value2[100][100];
int Free[100][100];
vector <string> value;
queue <pair<int,int> > q;

void BFS(int x,int y){
	cout<<"\nPath: ";
	q.push({x,y});
	Free[x][y]=1;
	while(!q.empty()){
		pair<int,int> top = q.front();
		q.pop();
		cout<<value2[top.first][top.second];
		if(value2[top.first][top.second]=='N'){
			int i1 = top.first + (-1);
			int j1 = top.second;
			if(Free[i1][j1]==0){
				q.push({i1,j1});
				Free[i1][j1]=1;
			}
		}
		else if(value2[top.first][top.second]=='E'){
			int i1 = top.first;
			int j1 = top.second + 1;
			if(Free[i1][j1]==0){
				q.push({i1,j1});
				Free[i1][j1]=1;
			}			
		}
		else if(value2[top.first][top.second]=='S'){
			int i1 = top.first + 1;
			int j1 = top.second;
			if(Free[i1][j1]==0){
				q.push({i1,j1});
				Free[i1][j1]=1;
			}
		}
		else if(value2[top.first][top.second]=='W'){
			int i1 = top.first;
			int j1 = top.second+ (-1);
			if(Free[i1][j1]==0){
				q.push({i1,j1});
				Free[i1][j1]=1;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	string temp;
	getline(cin,temp);
	for(int i=0;i<n;i++){
		getline(cin,temp);
		value.push_back(temp);
	}
	

	for(int i=0;i<n;i++){
		temp = value[i];
		for(int j=0;j<m;j++){
			value2[i][j]=temp[j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(Free[i][j]==0){
				slt++;
				BFS(i,j);
			}
		}
	}
	cout<<"Ket qua: "<<slt;
	
	
	
	
	return 0;
}

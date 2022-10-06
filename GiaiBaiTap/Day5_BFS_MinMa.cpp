//link: https://www.spoj.com/problems/NAKANJ/
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;


int d_x[]={-2,-1,1,2,2,1,-1,-2};
int d_y[]={-1,-2,-2,-1,1,2,2,1};
char text[] = {'a','b','c','d','e','f','g','h'};
int s_x,s_y,e_x,e_y;
int Free[20][20];
int Step[20][20];
queue <pair<int,int> > q;
int m,n;

int BFS(int i, int j,int n,int m){
	q.push({i,j});
	Free[i][j]=1;
	while(!q.empty()){
		pair<int,int> top = q.front();
		q.pop();
		for(int k =0; k<8;k++){
			int i1 = top.first + d_x[k];
			int j1 = top.second + d_y[k];
			if(i1>=1 && i1<=8 && j1>=1 && j1<=8 && Free[i1][j1]==0){
				Step[i1][j1]=Step[top.first][top.second]+1;
				q.push({i1,j1});
				Free[i1][j1]=1;
				if(i1==n&&j1==m){
					return Step[i1][j1];
				}
			}
		}
	}
	return 0;
}


int main(){
	memset(Free,0,sizeof(Free));
	memset(Step,0,sizeof(Step));
	string input;
	getline(cin,input);
	
	s_y=(int)input[1]-48;
	e_y=(int)input[4]-48;
	for(int i=0;i<8;i++){
		if(input[0]==text[i]){
			s_x=i+1;
		}
		if(input[3]==text[i]){
			e_x=i+1;
		}
	}
	
	
	cout<<"Ket qua:"<<BFS(s_x,s_y,e_x,e_y);


	return 0;
}

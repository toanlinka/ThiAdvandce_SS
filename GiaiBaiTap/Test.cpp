#include <iostream>
using namespace std;

char a[50][50];
int b[50][50];
int c[50][50];
int n,m,i,j,index;
bool flag;

bool valid(int i,int j){
	if(i>=0 && i<n && j>=0 && j<m){
		return true;
	}
	else{
		return false;
	}
}

void DFS(int i, int j, int x, int y){
	int dx[]={1,-1,0,0};
	int dy[]={0,0,1,-1};
	
	for(int k=0;k<4;k++){
		int x1 = i+dx[k];
		int y1 = j+dy[k];
		if(valid(x1,y1) && a[i][j]==a[x1][y1]){
			if(b[x1][y1]!=index){
				b[x1][y1]=index;
				DFS(x1,y1,i,j);
			}
			else if(c[x1][y1]!=index && x1!=x && y1!=y){
				flag = 1;
			}
		}
	c[i][j]=index;
	}
}

int main(){
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(flag){
				cout<<"Yes";
				return 0;
			}
			
			b[i][j]=index=j+i*m;
			DFS(i,j,i,j);
		}
	}
	
	cout<<"No";
	return 0;
}

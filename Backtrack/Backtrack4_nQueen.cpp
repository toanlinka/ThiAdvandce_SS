#include <iostream>
using namespace std;

#define N 8

void showResult(int b[][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
}

bool check(int b[N][N],int row, int col){
	int i,j;
	for(i=0;i<col;i++){ //check hang ngang
		if(b[row][i]==1){
			return false;
		}
	}
	
	i = row; j = col;
	while (i>=0 && j>=0){ //check cheo trai tren
		if(b[i][j]==1){
			return false;
		}
		i--;
		j--;
	}
	
	i = row; j=col;
	while (i<N && j>=0){ //check cheo trai duoi
		if(b[i][j]==1){
			return false;
		}
		i++;
		j--;
	}
	return true;
}

bool setQueen(int b[][N], int col){
	if (col>=N){
		return true;
	}
	for(int i=0; i<N; i++){
		if(check(b,i,col)){
			b[i][col]=1;
			if(setQueen(b,col+1)){
				return true;
			}
			b[i][col]=0;
		}
	}
	return false;
}

int main(){
	int b[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			b[i][j]=0;
		}
	}
	if(setQueen(b,0)){
		showResult(b);
	}
	else{
		cout<<"No solution!"<<endl;
	}
	return 0;
}

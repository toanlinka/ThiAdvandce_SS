#include <iostream>
using namespace std;

#define N 8

int isSafe(int x, int y, int sol[N][N]){
	return (x>=0 && x<N && y>=0 && y<N && sol[x][y]==-1);
}

void printSolution(int sol[N][N]){
	for(int x=0;x<N;x++){
		for(int y=0;y<N;y++){
			cout<<" "<<setw(2)<<sol[x][y]<<" ";
			
		}
		cout<<endl;
	}
}

int main(){
	
	return 0;
}

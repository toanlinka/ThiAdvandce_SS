#include <iostream>
using namespace std;
int N,K;
int X[100];

void show(){
	for(int i=1;i<=K;i++){
		cout<<X[i];
	}
	cout<<endl;
}
//max_tohop = N-K+i
//min_tohop = X[i-1]+1

void Try(int i){
	//Duyen cac kha nang nhan duoc
	for(int j= X[i-1]+1;j<=N-K+i;j++){
		X[i]=j;
		if(i==K){
			show();
		}
		else{
			Try(i+1);
		}
	}
}

int main(){
	cin>>N>>K;
	Try(1);
}

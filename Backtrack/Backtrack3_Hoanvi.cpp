#include <iostream>
using namespace std;
int N,K;
int X[100];
int used[100];

void show(){
	for(int i=1;i<=N;i++){
		cout<<X[i];
	}
	cout<<endl;
}
//max_tohop = N-K+i
//min_tohop = X[i-1]+1

void Try(int i){
	//Duyen cac kha nang nhan duoc
	for(int j=1; j<=N;j++){
		if(used[j]==0){
			X[i]=j;
			used[j]=1;
			if(i==N){
				show();
			}
			else{
				Try(i+1);
			}
			used[j]=0;
		}
	}
}

int main(){
	cin>>N;
	Try(1);
}

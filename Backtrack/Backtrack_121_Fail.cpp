#include <iostream>
#include <vector>
using namespace std;
int N,K;
int X[100];
int used[100];
vector <int> Arr;

void show(){
	for(int i=1;i<=N;i++){
		cout<<X[i];
	}
	cout<<endl;
}

void Try(int i){
	//Duyen cac kha nang nhan duoc
	for(int j=0; j<N;j++){
		if(used[j]==0){
			X[i]=Arr[j];
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
	for(int i=1;i<=N;i++){
		int temp;
		cin>>temp;
		Arr.push_back(temp);
	}
	Try(1);
}

//Backtrack1_NhiPhan.cpp
#include <iostream>
using namespace std;

int n,m;
int a[100];

void show(){
	for(int i=1;i<=m;i++){
		cout<<a[i];
	}
}

int Try(int n){
	//Duyet cac kha nang nhan duoc
	for(int i=0;i<=1;i++){
		a[n]=i;
		if(n==m){
			show();
			cout<<endl;
		}
		else{
			Try(n+1);
		}
	}
}

int main(){
	cin>>m;
	Try(1);
	return 0;
}

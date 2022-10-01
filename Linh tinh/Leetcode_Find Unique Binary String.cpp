#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int n,m;
int a[100];
vector <string> input{"111","011","001"};

void show(){
	string temp = "";
	for(int i=1;i<=m;i++){
			temp = temp+to_string(a[i]);
	}
	for(int i =0;i< input.size();i++){
		if(temp==input[i]){
			cout<<temp;
			break;
		}	
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
	m = input.size();
	Try(1);
	return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;
string input;
char alphabet[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
vector <string> result(12);

bool check_al(char a){
	int al = sizeof(alphabet) / sizeof(alphabet[0]);
	for(int i =0;i<al;i++){
		if(alphabet[i]==a){
			return true;
		}
	}
	return false;
}
bool check_ud(char a){
	
}

void Try(int n){
	for(int i =0; i<=input.length();i++){
		if(check_al(input[i])==true){
			
		}
		else{
			result[i]=input[i];
		}
	}

	

}

int main(){
	cin>>input;
	fill(result.begin(),result.end(),"0");
	Try(1);


	return 0;
}

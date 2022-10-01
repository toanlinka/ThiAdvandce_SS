#include <iostream>
#include <stack>

using namespace std;

int main(){
	//push(): them vao
	//pop(): lay ra
	//top(): xem thang dau
	//size(): kich thuoc
	//empty(): check rong
	
	stack <int> Test;
	Test.push(10);
	Test.push(12);
	Test.push(15);
	Test.push(12);
	
	Test.pop();
	
	int size = Test.size();
	cout<<"So phan tu cua Stack: "<<size<<endl;
	cout<<"Phan tu dau: "<<Test.top()<<endl;
	
	cout<<"Cac phan tu trong Stack: ";
	while(!Test.empty()){
		cout<<"\t"<<Test.top();
		Test.pop();
	}
	
	
	return 0;
}

#include <iostream>
#include <queue>

using namespace std;

int main(){
	queue <int> Test;
	Test.push(1);
	Test.push(12);
	Test.push(15);
	Test.push(22);
	
	cout<<"So phan tu: "<<Test.size()<<endl;
	Test.pop();
	cout<<Test.size()<<endl;
	
	cout<<"Phan tu dau tien: "<<Test.front()<<endl;
	cout<<"Phan tu cuoi cung: "<<Test.back()<<endl;
	
	cout<<"Cac phan tu cua Queue: ";
	while (!Test.empty()){
		cout<<"\t"<<Test.front();
		Test.pop();
	}
	
	return 0;
}

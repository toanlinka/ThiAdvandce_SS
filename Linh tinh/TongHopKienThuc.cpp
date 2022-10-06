//Tong hop kien thuc
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//1.Lenght of array
	char arr[] = { 'a','b','c','d','e' };
	cout << "Length arr = " << sizeof(arr) / sizeof(arr[0]) << endl;
	
	//2.Length of string
	string txt = "HuyBlue";
	cout << txt.length()<<"-"<<txt.size()<<endl;;
	
	//3. Check a char/string in string and find index
	string s= "HuyBlue";
	int index = s.find('u');
	if(index !=string::npos){
		cout<<"Yess: "<<index;
	
	//4. Convert lowcase to upcase
	char x = 'u';
	cout<<char(toupper(x))<<char(tolower(x));
	
	//5. Vector
	vector <int> arr_2{ 1,2,3,4,5 };
	cout << arr_2[0];
	cout<< arr_2.size() //size
	
	// fill a gt to all vector
	vector <string> result(12);
	fill(result.begin(),result.end(),"0");
	
	arr_2.front();//xem phan tu dau tien
	arr_2.front();//Xem phan tu cuoi cung
	
	//Array of vector
	vector<int> v[5];
	for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            v[i].push_back(j);
        }
		
	//Vector of Vector
	vector<vector<int> >v;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		vector<int> row;
		for(int j=1;j<=m;j++){
			cin>>a;
			row.push_back(a);
		}
		v.push_back(row);
	}
	//show()
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//6. Memset
	int Free[10];
	memset(Free,0,sizeof(Free));
	cout<<Free[2];
	
	//7.Pair
	pair<int,char>Test;
	Test.first = 100;
	Test.second = 'a';
	cout<<Test.first<<"-"<<Test.second;
	
	//8.Convert data type
	int a =9
	string b;
	b = to_string(a);//int to string
	
	string str ="45";
	int num = stoi(str);//string to int
	
	string test = "b5";//convert char to int
	char k = test[1];
	int x = (int)k -48;//x=5
	
	
	//9/. Measure runtime: #include <chrono>
	auto started = chrono::high_resolution_clock::now();
	//------CODE HERE!----------
	auto done = std::chrono::high_resolution_clock::now();
	cout<<chrono::duration_cast<std::chrono::milliseconds>(done-started).count();

	//10. Struct
	typedef struct a{
		int x;
		int y;
		int z;
	}a;
	queue<a> q;
	
	a Test;
	cin>>Test.x;
	cin>>Test.y;
	cin>>Test.z;
	q.push(Test)
	cout<<Test.x<<Test.y<<Test.z<<endl;
	
	a Test2{14,16,12};
	q.push({14,16,12});
	cout<<Test2.x<<Test2.y<<Test2.z;
		

	

	return 0;
}

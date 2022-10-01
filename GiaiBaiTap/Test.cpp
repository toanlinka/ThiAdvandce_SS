#include <iostream>
#include <string>
#include <chrono>

#include <bits/stdc++.h>

using namespace std;
void fun()
{
    for (int i=0; i<1000; i++)
    {
    	cout<<i;
    }
}

int main(){
//	int a =1;
//	auto started = chrono::high_resolution_clock::now();
//	start = clock();
//	
//	for(int i=0;i<=1000;i++){
//		cout<<i;
//	}
//	auto done = std::chrono::high_resolution_clock::now();
//	cout<<"\nT: "<<chrono::duration_cast<std::chrono::milliseconds>(done-started).count();
    clock_t start, end;
  
    /* Recording the starting clock tick.*/
    start = clock();
  
    fun();
  
    // Recording the end clock tick.
    end = clock();
  
    // Calculating total time taken by the program.
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << time_taken;


	return 0;
}

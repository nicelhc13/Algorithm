#include <iostream>
#include <fstream>

using namespace std;

//
//0 1
//1 2
//2 3
//3 4 
//4 5
//6 7
//7 8
//9 10
//....
int main(void)
{
	ofstream out_file("input3");
	for (int i = 0; i < 100000; i++) {
		out_file << i << " " << i+1	<< " " << i << endl;
	}
	out_file.close();
}


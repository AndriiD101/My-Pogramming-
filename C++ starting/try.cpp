#include <iostream>
#include <vector>
#include <ctime>
#include <stdexcept>
using namespace std;

int main(){
	try{
		int i = 5;
		i = i/1;
	}
	catch(const exception& err){
		cout<< err.what() << endl;
	}
	return 0;
}
#include<iostream>
#include"enigma.h"
#include"errors.h"
using namespace std;

int main(int argc, char** argv){
	Enigma enigma(argc,argv);
	char c;
	while(!cin.eof()){
		cin>>c;
		//cout<<c;  //check input
		if(c<'A'||c>'Z') {
			cout<<"Invalid input character"<<endl;
			exit(INVALID_INPUT_CHARACTER);
		}
		c = enigma.encrypt(c);
		cout<<c;
		cin>>ws;
	}
//	cout<<endl;
	exit(NO_ERROR);

	return 0;
}

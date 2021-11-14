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
			cerr<<c<<" is not a valid input character (input characters must be upper case letters A-Z)!"<<endl;
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

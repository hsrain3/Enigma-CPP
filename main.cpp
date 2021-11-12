#include<iostream>
#include"enigma.h"
#include"errors.h"
using namespace std;

int main(int argc, char** argv){
	Enigma enigma(argc,argv);
	char c;
	while(cin>>c){
		if(c<'A'||c>'Z') {
			cout<<"Invalid input character"<<endl;
			exit(INVALID_INPUT_CHARACTER);
		}
		char res = enigma.encrypt(c);
		cout<<res;
	}
	cout<<endl;
	exit(NO_ERROR);

	return 0;
}

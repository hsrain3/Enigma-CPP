#include"common.h"
#include"errors.h"
#include<fstream>
#include<iostream>
using namespace std;
bool checkNumeric(const char* filename){
	ifstream in;
	in.open(filename);
	if(in.fail()){
		cerr<<"error opening configuration file"<<endl;
		exit(ERROR_OPENING_CONFIGURATION_FILE);
	}
	char ch;
	in>>ch;
	while(!in.eof()){
/*	if(ch == '\n') {
			in>>ch;
			continue;
		}*/
		if(ch>'9'||ch < '0'){
			return false;
		}
		in>>ch;

	}
	in.close();
	return true;
}

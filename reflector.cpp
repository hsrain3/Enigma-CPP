#include"reflector.h"
#include<fstream>
#include<iostream>
#include"common.h"
#include"errors.h"
using namespace std;
Reflector::Reflector(){}
Reflector::~Reflector(){}
void Reflector::inputMap(const char* filename){
	if(!checkNumeric(filename)){
		cout<<"Non numeric character"<<endl;
		exit(NON_NUMERIC_CHARACTER);
	}
	ifstream in;
	in.open(filename);
	int count = 0;
	int a,b;
	in>>a;
		
	if(!in.eof()) in>>b;
	else {
		cout<<"Incorrect number of reflector parameters"<<endl;
		exit(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);
	}
	while(!in.eof()){
		count++;
		if(count > 13) {
			cout<<"Incorrect number of reflector parameters"<<endl;
			exit(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);
		}
		if(map1.count(a)||a == b||map2.count(b)){
			cout<<"Invalid reflector mapping"<<endl;
	   		exit(INVALID_REFLECTOR_MAPPING);
		}
		if(a<0||a>25||b<0||b>25){
			cout<<"Invalid index error in reflector"<<endl;	
	   		exit(INVALID_INDEX);
		}
		//cout<<"debug "<<a<<b<<endl;
		map1.insert({a,b});
		map2.insert({b,a});
		in>>a;
		if(in.eof()) break;
		in>>b;
		if(in.eof()) {
			cout<<"Incorrect number of reflector parameters"<<endl;
			exit(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);
		}	
	}
	if(count < 13) {
		cout<<"Incorrect number of reflector parameters"<<endl;
		exit(INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS);
	}
	in.close();

}

int Reflector::getOutput(int input){
	if(map1.count(input)) return map1[input];
    return map2[input];
	
}

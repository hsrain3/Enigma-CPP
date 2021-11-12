#include"errors.h"
#include "Plugboard.h"
#include"common.h"
#include<fstream>
#include<iostream>
using namespace std;
Plugboard::Plugboard(){}
Plugboard::~Plugboard(){}
void Plugboard::inputMap(const char* filename){
	if(!checkNumeric(filename)){
		cout<<"Input Non numeric character"<<endl;
		exit(NON_NUMERIC_CHARACTER);
	} 
	ifstream in;
	in.open(filename);
	int a,b;
	in>>a;
	if(in.eof()) return;
	in>>b;
	
	if(in.eof()) {
		cout<<"Incorrect number of plugboard parameters"<<endl;
		exit(INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS);
	}
	while(!in.eof()){
		if(map1.count(a)||a == b||map2.count(b)){
			cout<<"Impossible plugboard configuration"<<endl;
	   		exit(IMPOSSIBLE_PLUGBOARD_CONFIGURATION);
		}
		if(a<0||a>25||b<0||b>25){
			cout<<"Invalid index error"<<endl;	
	   		exit(INVALID_INDEX);
		}
		//cout<<"debug "<<a<<b<<endl;
		map1.insert({a,b});
		map2.insert({b,a});
		in>>a;
		if(in.eof()) break;
		in>>b;
		if(in.eof()) {
			cout<<"Incorrect number of plugboard parameters"<<endl;
			exit(INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS);
		}	
	}
	
	in.close();
}
int Plugboard::getOutput(int input){
	if(map1.count(input)) return map1[input];
	else if(map2.count(input))	return map2[input];
	return input;
}

#include"rotor.h"
#include"errors.h"
#include"common.h"
#include<iostream>
#include<fstream>
#include<unordered_set>
using namespace std;

Rotor::Rotor(int startPos){
	for(int i = 0;i < 26;i ++) notchPos[i] = -1;
	absPos = startPos; 
}
Rotor::~Rotor(){}
void Rotor::inputRotor(const char* filename){
	if(!checkNumeric(filename)) {
		cerr<<"Non-numeric character for mapping in rotor file "<<filename<<endl;
		exit(NON_NUMERIC_CHARACTER);
	}
	ifstream in;
	in.open(filename);
	int a;
	in>>a;
	int i = 0;
	unordered_set<int>tmp;
	while(i<26){
		if(tmp.count(a)||in.eof()) {
			cerr<<"Invalid rotor mapping"<<endl;
			exit(INVALID_ROTOR_MAPPING);
		}
		if(a<0||a>25) {
			cerr<<"Invalid index in rotor config"<<endl;
			exit(INVALID_INDEX);
		}
		tmp.insert(a);
		forwardMap[i] = a;
		backwardMap[a] = i; //
		i ++;
		in>>a;
	}
	i = 0;
	while(!in.eof()){
		in>>a;
		if(a<0||a>25) {
			cerr<<"Invalid index in rotor config"<<endl;
			exit(INVALID_INDEX);
		}
		notchPos[(a-absPos+length)%length] = 1;
		
	}

	in.close();
}
void Rotor::setPos(int p){
	absPos = p;
}
void Rotor::rotate(){
	int tmpNotch = notchPos[0];
	absPos = (absPos + 1)%length;
	for(int i = 0;i < 25;i ++){
		notchPos[i] = notchPos[i+1];			
	}
	notchPos[25] = tmpNotch;



}

bool Rotor::rotateNext(){
	if(notchPos[0] == 1) return true;
	return false;	
}

int Rotor::getOutputForward(int inputIndex){
	int input = (inputIndex + absPos)%length;
	int output = forwardMap[input];
	int absOutput = (output - absPos + length)%length;
	return absOutput;	

}

int Rotor::getOutputBackward(int inputIndex){
	int input = (inputIndex + absPos)%length;
	int output = backwardMap[input];
	int absOutput = (output - absPos + length)%length;
	return absOutput;
}



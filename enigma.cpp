#include<fstream>
#include<iostream>
#include"errors.h"
#include"enigma.h"
#include"common.h"
using namespace std;
Enigma::Enigma(int argc,char** argv){
	if(argc < 4){
		cout<<"Insuffieient number of parameters"<<endl;
		exit(INSUFFICIENT_NUMBER_OF_PARAMETERS);

	}
	rotorNumber = argc - 4;
	if(rotorNumber < 0) {
		cout<<"Insufficient number of parameters"<<endl;
		exit(INSUFFICIENT_NUMBER_OF_PARAMETERS);
	}
	plugboard.inputMap(argv[1]);
	reflector.inputMap(argv[2]);
	configRotorPos(argv[argc-1]);
	if(rotorPos.size() < rotorNumber) {
		cout<<"No rotor starting position"<<endl;
		exit(NO_ROTOR_STARTING_POSITION);
	}
	// initiate rotors
	for (int i = 3;i < argc - 1;i ++){
			//left to right
		Rotor rotor(rotorPos[i-3]);
		rotor.inputRotor(argv[i]);
		rotors.push_back(rotor);


	}	
}
Enigma::~Enigma(){}
void Enigma::configRotorPos(const char* filename){
	if(rotorNumber == 0) return;
	if(!checkNumeric(filename)) {
		cout<<"Non numeric character"<<endl;
		exit(NON_NUMERIC_CHARACTER);
	}
	ifstream in;
	in.open(filename);
	for(int i = 0;i < rotors.size();i ++){
		if(in.eof()) {
			cout<<"No rotor starting position"<<endl;
			exit(NO_ROTOR_STARTING_POSITION);
		}
		int tmp;
		in>>tmp;
		if(tmp <0 ||tmp > 25){
			cout<<"Invalid index in"<<endl;
			exit(INVALID_INDEX);
		}
		rotorPos.push_back(tmp);
	}
	in.close();
}
char Enigma::encrypt(char letter){
	int l = letter - 'A';
	//plugboard	
	//
	int tmp = plugboard.getOutput(l);
	for(int i = rotorNumber - 1;i >= 0;i --){
		tmp = rotors[i].getOutputForward(tmp);
	}
	tmp = reflector.getOutput(tmp);
	for(int i = 0;i < rotorNumber;i ++){
		tmp = rotors[i].getOutputBackward(tmp);
	}
	tmp = plugboard.getOutput(tmp);
	//rotate for next
	rotors[rotorNumber-1].rotate();
	for(int i = rotorNumber - 2;i >= 0;i --){
		if(rotors[i+1].rotateNext()) rotors[i].rotate();
		else break;
	}
	return tmp;

}

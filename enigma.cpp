#include<fstream>
#include<iostream>
#include"errors.h"
#include"enigma.h"
#include"common.h"
using namespace std;
Enigma::Enigma(int argc,char** argv){
	if(argc < 4){
		cerr<<"usage: enigma plugboard-file reflector-file (<rotor-file>)* rotor-positions"<<endl;
		exit(INSUFFICIENT_NUMBER_OF_PARAMETERS);

	}
	rotorNumber = argc - 4;
	plugboard.inputMap(argv[1]);
	reflector.inputMap(argv[2]);
	configRotorPos(argv[argc-1]);
	if(rotorPos.size() < rotorNumber) {
		cerr<<"No rotor starting position"<<endl;
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
		cerr<<"Non numeric character in rotor position file "<<filename<<endl;
		exit(NON_NUMERIC_CHARACTER);
	}
	ifstream in;
	in.open(filename);
	int tmp;
	in>>tmp;
	while(!in.eof()){	
		if(tmp <0 ||tmp > 25){
			cerr<<"Invalid index in"<<endl;
			exit(INVALID_INDEX);
		}
		rotorPos.push_back(tmp);
		in>>tmp;
	}
	in.close();
}
char Enigma::encrypt(char letter){
	int l = letter - 'A';
	//rotate first
	if(rotorNumber > 0){
		rotors[rotorNumber-1].rotate();
		for(int i = rotorNumber - 2;i >= 0;i --){
			if(rotors[i+1].rotateNext()) rotors[i].rotate();
			else break;
		}
	}
	//plugboard
	int tmp = plugboard.getOutput(l);
	for(int i = rotorNumber - 1;i >= 0;i --){
		tmp = rotors[i].getOutputForward(tmp);
	}
	tmp = reflector.getOutput(tmp);
	for(int i = 0;i < rotorNumber;i ++){
		tmp = rotors[i].getOutputBackward(tmp);
	}
	tmp = plugboard.getOutput(tmp);
	char d = tmp + 'A';
	return d;

}

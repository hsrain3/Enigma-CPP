#ifndef ENIGMA_H
#define ENIGMA_H
#include<vector>
#include"rotor.h"
#include"Plugboard.h"
#include"reflector.h"
class Enigma{
	vector<Rotor>rotors;
	vector<int>rotorPos;
	int rotorNumber;
	Plugboard plugboard;
	Reflector reflector;	
public:
	Enigma(int argc,char** argv);
	~Enigma();
	void configRotorPos(const char* filename);
	char encrypt(char letter);
		
};
#endif

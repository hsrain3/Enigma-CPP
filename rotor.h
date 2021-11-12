#ifndef ROTOR_H
#define ROTOR_H
#include<unordered_map>
class Rotor{
	int forwardMap[26];
	int backwardMap[26];
	//unordered_map<int,int>rotorMap;
	int notchPos[26]; //abs
	int absPos;
public:
	Rotor(int startPos);
	~Rotor();
	void inputRotor(const char* filename);
	void rotate();
	void setPos(int p);
	bool rotateNext();
	int getOutputForward(int inputIndex);
	int getOutputBackward(int inputIndex);
};
#endif

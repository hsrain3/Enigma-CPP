#ifndef REFLECTOR_H
#define REFLECTOR_H
#include<unordered_map>
using namespace std;
class Reflector{
	unordered_map<int,int>map1;
	unordered_map<int,int>map2;
public:	
	Reflector();
	~Reflector();
	void inputMap(const char* filename);
	int getOutput(int input);

};
#endif

#ifndef PLUG_B
#define PLUG_B
#include<unordered_map>
using namespace std;
class Plugboard {
	unordered_map<int,int>map1;
	unordered_map<int,int>map2;
public:
	Plugboard();
	~Plugboard();
	void inputMap(const char* filename);	
	int getOutput(int input);	
};

#endif

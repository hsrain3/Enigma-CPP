OBJ = main.o enigma.o Plugboard.o rotor.o reflector.o common.o
EXE =  enigma
CXX = g++
CXXFLAGS = -Wall -g

$(EXE): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

main.o: enigma.h

enigma.o: enigma.h Plugboard.h rotor.h reflector.h errors.h common.h

Plugboard.o: Plugboard.h errors.h common.h

rotor.o: rotor.h errors.h common.h

reflector.o: reflector.h errors.h common.h

common.o: common.h errors.h

.PHONY: clean
clean:
	rm -f $(OBJ) $(EXE)

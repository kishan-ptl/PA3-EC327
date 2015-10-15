# in EC327, we use the ${GCC} compiler
# therefore, we define the GCC variable
GCC = g++ 


UnderTheSea: PA3.o GameObject.o Fish.o Cave.o CoralReef.o CartPoint.o CartVector.o Model.o View.o GameCommand.o
	${GCC} PA3.o GameObject.o Fish.o Cave.o CoralReef.o CartPoint.o CartVector.o Model.o View.o GameCommand.o -o UnderTheSea

PA3.o: PA3.cpp
	${GCC} -c PA3.cpp

GameObject.o: GameObject.cpp
	${GCC} -c GameObject.cpp

Fish.o: Fish.cpp
	${GCC} -c Fish.cpp

Cave.o: Cave.cpp
	${GCC} -c Cave.cpp

CoralReef.o: CoralReef.cpp
	${GCC} -c CoralReef.cpp

CartPoint.o: CartPoint.cpp
	${GCC} -c CartPoint.cpp

CartVector.o: CartVector.cpp
	${GCC} -c CartVector.cpp

Model.o: Model.cpp
	${GCC} -c Model.cpp

View.o: View.cpp
	${GCC} -c View.cpp

GameCommand.o: GameCommand.cpp
	${GCC} -c GameCommand.cpp

clean:
	rm PA3.o GameObject.o Fish.o Cave.o CoralReef.o CartPoint.o CartVector.o Model.o View.o GameCommand.o UnderTheSea  

#Makefile for Lab 12 - Golf Game
#Isobel Murrer and Hannah Sarkey
#12/8/18

CMP = g++ -std=c++11
MAIN = project
CLASS = golf
EXEC = golf

$(EXEC): $(MAIN).o $(CLASS).o
	$(CMP) $(CLASS).o $(MAIN).o gfx3.o -lX11 -o $(EXEC)
  
$(MAIN).o: $(MAIN).cpp $(CLASS).h
	$(CMP) -c $(MAIN).cpp -o $(MAIN).o
  
$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -c $(CLASS).cpp -o $(CLASS).o

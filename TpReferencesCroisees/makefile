CC=g++
EDL=g++
RM=rm

CCFLAGS=-Wall
LDFLAGS=
RMFLAGS=-f
LIBS=

EXE=TP_STL.exe
INTERFACE=AssocRefFichier.h References.h
REALISATION=$(INTERFACE:.h=.cpp) Main.cpp
OBJ=$(REALISATION:.cpp=.o)

$(EXE): $(OBJ)
	$(EDL) $(LDFLAGS) -o $@ $^ $(LIBS)

clean:
	$(RM) $(RMFLAGS) $(EXE) $(OBJ)
	
References.o: References.h AssocRefFichier.h

AssocRefFichier.o: AssocRefFichier.h

Main.o: References.h

%.o: %.cpp
	$(CC) $(CCFLAGS) -c $<


# for use with C++ files
.SUFFIXES: .cpp


# &&&&&&  Enter your own source file names   &&&&&&
SOURCES = main.cpp functions.cpp Game.cpp GameBoard.cpp Player.cpp Player2.cpp Ship.cpp


# &&&&&& Enter your own executable program name &&&&&&
TARGET = armada

#-------Do Not Change below this line-------------
#Compile with g++
CC = g++ 

#use -g for gnu debugger and -std= for c++11 compiling
CXXFLAGS = -g -std=c++17
OBJS:= ${SOURCES:.cpp=.o}

######Do NOT change this...Tabs Matter!#########
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
.cpp.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<
    
#In order to get rid of all .o files create, at the command prompt
#make clean
clean:
	rm -f $(OBJS) $(TARGET) core *.txt
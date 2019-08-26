
.PHONY: depend clean

PWD = $(shell pwd)

# HEADERS
INCLUDES =  -I$(PWD)/../../../../MyLibC++/BinaryTree/ \
	       
# LIBRARY
LIB += $(PWD)/../../../../MyLibC++/BinaryTree/MyBinSearchTree.cpp 
LIB += $(PWD)/../../../../MyLibC++/BinaryTree/MyTreeUtils.cpp 
LIB += $(PWD)/../../../../MyLibC++/Stack/MyStackTreeNode.cpp 

# Source file path 
SRC_PATH :=$(PWD)/src
SRC += $(SRC_PATH)/main.cpp

# Object file path
OBJ_PATH :=$(PWD)/obj
OBJ += $(patsubst %.cpp, %.o, $(LIB))
OBJ += $(patsubst %.cpp, %.o, $(SRC))

EXEC = $(bin)
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -v $(INCLUDES)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)
	mv $(OBJ) $(OBJ_PATH)

all: $(OBJ)
	$(CXX) $(INCLUDES) $(CXXFLAGS) -o $(EXEC) $(OBJ)
	mv $(OBJ) $(OBJ_PATH)
	@echo  Compilation successful!

.c.o:
	$(CXX) $(INCLUDES) $(CXXFLAGS) -c $<  -o $@

clean:
	$(RM) $(EXEC) $(OBJ_PATH)/*.o $(OBJ_PATH)/*~ *.o *~

depend: $(SRC)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it


.PHONY: depend clean

PWD = $(shell pwd)

# Header file path
INCLUDES = 	-I$(PWD)/../../../../../app_util/utils				\
		   			-I$(PWD)/../../../../../app_util/stack 			\
		   			-I$(PWD)/../../../../../app_util/queue 			\
		   			-I$(PWD)/../../../../../app_util/binarytree 	\
	       
# Library file path
LIB += $(PWD)/../../../../../app_util/utils/MyTreeUtils.cpp
LIB += $(PWD)/../../../../../app_util/stack/MyStackTreeNode.cpp
LIB += $(PWD)/../../../../../app_util/stack/MyStack.cpp
LIB += $(PWD)/../../../../../app_util/binarytree/MyBinSearchTree.cpp

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

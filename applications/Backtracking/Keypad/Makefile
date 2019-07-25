
.PHONY: depend clean

PWD = $(shell pwd)

# Header file path
INCLUDES = 	-I$(PWD)/../../library/utils/ 				\
	       		-I$(PWD)/../../library/binarytree/ 	\

# Library file path
#LIB += $(PWD)/../../utils/MyTreeUtils.cpp

# Source file path
SRC_PATH :=$(PWD)/src
SRC += $(SRC_PATH)/main.cpp

# Object file path
OBJ_PATH :=$(PWD)/obj
OBJ += $(patsubst %.cpp, %.o, $(LIB))
OBJ += $(patsubst %.cpp, %.o, $(SRC))

EXEC = $(bin)
CXX = g++
DEBUG ?= 0
ifeq ($(DEBUG), 1)
    CXXFLAGS = -Wall -g -v -DDEBUG $(INCLUDES)
else
    CXXFLAGS = -Wall -g -v $(INCLUDES)
endif

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

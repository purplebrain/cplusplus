
.PHONY: depend clean

PWD = $(shell pwd)

# Header file path
# (none)

# Library file path
# (none)

# Source file path
SRC_PATH :=$(PWD)/src
SRC += $(SRC_PATH)/main.cpp
SRC += $(SRC_PATH)/vehicleFactory.cpp
SRC += $(SRC_PATH)/vehicle.cpp
SRC += $(SRC_PATH)/car.cpp
SRC += $(SRC_PATH)/truck.cpp
SRC += $(SRC_PATH)/parking.cpp

# Object file path
OBJ_PATH :=$(PWD)/obj
OBJ += $(patsubst %.cpp, %.o, $(LIB))
OBJ += $(patsubst %.cpp, %.o, $(SRC))

EXEC = $(bin)
CXX = g++
CXXFLAGS = -Wall -g -v $(INCLUDES)

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

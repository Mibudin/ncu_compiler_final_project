# For NCU Compiler Final Project
# 	For programs compiled with Flex and Yacc.
# 
# 	Specified Language:
# 		C, LEX, YACC
# 	Specified Compiler:
# 		GCC 5.4
# 	Specified Compiling Command:
# 		"/usr/bin/gcc -DONLINE_JUDGE -O2 -w -fmax-errors=3 -std=c99 {src_path} -lm -o {exe_path}"


# Settings

# Set the target environment
# TARGET_ENV	:= OJ
TARGET_ENV	:= 

# Set the target for this makefile
# INDEX	:= 3a
# TARGET	:= hw$(INDEX)
TARGET	:= mnlsp

# Set the file structure
BIN_DIR	:= ./bin
SRC_DIR	:= ./src
OBJ_DIR	:= ./build
INC_DIR	:= ./inc
LIB_DIR	:= ./lib
CXX_DIR	:= ./build
DOC_DIR	:= ./doc

# Set the compiling settings
# 	(Flex would generate C99 codes in default)
CC		:= g++
C_FLAGS	:= -O2 -w -fmax-errors=3 -std=c++14
ifeq ($(TARGET_ENV), OJ)
C_FLAGS += -DONLINE_JUDGE
endif

# Set the Yacc settings
YACC	:= bison
Y_FLAGS	:= -d --defines=$(INC_DIR)/$(TARGET).tab.h
# 	Used if want to know the detailed conflicts
Y_FLAGS	+= -v --report-file=$(DOC_DIR)/$(TARGET).output

# Set the Lex settings
LEX		:= flex
L_FLAGS	:= 

# Set the libraries
LIBS	:= -lfl
ifeq ($(TARGET_ENV), OJ)
LIBS	+= -lm
endif

# Set the lex target file
# LEXYYC	:= $(TARGET).yy.c

# Problrms about names of files
ifeq ($(OS),Windows_NT)
EXECUTABLE	:= $(TARGET).exe
RM	:= del
else
EXECUTABLE	:= $(TARGET)
endif


# Commands

# Compile all the specified files (if needed)
all: $(BIN_DIR)/$(EXECUTABLE)

# Clean all the executable files
cleanbin:
	$(RM) $(BIN_DIR)/$(EXECUTABLE)

# Clean all the object files
cleanobj:
	$(RM) $(OBJ_DIR)/$(TARGET).tab.o $(OBJ_DIR)/$(TARGET).yy.o

# Clean all the generated C header files
cleaninc:
	$(RM) $(INC_DIR)/$(TARGET).tab.h

# Clean all the generated C source files
cleancxx:
	$(RM) $(CXX_DIR)/$(TARGET).tab.cpp $(CXX_DIR)/$(TARGET).yy.cpp

# Clean all the generated Bison report files
cleandoc:
	$(RM) $(DOC_DIR)/$(TARGET).output

# Clean all the generated files
clean: cleanbin cleanobj cleaninc cleancxx cleandoc

# Compile all the specified files (if needed), and excute them
run: all
	$(BIN_DIR)/$(EXECUTABLE)

# Compile the Yacc file
$(CXX_DIR)/$(TARGET).tab.cpp: $(SRC_DIR)/$(TARGET).y
	$(YACC) $(Y_FLAGS) -o $@ $<

# Compile the Lex file
$(CXX_DIR)/$(TARGET).yy.cpp: $(SRC_DIR)/$(TARGET).l $(INC_DIR)/$(TARGET).tab.h $(INC_DIR)/$(TARGET).hpp
	$(LEX) $(L_FLAGS) -o $@ $<

# Compile the MNLSP file
$(OBJ_DIR)/$(TARGET).o: $(SRC_DIR)/$(TARGET).cpp $(INC_DIR)/$(TARGET).hpp
	$(CC) $(C_FLAGS) -I$(INC_DIR) -L$(LIB_DIR) $(LIBS) -c $< -o $@

# Compile the object files
$(OBJ_DIR)/%.o: $(CXX_DIR)/%.cpp
	$(CC) $(C_FLAGS) -I$(INC_DIR) -L$(LIB_DIR) $(LIBS) -c $< -o $@

# Compile the specified file
$(BIN_DIR)/$(EXECUTABLE): $(OBJ_DIR)/$(TARGET).tab.o $(OBJ_DIR)/$(TARGET).yy.o $(OBJ_DIR)/$(TARGET).o
	$(CC) $(C_FLAGS) -I$(INC_DIR) -L$(LIB_DIR) $(LIBS) $^ -o $@

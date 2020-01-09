.PHONY: clean run_test run_wx mkdir
INC=inc
BIN=bin
SRC=src
OBJ=obj
TEST=test
CC=g++
CFLAG=-std=c++11 -Wfatal-errors
WXFLAG=`wx-config --libs` `wx-config --cxxflags`
LIB=-lgtest -lpthread

all: clean mkdir $(BIN)/ut_all 
$(BIN)/ut_all:$(TEST)/ut_main.cpp $(TEST)/ut_file_system.h $(OBJ)/node.o $(OBJ)/file.o $(OBJ)/folder.o $(OBJ)/null_iterator.o $(OBJ)/link.o $(OBJ)/filesystem_builder.o $(OBJ)/update_path_visitor.o
	$(CC) $(CFLAG) $< $(OBJ)/node.o $(OBJ)/file.o $(OBJ)/folder.o $(OBJ)/null_iterator.o $(OBJ)/link.o $(OBJ)/filesystem_builder.o $(OBJ)/update_path_visitor.o  -o $@ $(LIB)

$(OBJ)/node.o:$(SRC)/node.cpp $(INC)/node.h $(INC)/string_utility.h $(INC)/iterator.h
	$(CC) $(CFLAG) -c $< -o $@ $(LIB)

$(OBJ)/file.o:$(SRC)/file.cpp $(INC)/file.h 
	$(CC) $(CFLAG) -c $< -o $@ $(LIB)

$(OBJ)/link.o:$(SRC)/link.cpp $(INC)/link.h 
	$(CC) $(CFLAG) -c $< -o $@ $(LIB)

$(OBJ)/folder.o:$(SRC)/folder.cpp $(INC)/folder.h 
	$(CC) $(CFLAG) -c $< -o $@ $(LIB)

$(OBJ)/null_iterator.o:$(SRC)/null_iterator.cpp $(INC)/null_iterator.h 
	$(CC) $(CFLAG) -c $< -o $@ $(LIB)

$(OBJ)/filesystem_builder.o:$(SRC)/filesystem_builder.cpp $(INC)/filesystem_builder.h 
	$(CC) $(CFLAG) -c $< -o $@ $(LIB)

$(OBJ)/update_path_visitor.o:$(SRC)/update_path_visitor.cpp $(INC)/update_path_visitor.h 
	$(CC) $(CFLAG) -c $< -o $@ $(LIB)
################################################################
clean: 
	rm -f $(BIN)/* 
mkdir: 
	mkdir -p $(BIN) 
	mkdir -p $(OBJ)
################################################################
run_test: 
	$(BIN)/ut_all 
run_wx: 
	$(BIN)/wx_Widget test_data
################################################################



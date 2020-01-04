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

$(BIN)/ut_all:$(TEST)/ut_main.cpp $(TEST)/ut_file_system.h
	$(CC) $(CFLAG)  -o $@ $<  $(LIB)



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



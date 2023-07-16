CXX=clang++
INCLUDES=-I includes/
CXX_FLAGS=-std=c++20 -g -O0 -Wall -Wextra -Werror -Iincludes/
# LD = clang++
# LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

exec: bin/main
tests: bin/tests

# main.o : src/main.cc includes/fileManagement includes/audioCompression
# 	$(CXX) $(CXX_FLAGS) main.cc

# catchmain.o : catch/catchmain.cpp catch/catch.hpp
# 	$(CXX) $(CXX_FLAGS) catch/catchmain.cpp

# tests.o : tests/tests.cc catch/catch.hpp src/fileManagement.cc includes/fileManagement.hpp src/audioCompression.cc includes/audioCompression.hpp
# 	$(CXX) $(CXX_FLAGS) tests/tests.cc

# fileManagement.o : src/fileManagement.cc includes/fileManagement.hpp src/audioCompression.cc includes/audioCompression.hpp
# 	$(CXX) $(CXX_FLAGS) src/fileManagement.cc

bin/main: src/main.cc includes/fileManagement.hpp src/fileManagement.cc includes/audioCompression.hpp src/audioCompression.cc includes/readWavFile.hpp src/readWavFile.cc
	${CXX} ${CXX_FLAGS} src/main.cc src/fileManagement.cc src/audioCompression.cc src/readWavFile.cc -o bin/exec

bin/tests: tests/tests.cc includes/fileManagement.hpp src/fileManagement.cc includes/audioCompression.hpp src/audioCompression.cc includes/readWavFile.hpp src/readWavFile.cc
	${CXX} ${CXX_FLAGS} tests/tests.cc src/fileManagement.cc src/audioCompression.cc  src/readWavFile.cc -o bin/tests

clean:
	rm -rf bin/*


.DEFAULT_GOAL := exec
.PHONY: clean exec tests



# MAIN FUNCTION:
# make exec
# bin/exec

# TEST CASES: 
# make tests
# bin/tests
CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrecTest: llrecTest.o
	$(CXX) llrecTest.o -o llrec-test

llrecTest.o: llrec-test.cpp llrec.h
	$(CXX) $(CPPFLAGS) $(VALGRIND) -c llrec-test.cpp -o $@

stack_test: stack_test.cpp stack.h random_generator.h
	$(CXX) $(CXXFLAGS) -o $@ stack_test.cpp $(GTEST_FLAGS)


clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 
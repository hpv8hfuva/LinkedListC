#Hunter Vaccaro
#hpv8hf
#Lab Section 11:00 am
CXX = clang $(CXXFLAGS)
CXXFLAGS = -Wall -g
LinkedList: linkedlist.o
	$(CXX) linkedlist.o
linkedlist: linkedlist.c
	$(CXX) linkedlist.c
clean:
	-rm *.o *~ LinkedList.exe

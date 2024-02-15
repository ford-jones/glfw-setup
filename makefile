OSFLAGS :=
ifeq ($(shell uname),Linux)
	OSFLAGS += -lGL -lGLEW -lglfw
endif

OBJECTS = main.o src/WindowManager.o

CXX = g++ -lstdc++fs -std=c++17

run: $(OBJECTS)
		$(CXX) -o run $(OBJECTS) $(CXXFLAGS) $(OSFLAGS)

debug: $(OBJECTS)
		$(CXX) -g -o run $(OBJECTS) $(CXXFLAGS) $(OSFLAGS)

main.o := main.h
WindowManager.o := hdr/WindowManager.h

clean : 
		rm run $(OBJECTS)

# Universitaet Stuttgart, ES - ITI 
# Modeling, Specification and Simulation SS 2014
# Feel free to modify this Makefile 

# These should point to the correct SystemC directories
SYSTEMC_INCDIR = /usr/include/sysc
SYSTEMC_LIBDIR = /usr/lib

# can be defined externally, such as DEBUG_ENABLED
CDEFINE = 

CXX     = g++
CXXFLAGS = -O1 -g -Wall -Wno-reorder $(CDEFINE)

INCDIR = -I. -I $(SYSTEMC_INCDIR)

LDFLAGS = -L. -L $(SYSTEMC_LIBDIR) -Wl,-rpath,$(SYSTEMC_LIBDIR)
LDLIBS = -lsystemc

HEADERS := $(wildcard *.h)
SOURCES := $(wildcard *.cpp)
OBJECTS := $(SOURCES:.cpp=.o)
MAIN = main.cpp

TARGET = $(notdir $(shell pwd))

$(TARGET): $(OBJECTS) $(MAIN)
	$(CXX) $(LDFLAGS) $(LDLIBS) -o $@ $(OBJECTS)
	@echo
	@echo "----------------------------------------"
	@echo " Compilation finished successfully!"
	@echo " Run simulation with the following command:"
	@echo " ./$@"

clean:  
	-rm $(TARGET) $(OBJECTS)

$(MAIN): $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCDIR) -c -o $(MAIN:.cpp=.o) $(MAIN)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCDIR) -c -o $@ $<

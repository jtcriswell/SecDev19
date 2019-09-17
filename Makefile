CXXFLAGS := -g -Og -fpic -fno-rtti -fno-exceptions

OBJS := SecDev.o

all: SecDev.so

SecDev.so: $(OBJS)
	$(CXX) $(LDFLAGS) -shared $^ -o $@ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

SecDev.o: SecDev.cpp SecDev.h

clean:
	rm -rf $(OBJS) SecDev.so

.PHONY: all clean

WARNFLAGS := -Wall -Wextra -pedantic
CPPFLAGS := $(WARNFLAGS)
CXXFLAGS := -g -Og -fpic -fno-rtti -fno-exceptions

OBJS := SecDev.o lib/secdevchecker.o

all: SecDev.so lib/libsecdevchecker.a

SecDev.so: $(OBJS)
	$(CXX) $(LDFLAGS) -shared $^ -o $@ $(LDLIBS)

lib/libsecdevchecker.a: lib/secdevchecker.o
	$(AR) cr $@ $^

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

SecDev.o: SecDev.cpp SecDev.h

lib/secdevchecker.o: lib/secdevchecker.c
lib/secdevchecker.o: CFLAGS += -O3 -fpic

clean:
	rm -rf $(OBJS) SecDev.so lib/libsecdevchecker.a run/

.PHONY: all clean

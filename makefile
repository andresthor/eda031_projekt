# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = g++

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of libstd++.
CPPFLAGS  = -std=c++11 -I..
CXXFLAGS  = -g -O2 -Wall -W -pedantic-errors
CXXFLAGS += -Wmissing-braces -Wparentheses -Wold-style-cast
CXXFLAGS += -std=c++11
LDFLAGS   = -g -L..
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

OUTPUT = bin/
#SERVER = src/server/

# Targets
PROGS = src/server/testMain

all: $(PROGS)
	mv src/server/testMain $(OUTPUT)

# Targets rely on implicit rules for compiling and linking
src/server/testMain: src/server/testMain.o src/server/article.o src/server/newsgroup.o

# Phony targets
.PHONY: all clean

# Standard clean
clean:
	rm -f *.o $(PROGS)
	rm -f *.d
	rm -f src/server/*.o
	rm -f bin/testMain

# Generate dependencies in *.d files
%.d: %.cc
	@set -e; rm -f $@; \
         $(CPP) -MM $(CPPFLAGS) $< > $@.$$$$; \
         sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
         rm -f $@.$$$$

# Include the *.d files
SRC = $(wildcard *.cc)
include $(SRC:.cc=.d)

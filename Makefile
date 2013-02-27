OBJS = src/fast_cluster.o src/hasher.o  src/hasher.o lib/city.o
CXXFLAGS ?=  -I./lib/ -I./src/ -Wall -Wextra -Werror -pedantic -std=c++11 -stdlib=libc++ -O3 -ggdb

all: fast_cluster

src/fast_cluster.o: src/fast_cluster.cc src/hasher.h
src/hasher.o: src/hasher.cc lib/city.h
lib/city.o: lib/city.cc

fast_cluster: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm src/*.o lib/*.o

dep:
	@$(CXX) $(CXXFLAGS) -MM src/*.cc lib/*.cc

.PHONY: dep clean all

OBJS = src/hasher.o src/fast_cluster.o src/hasher.o src/worker.o lib/city.o
CXXFLAGS ?=  -I./lib/ -I./src/ -Wall -Wextra -Werror -pedantic -std=c++11 -stdlib=libc++ -O3 -ggdb

all: fast_cluster

fast_cluster: $(OBJS)

src/fast_cluster.o: src/fast_cluster.cc src/hasher.h
src/hasher.o: src/hasher.cc lib/city.h
src/worker.o: src/worker.cc
lib/city.o: lib/city.cc


clean:
	rm src/*.o lib/*.o

dep:
	@$(CXX) $(CXXFLAGS) -MM src/*.cc lib/*.cc

.PHONY: dep clean

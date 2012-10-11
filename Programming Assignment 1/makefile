OBJ= timer.o k_ary_heap.o avl_tree.o main.o
HDR= sorts.hpp

%.o : %.cpp
	g++ -c $< -I include/

all: $(OBJ)
	g++ $(OBJ) -o main

clean:
	@rm -rf $(OBJ) main
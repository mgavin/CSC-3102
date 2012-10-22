OBJ= timer.o main.o
HDR= sorts.hpp k_ary_heap.hpp avl_tree.hpp

%.o : %.cpp
	g++ -c $< -I include/

all: $(OBJ)
	g++ $(OBJ) -o main

clean:
	@rm -rf $(OBJ) main
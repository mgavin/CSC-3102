OBJ= timer.o main.o
HDR= sorts.hpp k_ary_heap.hpp avl_tree.hpp

%.o : %.cpp
	g++ -c $< -I include/

all: $(OBJ)
	g++ $(OBJ) -o main

main1: timer.o main1.o
	g++ timer.o main1.o -o main1

main3: timer.o main3.o
	g++ timer.o main3.o -o main3

main2: timer.o main2.o
	g++ timer.o main2.o -o main2

clean:
	@rm -rf $(OBJ) main main1 main2 main3 main1.o main2.o main3.o
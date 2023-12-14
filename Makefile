all: data1 data2 pre_vec vecmult pre_vmm vmm vmm2 vmm3
data1: src/data_generation.cpp
	g++ src/data_generation.cpp -o bin/data1
data2: src/data_generation_2.cpp
	g++ src/data_generation_2.cpp -o bin/data2
pre_vec: src/pre_vec.cpp
	g++ -mavx2 src/pre_vec.cpp -o bin/pre_vec
vecmult: src/vecmult.cpp
	g++ -mavx2 src/vecmult.cpp -o bin/vecmult
pre_vmm: src/pre_vmm.cpp
	g++ -mavx2 src/pre_vmm.cpp -o bin/pre_vmm
vmm: src/vmm.cpp
	g++ -mavx2 src/vmm.cpp -o bin/vmm
vmm2: src/vmm2.cpp
	g++ -mavx2 src/vmm2.cpp -o bin/vmm2
vmm3: src/vmm3.cpp
	g++ -mavx2 src/vmm3.cpp -o bin/vmm3

new_data_1:
	./bin/data1
new_data_2:
	./bin/data2
clean:
	rm -f bin/* data/*.in data/*.out

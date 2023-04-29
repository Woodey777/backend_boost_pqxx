STD = --std=c++20

all: build run_backend

build:
	g++ --std=c++20 main.cpp server/*.cpp entity/*.cpp action/*.cpp database/*.cpp \
	-I/opt/local/include/ -L/opt/local/lib/ -lpqxx \
	-I/opt/local/include/postgresql13 -L/opt/local/lib/postgresql13 -lpq -o backend

run_backend:
	./backend

clean:
	rm -rf backend

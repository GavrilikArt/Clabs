all: clean buildMain buildTest runTest

buildMain:
	mkdir -p target/main
	g++ -o target/main/dormitory source/Dormitory.cpp source/main.cpp

buildTest:
	g++ -ftest-coverage -fprofile-arcs -O0 -o source/test source/mainTest.cpp source/Dormitory.cpp

runTest:
	./source/test
	gcov -abcfu Dormitory.cpp

clean:
	rm -rf target

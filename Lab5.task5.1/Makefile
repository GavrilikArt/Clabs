all: clean buildMain buildTest runTest

buildMain:
	mkdir -p target/main
	g++ -o target/main/operations source/main.cpp -lm

buildTest:
	mkdir -p target/test
	g++ -o target/test/LongNumTest -Dmain=_main source/main.cpp source/mainTest.cpp -lm
runTest:
	./target/test/LongNumTest

clean:
	rm -rf target
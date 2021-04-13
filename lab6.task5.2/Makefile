all: clean buildMain buildTest runTest

buildMain:
	mkdir -p target/main
	g++ -o target/main/binaryTree source/main.cpp -lm

buildTest:
	mkdir -p target/test
	g++ -o target/test/binaryTree_test -Dmain=_main source/main.cpp source/mainTest.cpp -lm

runTest:
	./target/test/Binarytree_test

clean:
	rm -rf target

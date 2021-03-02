all: clean buildMain buildTest runTest

buildMain:
	mkdir -p target/main
	gcc -o target/main/tailor source/main.c

buildTest:
	mkdir -p target/test
	gcc -o target/test/Test -Dmain=_main source/main.c source/mainTest.c

runTest:
	./target/test/Test
clean:
	rm -rf target
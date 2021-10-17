.PHONY: build test

build-test:
	cd test && idf.py build

test: build-test
	./test/build/enginooze_test.elf
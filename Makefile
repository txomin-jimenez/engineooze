.PHONY: build flash test

build:
	idf.py build

flash:
	idf.py flash monitor

build-test:
	cd test && idf.py build

test: build-test
	./test/build/enginooze_test.elf
BUILD_DIR=build
LIBS=$(wildcard lib/*/*.cpp)
TESTS=$(wildcard test/*/*.cpp)


all: lint build test

lint: ${LIBS}
	cpplint ./lib/*/*
	cpplint ./test/*/*

build: ${LIBS}
	mkdir -p ${BUILD_DIR}; \
	cd build; \
	cmake ..; \
	make -j 2

test: ${LIBS}
	${BUILD_DIR}/test/mathTest


clean:
	- rm -rf ${BUILD_DIR}

.PHONY:
	all lint build test clean

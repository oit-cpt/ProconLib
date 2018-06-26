BUILD_DIR=build
LIBS=$(wildcard lib/*/*.cpp)
LIBS+=$(wildcard lib/*/*.h)
TESTS=$(wildcard test/*/*.cpp)


all: lint build test

lint: ${LIBS}
	cpplint ./lib/*/*
	cpplint ./test/*/*

build: ${LIBS} ${TESTS}
	mkdir -p ${BUILD_DIR}; \
	cd build; \
	cmake ..; \
	make -j 2

test: build
	${BUILD_DIR}/test/runTest

format:
	clang-format -i $(FILE)

clean:
	- rm -rf ${BUILD_DIR}

.PHONY:
	all lint build test clean

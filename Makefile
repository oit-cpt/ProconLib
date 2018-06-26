BUILD_DIR=build
LIBS=$(wildcard lib/*/*.cpp)
LIBS+=$(wildcard lib/*/*.h)
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

test: ${BUILD_DIR}
	${BUILD_DIR}/test/mathTest

format:
	clang-format -i $(FILE)

clean:
	- rm -rf ${BUILD_DIR}

.PHONY:
	all lint build test clean

BUILD_DIR = build
VIEW_DIR = View
SOURCES = $(shell find $(SRC_DIRS) -name '*.cpp' -o -name '*.h')
CFLAGS=-Wall -Werror -Wextra
all: build

build:
	cd View && qmake 3dViewer.pro && make && make clean && ./3dViewer $(CFLAGS)

install: build
	@echo "Creating build directory..."
	mkdir -p $(BUILD_DIR) 
	mv $(VIEW_DIR)/3dViewer $(BUILD_DIR)/

uninstall:
	@echo "Removing the executable..."
	rm -rf $(BUILD_DIR)

clean:
	rm -rf $(VIEW_DIR)/Makefile $(VIEW_DIR)/.qmake.stash Test

dist: clean uninstall
	mkdir ../dist
	cp -r ../src ../dist
	cp ../README.md ../dist
	cd ../dist && tar -czvf dist.tar.gz ./src
	rm -rf ../dist/src

dvi:
	open readme.html

style:
	clang-format -n $(SOURCES)
	clang-format -i $(SOURCES)

test:
	rm -rf Test
	gcc test.cpp -lgtest -lrt -lpthread -o Test -lm -lsubunit -lstdc++ -std=c++17
	./Test

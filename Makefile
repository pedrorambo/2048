build: src/* src/include/*
	rm -rf build
	mkdir -p build

	gcc -Wall -Wextra -Wpedantic \
	-o build/main \
	src/main.c src/prints.c src/utils.c src/tableLogic.c src/tablePlays.c src/view.c \
	-lncurses \
	-I src/include

clean:
	rm -rf build
build: src/* src/include/*
	rm -rf build
	mkdir -p build

	gcc -Wall -Wextra -Wpedantic \
	-o build/main \
	\
	src/main.c \
	src/prints.c \
	src/utils.c \
	src/tableLogic.c \
	src/core.c \
	src/view.c \
	src/tableView.c \
	src/ranking.c \
	src/promptView.c \
	src/promptRankingView.c \
	src/rankingView.c \
	src/logFile.c \
	\
	-lncurses \
	-I src/include

clean:
	rm -rf build
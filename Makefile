build: src/* src/include/*
	rm -rf build
	mkdir -p build

	gcc -static -Wall -Wextra -Wpedantic \
	-o build/2048 \
	\
	src/main.c \
	src/prints.c \
	src/utils.c \
	src/tableLogic.c \
	src/core.c \
	src/view.c \
	src/tableView.c \
	src/ranking.c \
	src/promptRankingView.c \
	src/rankingView.c \
	src/logFile.c \
	src/saveGame.c \
	src/promptSaveView.c \
	src/mainMenu.c \
	src/promptExitView.c \
	src/promptNewView.c \
	src/promptLoadView.c \
	src/inputManager.c \
	\
	-lncurses -l:libncursesw.a -l:libtinfo.a \
	-I src/include

clean:
	rm -rf build
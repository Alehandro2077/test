NAME = app

all: compile

compile:
	gcc main.c -o ${NAME} -L. -lmy

uninstall: 
	rm -rf ${NAME}
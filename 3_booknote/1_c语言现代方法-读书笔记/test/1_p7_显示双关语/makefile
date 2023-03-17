CC = gcc
TARGET = main
SRC = $(wildcard *.c)

OBJ = $(patsubst %.c, %.o, $(SRC)) # 将src里面的东西提取出来变成.o文件
#OBJ = $(wildcard *.o)

$(TARGET): $(SRC)
	$(CC) -c $^
	$(CC) $(OBJ) -o $@

.PHONY: clean
clean: 
	rm $(OBJ) *.exe

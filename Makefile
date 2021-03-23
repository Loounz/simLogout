INCFLAG = -I ./inc/
TARGET = test
CC	= gcc

SOURCE = test.c src/MyLog.c

$(TARGET):
	$(CC) -g $(SOURCE) -o $@

CC = gcc
CFLAGS = -Wall -Wextra -O2 -static

all: antiscreensaver.exe rtime.exe

%.exe: %.c
	$(CC) $(CFLAGS) $< -o $@
	strip $@

CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb
TARGET = ft_ls
SRC = *.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)


re: clean all

.PHONY: all clean

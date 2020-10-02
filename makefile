CFLAGS := -pthread
LDFLAGS := -lpthread

SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)
TARGET := domaincheck

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

%.o: %.c
	$(CC) -c $^ $(CFLAGS)

clean:
	@rm -rf $(OBJ)

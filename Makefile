# All copyright and related rights waived via CC0.

SRC_DIR = ./src/
TARGET = target
SRCS = target.c crypto.c
SRC = $(addprefix $(SRC_DIR), $(SRCS))
ENC = encrypt
ENC_SRCS = encrypt.c crypto.c
ENC_SRC = $(addprefix $(SRC_DIR), $(ENC_SRCS))
OBJS = $(SRC:.c=.o)
ENC_OBJS = $(ENC_SRC:.c=.o)

CFLAGS = --std=gnu99 -Wall

all: encrypt target

target: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(CFLAGS) $(LDFLAGS)

encrypt: $(ENC_OBJS)
	$(CC) -o $(ENC) $(ENC_OBJS) $(CFLAGS) $(LDFLAGS)
	@./encrypt

clean:
	@rm $(ENC) $(TARGET) src/*.o src/const.h

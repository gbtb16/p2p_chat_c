#
#  Makefile
#  p2p_chat_c
#
#  Created by Gabriel Barbosa on 22/01/25.
#

CC := clang
CFLAGS := -Wall -Wextra -Wpedantic -Wconversion -O2 -g
LDFLAGS :=

SRC := src/main.c
BUILD_DIR := builds/bin
TARGET := $(BUILD_DIR)/p2p_chat_c

# Cria o diretório de builds caso não exista
$(shell mkdir -p $(BUILD_DIR))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -rf $(TARGET)

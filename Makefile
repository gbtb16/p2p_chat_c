#
#  Makefile
#  p2p_chat_c
#
#  Created by Gabriel Barbosa on 22/01/25.
#

CC = gcc
CFLAGS = -Wall -Iinclude
SRCDIR = src
OBJDIR = build

OBJS = $(OBJDIR)/main.o $(OBJDIR)/localization.o $(OBJDIR)/operation_mode.o $(OBJDIR)/menu.o $(OBJDIR)/utils.o
TARGET = $(OBJDIR)/p2p_chat_c

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

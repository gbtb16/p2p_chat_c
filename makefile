CC = gcc
CFLAGS = -Wall -Iinclude
SRCDIR = src
OBJDIR = build

OBJS = $(OBJDIR)/main.o $(OBJDIR)/localization.o
TARGET = $(OBJDIR)/p2p_chat_c

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

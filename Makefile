CC = gcc

CFLAGS  = -g -Wall

# the build target executable:
TARGET = main

all: $(TARGET)

$(TARGET): $(TARGET).c
  $(CC) $(CFLAGS) -o $(TARGET).cpp

clean:
  $(RM) $(TARGET)
# get arch name
ARCH = $(shell uname -m)
TARGET = example
OBJS = example.o test_main.o 
DEPS = test.h
CFLAGS += -g -O2 #-DNDEBUG

all: $(TARGET)
	
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

clean:
	rm $(TARGET) $(OBJS)

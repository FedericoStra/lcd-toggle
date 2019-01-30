CFLAGS += -std=c17 -Wall -O2

.PHONY: all install clean

all: lcd-toggle

install:
	install -m 4755 lcd-toggle /usr/local/bin/

clean:
	$(RM) lcd-toggle

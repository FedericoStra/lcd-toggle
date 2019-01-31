CFLAGS += -std=c17 -Wall -O2

.PHONY: all install clean

all: lcd-toggle

install: all
	install -m 4755 -t /usr/local/bin lcd-toggle
	@# The bash and python scripts do no work as setuid programs
	@# install -m 4755 -t /usr/local/bin lcd-toggle bl-tgl.sh bl-tgl.py

clean:
	$(RM) lcd-toggle

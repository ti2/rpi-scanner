OBJS = main.o motor.o laser.o
BIN = scanner.out

CFLAGS += -Wall -g
LDFLAGS += -lm -lwiringPi
INCLUDES += -I.

all: $(BIN)

%.o: %.c
	@rm -f $@ 
	$(CC) $(CFLAGS) $(INCLUDES) -g -c $< -o $@ 

%.out: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS) 

clean:
	for i in $(OBJS); do (if test -e "$$i"; then (rm $$i); fi); done
	@rm -f $(BIN)


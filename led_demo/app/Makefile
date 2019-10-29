Exec :=led_test
Obj :=LED_test.c
CC :=arm-linux-gcc

$(Exec) :$(Obj)
	$(CC) -o $@ $(Obj) $(LDLIBS$(LDLIBS-$(@)))
	
clean:
	rm -vf $(Exec) *.elf *.o

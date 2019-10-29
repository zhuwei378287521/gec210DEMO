#
#  General Makefile

Exec := led_test
Obj := led_test.c
CC := arm-linux-gcc   #此编译器需根据自己的内核编译器来更改

$(Exec) : $(Obj)
	$(CC) -o $@ $(Obj) $(LDLIBS$(LDLIBS-$(@)))

clean:
	rm -vf $(Exec) *.elf *.o

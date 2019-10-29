ifneq ($(KERNELRELEASE),)
	obj-m :=led.o
else
	module-objs :=led.o
	KERNELDIR :=/home/zjw/yueqian/linux-2.6.35.7-gec-v3.0.3/
	PWD :=$(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif

clean:
	$(RM)  *.ko *.mod.c *.mod.o *.o *.order *.symvers *.cmd

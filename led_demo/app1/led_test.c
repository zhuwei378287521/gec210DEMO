#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/input.h>

#define IOCTL_LED_ON 0
#define IOCTL_LED_OFF 1

void usage(char *exename)//使用说明
{
	printf("Usage:\n");
	printf("   %s <led_no> <on/off>\n",exename);
	printf("   led_no=1,2\n");
} 

int main(int argc, char **argv)
{
	unsigned int led_no;
	int fd = -1;
	
	if(argc != 3)
	{
		goto err;
	}

	fd = open("/dev/leds",O_RDWR);//打开文件
	if(fd < 0)
	{
		printf("Can't open /dev/leds\n");
		return -1;
	}
	
	led_no = strtoul(argv[1],0,0) - 1;//获取LED号
	if (led_no > 3)
		goto err;
	
	if(!strcmp(argv[2],"on"))
	{		
		ioctl(fd,IOCTL_LED_ON,led_no);	//点亮LED灯
	}
	else if(!strcmp(argv[2],"off"))
	{	
		ioctl(fd,IOCTL_LED_OFF,led_no);//熄灭LED灯
	}
	else
	{
		goto err;
	}
	
	close(fd);
	return 0;

err:
	if(fd > 0)
		close(fd);
	usage(argv[0]);
	return -1;
}

// gcc -o irm1 irm1.c -l bcm2835 -l lirc_client
// sudo ./irm1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <bcm2835.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <lirc/lirc_client.h>

// LED3 je na DVK512 pločici na P28 što je pin 20 na BCM-u,
// ako se koristi protobord može se
// koristiti isti ovaj pin ili neki drugi
	#define PIN 20

int main(int argc, char **argv)
{
	struct lirc_config *config;
	char *code;
	//startuj lirc
	
	if(lirc_init("lirc",1)==-1)
		return 1;
 
	if(wiringPiSetup() == -1)
	exit(1);
	
	pinMode(27,OUTPUT);
	digitalWrite(27,HIGH);
	
	if(softPwmCreate(28,0,100) != 0)
	exit(2);
		
	int i = 0;
	int taster_pritisnut =1;
	
	// Setuj PIN kao izlazni
	
	//bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);
		//procitaj /etc/lirc/lirc/lircrc/lircd.conf
	
	if(lirc_readconfig(NULL, &config,NULL)==0)
		{
		//radimo dok je LIRC soket otvoren 0=otvoren -1=zatvoren

			while (lirc_nextcode(&code)==0)
			{
				// if code=NULL ništa nije primljeno-preskoči
				if(code==NULL) continue; 
				{
					//bcm2835_delay(400);
					if (strstr(code,"KEY_VOLUMEUP") && taster_pritisnut)
					{
						taster_pritisnut = 0;
						printf("KEY0\n");
						i += 20;
						if(i > 100) i = 0;
						printf("i = %d\n",i);
						softPwmWrite(28,i);
						// iskljuci
						//bcm2835_gpio_write(PIN, LOW);
						//bcm2835_delay(500);
					}
					
					if (strstr(code,"KEY_VOLUMEDOWN")&& taster_pritisnut)
					{
						taster_pritisnut = 0;
						printf("KEY0\n");
						i -= 20;
						if(i < 0) i = 100;
						printf("i = %d\n",i);
						softPwmWrite(28,i);
						
						// ukljuci
						//bcm2835_gpio_write(PIN, HIGH);
						//bcm2835_delay(500);
					}
					if(!strstr(code,"KEY_VOLUMEDOWN") ||!strstr(code,"KEY_VOLUMEUP")) {taster_pritisnut = 1;}
					
				}
				free(code);
			}
			lirc_freeconfig(config);
		}
		lirc_deinit();
		//bcm2835_close();
	return 0;
	}

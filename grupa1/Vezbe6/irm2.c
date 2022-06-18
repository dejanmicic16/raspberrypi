
// gcc -o irm1 irm1.c -l bcm2835 -l lirc_client
// sudo ./irm1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bcm2835.h>
#include <lirc/lirc_client.h>

// LED3 je na DVK512 pločici na P28 što je pin 20 na BCM-u,
// ako se koristi protobord može se
// koristiti isti ovaj pin ili neki drugi
	#define PIN 20

int main(int argc, char **argv)
{
	struct lirc_config *config;
	char *code;
	
	char rec1[25];
	char rec2[25];
	char rec3[15];
	char rec4[15];
		//startuj lirc
	
	if(lirc_init("lirc",1)==-1)
		return 1;
 
	if (!bcm2835_init())
		return 2;
	
	// Setuj PIN kao izlazni
	
	bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);
		//procitaj /etc/lirc/lirc/lircrc/lircd.conf
	
	if(lirc_readconfig(NULL, &config,NULL)==0)
		{

		//radimo dok je LIRC soket otvoren 0=otvoren -1=zatvoren

			while (lirc_nextcode(&code)==0)
			{
				//sprintf(code,"%s\n",code);
				//printf("0x");
				//printf("%s\n",code + 10);
				//printf("%s\n",code + 20);
				
				printf("%s\n",code);
				
				strcpy(rec4," 01 ");
				sscanf(code,"%s 01 %s remote_default",rec1,rec2);
				printf("0x");
				printf("%s",rec1);
				printf("   %s\n",rec2);
				// if code=NULL ništa nije primljeno-preskoči
				/*if(code==NULL) continue; 
				{
					printf("%d",lirc_readconfig);
					bcm2835_delay(400);
					if (strstr(code,"KEY_0"))
					{
						printf("KEY0\n");
						// iskljuci
						bcm2835_gpio_write(PIN, LOW);
						bcm2835_delay(500);
					}
					
					else if (strstr(code,"KEY_1"))
					{
						printf("KEY1\n");
						// ukljuci
						bcm2835_gpio_write(PIN, HIGH);
						bcm2835_delay(500);
					}
				}*/
				
				
				free(code);
				//free(rec1);
				//free(rec2);
			}
			lirc_freeconfig(config);
		}
		lirc_deinit();
		bcm2835_close();
	return 0;
	}

#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

int main(){
	int taster_pritisnut = 0,i=0;
	int r_value1;
	int r_value2;
	if(wiringPiSetup()== -1)
		exit(1);
	pinMode(21,INPUT);
	pinMode(22,INPUT);
	pinMode(25,OUTPUT); //dioda koja se gasi
	digitalWrite(25,HIGH);
	if(softPwmCreate(28,0,100)!=0)
		exit(2);
	i=0;
	taster_pritisnut = 0;
	while(1)
	{
		r_value1 = digitalRead(21);
		digitalWrite(25,r_value1);
		if(!r_value1 && !taster_pritisnut)
		{
			taster_pritisnut = 1;
			i+=20;
			if(i > 100)
				i = 0;
			printf("i = %d\n",i);
			fflush(stdout);
			softPwmWrite(28,i);
		}

		r_value2 = digitalRead(22);
		digitalWrite(25,r_value2);
		if(!r_value2 && !taster_pritisnut)
		{
			taster_pritisnut = 1;
			i-=20;
			if(i < 0)
				i = 100;
			printf("i = %d\n",i);
			fflush(stdout);
			softPwmWrite(28,i);
		}
	
	if (r_value1 && r_value2)
		taster_pritisnut = 0;
	}
	return 0;
}

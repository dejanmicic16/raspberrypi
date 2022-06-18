// lcd1602.c
// kompajlirati sa -lwiringPi -lwiringPiDev
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <lcd.h>
#include <stdlib.h>
// dodela vrednosti za konkretne pinove
// prema gornjoj tabeli i semi DVK512
const int RS = 3;
const int EN = 14;
const int D0 = 4;
const int D1 = 12;
const int D2 = 13;
const int D3 = 6;

int pos1 = 0, pos2 = 0;

int main(){
	int lcd_h;
	
	if (wiringPiSetup() < 0)
	{
	 fprintf (stderr, "Greška pri inicijalizaciji:%s\n", strerror (errno)) ;
	 return 1 ;
	}
		int taster_pritisnut = 0,i=0;
		lcd_h = lcdInit(2, 16, 4, RS, EN, D0, D1, D2, D3, D0, D1, D2, D3);
		lcdPosition(lcd_h, 0,0);
		lcdPrintf(lcd_h,"Displej sa 16 ch");
		//lcdPosition(lcd_h, 0,1);
		lcdPrintf(lcd_h, "u 2 reda");
		delay(2000);
		lcdClear(lcd_h);
		
		lcdCursor(lcd_h,1);
		lcdCursorBlink(lcd_h,1);
		
		pinMode(21,INPUT);
		pinMode(22,INPUT);
		pinMode(23,INPUT);
		pinMode(24,INPUT);
		
		if(softPwmCreate(28,0,100)!=0)
		exit(2);
		
		int r_value1;
		int r_value2;
		int r_value3;
		int r_value4;
		
		
		
		while(1){
			
			r_value1 = digitalRead(21);
			r_value2 = digitalRead(22);
			r_value3 = digitalRead(23);
			r_value4 = digitalRead(24);
			
			if(!r_value1 && !taster_pritisnut)
			{
				taster_pritisnut = 1;
				pos1++;
				if(pos1 > 15)
					{
						pos1 = 0;
					}
				printf("Pritisnut taster 1\n");
				
			}
			if(!r_value2 && !taster_pritisnut)
			{
				taster_pritisnut = 1;
				pos1--;
				if(pos1 < 0)
				{
					pos1 = 15;
				}
				printf("Pritisnut taster 2\n");
				
			}
			if(!r_value3 && !taster_pritisnut)
			{
				taster_pritisnut = 1;
				pos2++;
				if(pos2 > 1)
				{
					pos2 = 0;
				}
				printf("Pritisnut taster 3\n");
				
			}
			if(!r_value4 && !taster_pritisnut)
			{
				taster_pritisnut = 1;
				pos2--;
				if(pos2 < 0)
				{
					pos2 = 1;
				}
				printf("Pritisnut taster 4\n");
				
			}
			if (r_value1 && r_value2 && r_value3 && r_value4)
				{taster_pritisnut = 0;}
				
			lcdPosition(lcd_h, pos1,pos2);
			
			//printf("\n\nPočetna Temp = %.3f \xC2\xB0 C\n", temperatura());
			//lcdClear(lcd_h);
			//lcdPrintf(lcd_h,"%lf C",temperatura());
			//delay(2000);
			
		}
		}

// primer rada sa PCF8563 koji ispisuje tekuce vreme
// u terminalu svakih 5 sekundi

#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>
#include <unistd.h>

#define changeHexToInt(hex) ((((hex)>>4) *10 ) +((hex)%16) )

#define changeIntToHex(hex) ((hex % 10) & ((hex / 10 )<< 4))

//adrese registara
#define SEK 0x02
#define MIN1 0x03
#define SAT 0x04
#define DAN 0x05
#define MES 0x07
#define GOD 0x08

const int RS = 3;
const int EN = 14;
const int D0 = 4;
const int D1 = 12;
const int D2 = 13;
const int D3 = 6;

const char PCF8591 = 0x51;
int fd, adcVal;

unsigned char WriteBuf[2];
unsigned char ReadBuf;
int g8563_Store[3];

// sec,min,sat
unsigned char init8563_Store[6]={0x02,0x03,0x04,0x05,0x07,0x08};

/*void P8563_settime()
{
	WriteBuf[0] = SEK;
	WriteBuf[1] = g8563_Store[0];
	bcm2835_i2c_write(WriteBuf,2);
	
	WriteBuf[0] = MIN1;
	WriteBuf[1] = g8563_Store[1];
	bcm2835_i2c_write(WriteBuf,2);
	
	WriteBuf[0] = SAT;
	WriteBuf[1] = g8563_Store[2];
	bcm2835_i2c_write(WriteBuf,2);
	
	WriteBuf[0] = DAN;
	WriteBuf[1] = g8563_Store[3];
	bcm2835_i2c_write(WriteBuf,2);
	
	WriteBuf[0] = MES;
	WriteBuf[1] = g8563_Store[5];
	bcm2835_i2c_write(WriteBuf,2);
	
	WriteBuf[0] = GOD;
	WriteBuf[1] = g8563_Store[6];
	bcm2835_i2c_write(WriteBuf,2);
	
}

void P8563_init()
{
	unsigned char i;
	for(i=0;i<=6;i++)
		g8563_Store[i]=init8563_Store[i];
		
	P8563_settime();
	printf("Postavi početno tekuće vreme\n");
	//inicijalizacija RTC-a
	
	WriteBuf[0] = 0x0;
	WriteBuf[1] = 0x00; //normalni rezim rada
	bcm2835_i2c_write(WriteBuf,2);
}
*/

/*int inttohex(val)
{
		int pom = val / 10;
		int res=1;
		for(int i = 0; i < 4; i++)
			{
					if(val % 2 == 0)
						{
							res << i;
						}
			}
		res << 4;
		int res2 = 1;
		int pom2 = val % 10;
		for(int i = 0; i < 4; i++)
			{
					if(val % 2 == 0)
						{
							res2 << i;
						}
			}
		return re2 & res;
}
*/
void P8563_Readtime()
{
	int time[7];
	
	time[0] = wiringPiI2CReadReg8(fd,SEK);
	time[1] = wiringPiI2CReadReg8(fd,MIN1);
	time[2] = wiringPiI2CReadReg8(fd,SAT);
	time[3] = wiringPiI2CReadReg8(fd,DAN);
	time[5] = wiringPiI2CReadReg8(fd,MES);
	time[6] = wiringPiI2CReadReg8(fd,GOD);
		
		
	
	g8563_Store[0] = time[0] & 0x7f;
	g8563_Store[1] = time[1] & 0x7f;
	g8563_Store[2] = time[2] & 0x3f;
	g8563_Store[3] = time[3] & 0x3f;
	g8563_Store[5] = time[5] & 0x1f;
	g8563_Store[6] = time[6] & 0xff;
	//printf("%d\n",time[6]);

	
	
	g8563_Store[0] = changeHexToInt(g8563_Store[0]);
	g8563_Store[1] = changeHexToInt(g8563_Store[1]);
	g8563_Store[2] = changeHexToInt(g8563_Store[2]);
	g8563_Store[3] = changeHexToInt(g8563_Store[3]);
	g8563_Store[5] = changeHexToInt(g8563_Store[5]);
	g8563_Store[6] = changeHexToInt(g8563_Store[6]);
	//printf("%c",time[6]);
	
}

int main(int argc, char **argv)
{
		int lcd_h;

	if(wiringPiSetup() == -1)
		exit(1);
	
	fd = wiringPiI2CSetup(PCF8591);
	

	printf("start..........\n");
	//P8563_init() ;
	
	lcd_h = lcdInit(2, 16, 4, RS, EN, D0, D1, D2, D3, D0, D1, D2, D3);
	lcdPosition(lcd_h, 0,0);
	
	int r_value1;
	int r_value2;
	int r_value3;
	int r_value4;
	
	int pos = 6;
	
	int taster_pritisnut = 0;
	pinMode(21,INPUT);
	pinMode(22,INPUT);
	
	while(1)
	{
		
		P8563_Readtime();
		lcdClear(lcd_h);
		r_value1 = digitalRead(21);
		r_value2 = digitalRead(22);
		
		if(!r_value1 && !taster_pritisnut)
		{
			taster_pritisnut = 1;
			pos--;
			if(pos <0)
				{
					pos = 6;
				}
			printf("Pritisnut taster 1 i na pozici je : %d \n",pos);
			
		}
		if(!r_value2 && !taster_pritisnut)
		{
			taster_pritisnut = 1;
			/*pos1--;
			if(pos1 < 0)
			{
				pos1 = 15;
			}*/
			printf("%d\n",g8563_Store[pos]);
			int pom = g8563_Store[pos] ;
			pom++;
			//g8563_Store[pos] = pom;
			//printf("%d\n",g8563_Store[pos]);
			pom = changeIntToHex(pom);
			
			wiringPiI2CWriteReg8(fd,init8563_Store[pos],pom);
			printf("Pritisnut taster 2 i vrednost je : %0x\n",g8563_Store[pos]);
			delay(100);
			
		}
		if (r_value1 && r_value2 )
				{taster_pritisnut = 0;}
		
		//while(1);
		printf("Godina:%d Mesec:%d Dan :%d Sati:%d Minuti:%d Sekunde:%d\n",g8563_Store[6],g8563_Store[5],g8563_Store[3],g8563_Store[2], g8563_Store[1], g8563_Store[0]);
		lcdPosition(lcd_h, 0,0);
		lcdPrintf(lcd_h,"%d | %d | %d |",g8563_Store[6],g8563_Store[5],g8563_Store[3]);
		lcdPosition(lcd_h, 0,1);
		lcdPrintf(lcd_h,"%d | %d | %d |",g8563_Store[2],g8563_Store[1],g8563_Store[0]);
		
		
		//bcm2835_delay(5000);
		delay(1000);
	}
	
	
	return 0;
}

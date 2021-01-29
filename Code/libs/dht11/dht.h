
#ifndef DHT_H_
#define DHT_H_

#include <stdint.h>

#define MAX_TIMINGS	85
#define DHT_PIN		6	/* GPIO-22 */
 
int data[5] = { 0, 0, 0, 0, 0 };
int state = 0;
void read_dht_data()
{
	uint8_t laststate	= 1;
	uint8_t counter		= 0;
	uint8_t j			= 0, i;
 
	data[0] = data[1] = data[2] = data[3] = data[4] = 0;
 
	/* pull pin down for 18 milliseconds */
	gpio_mode( DHT_PIN, 1);
	gpio_write( DHT_PIN,0);
	delay_ms( 18 );
    
 
	/* prepare to read the pin */
	gpio_mode( DHT_PIN, 0);
 
	/* detect change and read data */
	for ( i = 0; i < MAX_TIMINGS; i++ )
	{
		counter = 0;
		while ( gpio_read( DHT_PIN ) == laststate )
		{
			counter++;
			delay_us(2);
			if ( counter == 255 )
			{
				break;
			}
		}
		laststate = gpio_read( DHT_PIN );
 
		if ( counter == 255 )
			break;
 
		/* ignore first 3 transitions */
		if ( (i >= 4) && (i % 2 == 0) )
		{
			/* shove each bit into the storage bytes */
			data[j / 8] <<= 1;
			if ( counter > 16 )
				data[j / 8] |= 1;
			j++;
		}
	}
 
	/*
	 * check we read 40 bits (8bit x 5 ) + verify checksum in the last byte
	 * print it out if data is good
	 */
	if ( (j >= 40) &&
	     (data[4] == ( (data[0] + data[1] + data[2] + data[3]) & 0xFF) ) )
	{
		float h = (float)((data[0] << 8) + data[1]) / 10;
		if ( h > 100 )
		{
			h = data[0];	// for DHT11
		}
		float c = (float)(((data[2] & 0x7F) << 8) + data[3]) / 10;
		if ( c > 125 )
		{
			c = data[2];	// for DHT11
		}
		if ( data[2] & 0x80 )
		{
			c = -c;
		}
        char snum[20];
        float f = c * 1.8f + 32;
		state = !state;
        if(state)
            sprintf(snum,"Humidity= %d%% Temperature= %dF",(int)h, (int)f);
        else
            sprintf(snum,"Humidity= %d%% Temperature= %dC",(int)h, (int)c);
        lcd_print(snum);

	}else  {
		lcd_print( "Invalid");
	}
}

#endif

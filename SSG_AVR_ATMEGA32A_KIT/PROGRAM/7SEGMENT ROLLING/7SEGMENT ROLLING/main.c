#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#define LED_direction DDRC		/* define LED Direction */
#define LED_PORT PORTC			/* define LED PORT */

int main(void)
{
	LED_direction |= 0x0f;		/* define LED port direction is output */
	LED_PORT = 0x0f;
	char array[]={0,1,2,3,4,5,6,7,8,9};
	/* write BCD value for CA display from 0 to 9 */
	while(1)
	{
		for(int i=0;i<10;i++)
		{
			LED_PORT = array[i];/* write data on to the LED port */
			_delay_ms(1000); /* wait for 1 second */
		}
	}
}
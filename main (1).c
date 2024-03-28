#include <kipr/wombat.h>

void squareUp(int speed);

int main()
{

    squareUp(20);
    
    return 0;
}

void squareUp(int speed)
{
		int threshold = 3600;

		if ( analog(0) < threshold || analog(1) >= threshold)
	{
	while (analog(0) < threshold)
		{
		motor(0, speed);
		motor(3, -1*speed);
		}
        }
	else if ( analog(1) < threshold || analog(0) >= threshold)
	{
		while (analog(1) < threshold)
	{
		motor(0,-1* speed);
		motor(3, speed);
	}
  	  }
	else if (analog(0) < threshold && analog(1) < threshold)
	{
		motor(0, speed);
		motor(3, speed);
	}
}
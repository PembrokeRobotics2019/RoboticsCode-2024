#include <kipr/wombat.h>
////////Wheels/////////
 //left wheel = 3//
 //Right wheel = 0//
////////TurningRadius/////////
      //90degrees=80//
////////Servos/////////
       //claw//
    //closed=1127//
     //open=730//
        //arm//
   //level=1213//
     //up=300//

                                    /////////////////////////////////////////////
// declare and  initialize variables
int left = -100;
int right= 100;
int closed = 1127;
int open = 730;
int level = 1216;
int up = 300;

                                    /////////////////////////////////////////////
// declare functions
void turn(int direction, int time);
void forward(int speed, int time);
void wait(int time);
void servo(int servo, int position);
void pickUpGuy();
void pickUpGuy2();
void pickUpGuy3();
void putDownGuy();
void lineFollow(int ticks);
void squareUp(int speed);
void startUp();
void stopAtLine(int speed);
void clear();


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// main function here
int main()
{
    enable_servos();
    servo(0, up);
    servo(3, closed);    
	cmpc(0);
    cmpc(3);
    
////////////////////////
    
   	forward(80, 1500);
    wait(500);
    
    turn(right, 850);
    wait(500);
    
    forward(80, 1000);
    wait(500);
    
    pickUpGuy2();
    wait(500);
    
    forward(-100, 1500);
    wait(500);
    
    turn(left, 790);
    wait(500);
    
    stopAtLine(90);
    wait(500);
    
    // line following
    if (analog(1) > 2500)
    {
    	while (analog(1) > 2500)
        {
            motor(0, 20);
            motor(3, 0);
            msleep(10);
        }
    }
    wait(500);
        
    forward(90, 4000);
    wait(500);
    
    turn(right, 800);
    wait(500);
    
    forward(80, 2500);
    wait(500);
    
   	servo(0, level);
    servo(3, open);
    wait(500);
    
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// simple turning function with two parameters, direction of turn and time
void turn(int direction, int time)
{
    motor(3 , direction);
    motor(0, -(direction));
  	  msleep(time);
    
    wait(500);
}

//////////////////////////////////////////////////////////////
// simple forward function with 2 parameters, speed and time
void forward(int speed, int time)
{
    motor(3, speed);
    motor(0, speed);
    msleep(time);
    
    wait(500);

}

//////////////////////////////////////////////////////////////
// this just makes our main function easier to read
void wait(int time)
{
    motor(3, 0);
    motor(0, 0);
    msleep(time);
}

//////////////////////////////////////////////////////////////
// sets a servo at a position and pauses the robot for a second so its not too jerky
void servo(int servo, int position)
{
	set_servo_position(servo, position);
    wait(500);
}

//////////////////////////////////////////////////////////////
// first draft of pickupguy function, doesn't help that the forward function is a comment
void pickUpGuy()
{
    servo(0, level);    //setup
    servo(3, open);

   // forward(50, 500);     //action
    servo(3, closed);
    servo(0, up);
}
    
//////////////////////////////////////////////////////////////
// second draft of pickup guy function, used in code
void pickUpGuy2()
{
	servo(0, level);    //setup
    servo(3, open);
    
    forward(20, 1500);     //action
    servo(3, closed);
    servo(0, up);
}

//////////////////////////////////////////////////////////////
// third draft, speed of forward function changed, not used
void pickUpGuy3()
{
	servo(0, level);    //setup
    servo(3, open);
    
    forward(10, 1000);     //action
    servo(3, closed);
    servo(0, up);
}
    
//////////////////////////////////////////////////////////////
// should place down the guy
void putDownGuy()
{
    servo(3, closed);
    servo(0, up);
    wait(500);
    
    
    servo(0, level);   
    servo(3, open);
}

//////////////////////////////////////////////////////////////
// simple line following code, with a parameter of how many ticks
void lineFollow(int ticks)
{
   while (gmpc(0) < ticks && gmpc(3) < ticks)
   {
     {
    if(analog(5) > 3500)
    {
        motor(0,10);
        motor(3,50);
    }
    else 
    {
        motor(0,50);
        motor(3,10);
        
    }

} 
   }
}

//////////////////////////////////////////////////////////////
// not used
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

//////////////////////////////////////////////////////////////
// initializes servos to starting position
void startUp()
{
	servo(0, level);
    servo(3, open);
    
}
 
//////////////////////////////////////////////////////////////
// tells robot to move forward until it hits a line of black tape
void stopAtLine(int speed)
{
    while (analog(0) < 3000)
    {
        motor(0, speed);
        motor(3, speed);
        msleep(10);
    }
}

//////////////////////////////////////////////////////////////

void Clear()
{
    cmpc(0);
    cmpc(1);
    cmpc(2);
    cmpc(3);
}

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

int left = -100;
int right= 100;
int closed = 1127;
int open = 730;
int level = 1216;
int up = 300;

                                    /////////////////////////////////////////////

void turn(int direction, int time);
void forward(int speed, int time);
void wait(int time);
void servo(int servo, int position);
void pickUpGuy();
void pickUpGuy2();
void pickUpGuy3();
void startUp();
void clear();


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    enable_servos();
   // startUp;
////////////////////////
    
    servo(0, up);
    servo(3, closed);    
	cmpc(0);
    cmpc(3);
    
    wait(500);
    pickUpGuy2();
    wait(500);
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void turn(int direction, int time)
{
    motor(3 , direction);
    motor(0, -(direction));
  	  msleep(time);
    
    wait(500);
}

//////////////////////////////////////////////////////////////

void forward(int speed, int time)
{
    motor(3, speed);
    motor(0, speed);
    msleep(time);
    
    wait(500);

}

//////////////////////////////////////////////////////////////

void wait(int time)
{
    motor(3, 0);
    motor(0, 0);
    msleep(time);
}

//////////////////////////////////////////////////////////////

void servo(int servo, int position)
{
	set_servo_position(servo, position);
    wait(500);
}

//////////////////////////////////////////////////////////////

void pickUpGuy()
{
    servo(0, level);    //setup
    servo(3, open);

   // forward(50, 500);     //action
    servo(3, closed);
    servo(0, up);
}
    
//////////////////////////////////////////////////////////////

void pickUpGuy2()
{
	servo(0, level);    //setup
    servo(3, open);
    
    forward(20, 1000);     //action
    servo(3, closed);
    servo(0, up);
}

//////////////////////////////////////////////////////////////

void pickUpGuy3()
{
	servo(0, level);    //setup
    servo(3, open);
    
    forward(10, 1000);     //action
    servo(3, closed);
    servo(0, up);
}
    
//////////////////////////////////////////////////////////////

void startUp()
{
	servo(0, level);
    servo(3, open);
    
}
    
//////////////////////////////////////////////////////////////

void Clear()
{
    cmpc(0);
    cmpc(1);
    cmpc(2);
    cmpc(3);
}

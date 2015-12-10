

/*
 * LeapTek : Connecting Leap Motion Controller to the MediaTek LinkIt One Board 
 * Author : Geeve George
 * Instrubtables : http://www.instructables.com/member/Geeve+George/
 */




import com.leapmotion.leap.*; //leap motion library
import processing.serial.*; //serial communication library

Controller leap; //define a controller
Serial port; //define a port



void setup(){
  size(250,250); //sketch size
  leap = new Controller(); // initialize the controller
  port = new Serial(this, "YOUR COM PORT HERE", 9600);//initialize the port in my case its [2]
}

void draw(){
  FingerList fingers = leap.frame().fingers().extended(); //finger list to get the fingers count
  int count = fingers.count(); // integer holds the count of fingers
  
  background(0);  // box background color
  fill(255); // text color
  textSize(height/2); // text size
  text(count, 90, 160); // text value and position on the box
  port.write(count); // port sends the integer to arduino
}

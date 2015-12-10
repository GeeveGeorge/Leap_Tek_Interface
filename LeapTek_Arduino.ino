

/*
 * LeapTek : Connecting Leap Motion Controller to the MediaTek LinkIt One Board 
 * Author : Geeve George
 * Instrubtables : http://www.instructables.com/member/Geeve+George/
 */




int ledone = 8;
int ledtwo = 10;
int ledthree = 11;
int c = -1; // int for income value

void setup()
{ 
  Serial.begin(9600); //set serial with baud rate
  pinMode(ledone,OUTPUT);
  pinMode(ledtwo,OUTPUT);
  pinMode(ledthree,OUTPUT);
}

void loop()
{ 
  if (Serial.available()>0){  //if we have incoming value
    c =Serial.read(); //read the value minus 48 
    Serial.println(c); 
    if(c == 0) 
    {
      digitalWrite(ledone,LOW); //if 0 fingers turn off led
      digitalWrite(ledtwo,LOW);
      digitalWrite(ledthree,LOW);
    }
    else if(c==1)
    {
      digitalWrite(ledone,HIGH);
      digitalWrite(ledtwo,LOW);
      digitalWrite(ledthree,LOW);
    }

    else if(c==2)
    {
      digitalWrite(ledone,LOW);
      digitalWrite(ledtwo,HIGH);
      digitalWrite(ledthree,LOW);
      
    }

    else if(c==3)
    {
      
      digitalWrite(ledone,LOW);
      digitalWrite(ledtwo,LOW);
      digitalWrite(ledthree,HIGH);
    }
    else if(c == 5) {
      
      digitalWrite(ledone,HIGH);
      digitalWrite(ledtwo,HIGH);
      digitalWrite(ledthree,HIGH);//if 5 fingers turn on led
    }
  }
}

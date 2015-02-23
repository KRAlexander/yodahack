void setup()
{
Serial.begin(115200);
pinMode(6,OUTPUT);
}

float read_ldr(int pin_number)
{
 return analogRead(pin_number); 
}

bool laser_on(int pin_number, int threshold)
{
  if(analogRead(pin_number) > threshold)
  {
    return true;
  }
   else return false;
}

void loop()
{
  float time = 0;
  time = random(10,1000);//wait random amount of time
  digitalWrite(6,HIGH);//turn laser on!!
  if(laser_on(5,150)) Serial.println("All is Well");
  else Serial.println("ALERT!!");  
  delay(time);//waigt random amount of time
  digitalWrite(6,LOW);//turn laser off!
  delay(0.01);
  if(!laser_on(5,150)) Serial.println("All is Well");
  else Serial.println("ALERT!!");  
  time = random(10,1000);//wait random amount of time
  delay(time);
  if(!laser_on(5,150)) Serial.println("All is Well");
  else Serial.println("ALERT!!");  
}


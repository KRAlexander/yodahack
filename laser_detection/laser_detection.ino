void setup()
{
Serial.begin(115200);
pinMode(6,OUTPUT);
digitalWrite(6,LOW);
}

float read_ldr(int pin_number)
{
 //Serial.println(analogRead(pin_number));
 return analogRead(pin_number); 
}

boolean laser_on(int pin_number, int threshold)
{
  if(read_ldr(pin_number) < threshold)
  {
    return true;
  }
   else return false;
}

void loop()
{
  float time = 0;
  
  boolean a = laser_on(5,600);
  
  time = random(50,200);//wait random amount of time
  //Serial.println("TURNING LASER ON");
  digitalWrite(6,HIGH);//turn laser on!!
  delay(10);

  boolean b = laser_on(5,600);
  Serial.println(analogRead(5));
  if (!a&&b) {
    Serial.println("All is Well");
  } else {
    Serial.println("ALERT");
  }
    
  delay(time);//waigt random amount of time
  
  a = laser_on(5,600);
  //Serial.println("TURNING LASER OFF");
  digitalWrite(6,LOW);//turn laser off!
  delay(50);
  
  b = laser_on(5,600);
  
  if (a&&!b) {
    Serial.println("All is Well");
  } else {
    Serial.println("ALERT");
  }

  time = random(50,200);//wait random amount of time
  
  delay(time);
  
}


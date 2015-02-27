//#include <avr/io.h>
//#include <avr/interrupt.h>

volatile long adcbin;
volatile long cnt;



void setup() {
pinMode(13,OUTPUT);
Serial.begin(57600);
Serial.println("Starting up..........");
/*
  adcbin = 0;    //accumulation bin
  cnt = 0;    //count variable
*/
  ADMUX |= (1 << REFS0); // Set ADC reference to AVCC
  ADMUX |=(1<<ADLAR); // left adjust results
  ADCSRA |= (1 << ADEN);  // Enable ADC
  //ADCSRA |= (1 << ADATE); // Enable auto-triggering
  //ADCSRA |= (1 << ADIE);  // Enable ADC Interrupt
  ADCSRA |= (1<<ADPS2) | (1<<ADPS0);
  //sei();                 // Enable Global Interrupts
  ADCSRA |= (1 << ADSC);  // Start A2D Conversions
  
}
void loop() {
  // put your main code here, to run repeatedly:
//Serial.println("All is fine");
digitalWrite(13,LOW);
//delay(100);
Serial.println(analogRead(0));
//digitalWrite(13,HIGH);
//delay(100);
//Serial.println(analogRead(0));

/*
  ADCSRA &= ~(1 << ADSC);    //Stop ADC
  ADCSRA &= ~(1(ADCSRA,ADIE);    //Disable ADC interrupts

  ADCSRA |= (1 << ADIE);    //Re-enable ADC interrupts and A2D conversions
  ADCSRA |= (1 << ADSC);
*/

}

ISR(ADC_vect)            //ADC interrupt
{
  /*
  uint8_t high,low;

  low = ADCL;            //Make certain to read ADCL first, it locks the values
  high = ADCH;            //and ADCH releases them.

  aval = (high << 8) | low;
*/
  /* for further brevity at cost of clarity

      aval = ADCL | (ADCH << 8);

  also seems to work        */
/*
    adcbin = adcbin + aval;    //accumulate the ADC values
    cnt++;    //iterate the counter
    */
    //Serial.println(ADCH);//Left adjusted result, only 8-bit precision
} 


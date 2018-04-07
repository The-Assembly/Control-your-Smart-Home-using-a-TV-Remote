#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

        switch(results.value){
          case 0x20DF10EF:
          Serial.println("On/Off");
          break;
          case 0x2ADE08A3:
          Serial.println("1");
          break ;  
          case 0x20DF48B7:
          Serial.println("2");
          break ;
          case 0x1A46B33F:
          Serial.println("3");
          break ;
          
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}


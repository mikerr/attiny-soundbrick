
int oldstate;
int SPEAKER = 0;
int TILT = 4;
//int LED = 4;

void setup()  {
  pinMode(TILT,  INPUT_PULLUP);
  pinMode(SPEAKER, OUTPUT); 
  
  oldstate = LOW;
  
  beep();
} 

//ok beep
void beep (){
      tone(SPEAKER,1024);
      delay(100);
      tone(SPEAKER,256);
      delay(100);
      noTone(SPEAKER);
}

// falling tone for bomb
void bomb () {
   for (int x=1000;x>500;x=x-10) {
    tone(SPEAKER,x);
    delay(20);
   }
   noTone(SPEAKER);
}

// rising tone sounds like a laser gun
void lasergun (){
  for (int x=10;x<1000;x=x+50) {
    tone(SPEAKER,x);
    delay(10);
  }
  noTone(SPEAKER);
}

// random noise for explosion
void explosion () {
  
  for (int x=0;x<2000;x++) {
    tone(SPEAKER,500+rand()*100);
  }
  noTone(SPEAKER);
}
void loop() {
int newstate;


  newstate = digitalRead(TILT);
 
  if (newstate != oldstate) {
          //digitalWrite(LED,HIGH);   
          lasergun();
          lasergun();
          delay(200);
          bomb();
          explosion();
          delay(200);
      
      // read sensor again after sound played - acts as a debouncer   
      oldstate = digitalRead(TILT);
      }
 //digitalWrite(LED,LOW);     
}

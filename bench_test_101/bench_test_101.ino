//Version 1.01
//  -Implemented Riva's modifications (to avoid the impact of serial transmission in the calibration)
//  -Not the compiler option is the same on all the platforms (Thanks Westfw)

#pragma GCC optimize ("-O1")

int led = 13; //13 in arduino uno nano and due - PC13 in STM32
int ia,ib,ic,id,ie,ig,ih,ii;
long int la,lb,lc,ld,le,lg,lh,li,N;
long int runs=0;
float fa,fb,fc,fd,fe,fg,calib;
double da,db,dc,dd,de,df,dg;
long elapsed;





// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  
  
  pinMode(led, OUTPUT); 
  Serial.begin(250000);
  Serial.print("test");
  delay(1000);
  
 
    
    
}

// the loop routine runs over and over again forever:
void loop() {
  runs++;
  digitalWrite(led, LOW);   
  delay(200);               
  digitalWrite(led, HIGH); 
  
  delay(200);               // wait for a second
  
  
  ie=random(1,2);
  elapsed=micros();
  for (ic=ie; ic<(ie+30000); ic++) //this syntax avoid compiler semplifications
  {
      
  }
  elapsed=micros()-elapsed;
  
  Serial.print(" Time (ms)...= ");
  Serial.print(millis());
  Serial.println(" ms");
  Serial.print(" INT_LOOP(30000) bench...= ");
  
  
  Serial.print(elapsed);
  Serial.print(" microseconds");
  Serial.print(" ");
  Serial.print((float)30000/(float)elapsed);
  Serial.println("MIPS");
  
    
  
  la=(long)random(1,2);
  lb=(long)random(1,1000);
  fb=0;
  fg=0;
  le=random(1,2);
  elapsed=micros();
  for (lc=le; lc<(le+30000); lc++) //this syntax avoid compiler simplifications
  {
      
  }
  elapsed=micros()-elapsed;
  calib=(float)elapsed;
  
  Serial.print(" LONG_LOOP(30000) bench...= ");
  
  Serial.print(elapsed);
  Serial.print(" microseconds");
  Serial.print(" ");
  Serial.print((float)30000/(float)elapsed);
  Serial.println("MIPS");
  
  
  
  fa=(float)random(1,2);
  fb=(float)random(1,1000);
  fb=0;
  fg=0;
  le=random(1,2);
  elapsed=micros();
  for (lc=le; lc<(le+30000); lc++)
  {
    fb=fb/fa;       
  }
  elapsed=micros()-elapsed;
  
  Serial.print(" FLOAT_DIV(30000) bench...= ");
  
  Serial.print(elapsed);
  Serial.print(" microseconds");
  Serial.print(" ");
  Serial.print((float)30000/((float)elapsed-calib));
  Serial.println("MFLOPS");
  
  
  le=random(1,2);
  da=(double)random(1,2);
  db=(double)random(1,1000);
  db=0;
  dg=0;
  elapsed=micros();
  for (lc=le; lc<(le+30000); lc++)
  {
    db=db/da;       
  }
   elapsed=micros()-elapsed;
    
    Serial.print(" DOUBLE_DIV(30000) bench...= ");
  
  Serial.print(elapsed);
  Serial.print(" microseconds");
  Serial.print(" ");
  Serial.print((float)30000/((float)elapsed-calib));
  Serial.println("MFLOPS");
  
  
  
  le=random(1,2);
  elapsed=micros();
  for (lc=le; lc<(le+30000); lc++)
  {
    fb=fb*fa;       
  }
    
  elapsed=micros()-elapsed;  
    Serial.print(" FLOAT_MUL(30000) bench...= ");
  
  Serial.print(elapsed);
  Serial.print(" microseconds");
  Serial.print(" ");
  Serial.print((float)30000/((float)elapsed-calib));
  Serial.println("MFLOPS");
  le=random(1,2);
  elapsed=micros();
  for (lc=le; lc<(le+30000); lc++)
  {
    db=db*da;       
  }
   elapsed=micros()-elapsed; 
    
    Serial.print(" DOUBLE_MUL(30000) bench...= ");
  
  Serial.print(elapsed);
  Serial.print(" microseconds");
  Serial.print(" ");
  Serial.print((float)30000/((float)elapsed-calib));
  Serial.println("MFLOPS");
  
  Serial.println("-------------------------------------------");
  
  
  delay(200);
  

}

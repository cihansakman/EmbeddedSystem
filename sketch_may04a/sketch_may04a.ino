#define entrance_pir 13
#define exit_pir 12

int count = 0;

void setup() {
Serial.begin(9600);
pinMode(entrance_pir, INPUT);
pinMode(exit_pir, INPUT);
}

void loop() {
  
int entr_pir_input=digitalRead(entrance_pir);
int exit_pir_input=digitalRead(exit_pir);

int situation = 0;

/*First we'll go through entrance */
if(entr_pir_input==HIGH)
{
  situation = 1;
}else{
  situation = 0;
}
if(situation == 1){
  count = count + 1; //Increase count.
  //Print the message and current occupancy.
  Serial.print("You entered, the person inside is:");
  Serial.print(count);
  Serial.println();
  //prevent multiple reads
  situation=0;
  delay(750);
}

/*Now we should consider when the person leave the place */
if(exit_pir_input==HIGH)
{
  situation = -1;
}else{
  situation = 0;
}
if(situation == -1){
  if(count>0){
  count = count - 1; //Decrease count.
  //Print the message and current occupancy.
  Serial.print("You left, the person inside is:");
  Serial.print(count);
  Serial.println();
  //prevent multiple reads
  situation=0;
  delay(750);
  }
  else{
    Serial.println("You can't leave the place where you don't exist!");
    delay(750);
  }
}





}

#define A_entrance_pir 13
#define A_exit_pir 12

#define B_entrance_pir 8
#define B_exit_pir 9


int A_count = 0;
int B_count = 0;
int total_count = 0;

void setup() {
Serial.begin(9600);
pinMode(A_entrance_pir, INPUT);
pinMode(A_exit_pir, INPUT);

pinMode(B_entrance_pir, INPUT);
pinMode(B_exit_pir, INPUT);
}

void loop() {
  
int A_entr_pir_input=digitalRead(A_entrance_pir);
int A_exit_pir_input=digitalRead(A_exit_pir);

int B_entr_pir_input=digitalRead(B_entrance_pir);
int B_exit_pir_input=digitalRead(B_exit_pir);

int A_situation = 0;
int B_situation = 0;
/*First we'll go through entrance */
if(A_entr_pir_input==HIGH)
{
  A_situation = 1;
}else{
  A_situation = 0;
}
if(A_situation == 1){
  A_count = A_count + 1; //Increase count.
  total_count = total_count +1; 
  //Print the message and current occupancy.
  Serial.print("You entered, the person inside A STORE is:");
  Serial.print(A_count);
  Serial.println();
  Serial.print("The person inside the all STORE is:");
  Serial.print(total_count);
  Serial.println();
  //prevent multiple reads
  A_situation=0;
  delay(750);
}

/*Now we should consider when the person leave the place */
if(A_exit_pir_input==HIGH)
{
  A_situation = -1;
}else{
  A_situation = 0;
}
if(A_situation == -1){
  if(A_count>0){
  A_count = A_count - 1; //Decrease count.
  total_count = total_count - 1; 
  //Print the message and current occupancy.
  Serial.print("You left, the person inside A STORE is:");
  Serial.print(A_count);
  Serial.println();
  Serial.print("The person inside the all STORE is:");
  Serial.print(total_count);
  Serial.println();
  //prevent multiple reads
  A_situation=0;
  delay(750);
  }
  else{
    Serial.println("You can't leave the place where you don't exist!");
    delay(750);
  }
}

//B STORE İŞLEMLERİ

if(B_entr_pir_input==HIGH)
{
  B_situation = 1;
}else{
  B_situation = 0;
}
if(B_situation == 1){
  B_count = B_count + 1; //Increase count.
  total_count = total_count +1; 
  //Print the message and current occupancy.
  Serial.print("You entered, the person inside B STORE is:");
  Serial.print(B_count);
  Serial.println();
  Serial.print("The person inside the all STORE is:");
  Serial.print(total_count);
  Serial.println();
  //prevent multiple reads
  B_situation=0;
  delay(750);
}

/*Now we should consider when the person leave the place */
if(B_entr_pir_input==HIGH)
{
  B_situation = -1;
}else{
  B_situation = 0;
}
if(B_situation == -1){
  if(B_count>0){
  B_count = B_count - 1; //Decrease count.
  total_count = total_count - 1; 
  //Print the message and current occupancy.
  Serial.print("You left, the person inside B STORE is:");
  Serial.print(B_count);
  Serial.println();
  Serial.print("The person inside the all STORE is:");
  Serial.print(total_count);
  Serial.println();
  //prevent multiple reads
  B_situation=0;
  delay(750);
  }
  else{
    Serial.println("You can't leave the place where you don't exist!");
    delay(750);
  }
}




}

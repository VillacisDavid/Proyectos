int pinled1 = 13;
int pinled2 = 12;
int pinrele = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinled1, OUTPUT);
  pinMode(pinled2, OUTPUT);
  pinMode(pinrele, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(pinled2, HIGH);
  int lectura1 = analogRead(A0);
  int lectura2 = analogRead(A1);
  Serial.print("Lectura 1: ");
  Serial.print(lectura1);
  Serial.print("\n");
  Serial.print("Lectura 2: ");
  Serial.print(lectura2);
  Serial.print("\n");
  
  if((lectura1+lectura2)/2 > 600){
    digitalWrite(pinled1,HIGH);
    digitalWrite(pinrele,HIGH);
    delay(10000);
    digitalWrite(pinled1,LOW);
    digitalWrite(pinrele,LOW);
    delay(400);
    blink(3);
  }else{
    blink(5);
  }
  delay(10000);//10S
}

void blink(int times){
  for(int i=0;i<times;i++){
      digitalWrite(pinled1, HIGH);
      delay(700);
      digitalWrite(pinled1, LOW);
      delay(400);
  }
}

float R1 = 98900.0;
float R2 = 9820.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  float vout = (value*5.3)/1024.0;
  float vin= vout/(R2/(R1+R2));
  
  Serial.print(value);
  Serial.print(':');
  Serial.println(vin);

}

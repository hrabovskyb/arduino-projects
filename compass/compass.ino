#include <Wire.h>


#define MAG_ADDRESS (0x3c >> 1)
#define MAG_REGISTER_XMSB (0x03)
#define MAG_REGISTER_MEASMODE (0x02)
#define MAG_MEASMODE_CONT (0x00)
//char c;


void i2c_write(int address, byte reg, byte data) {
  // Send output register address
  Wire.beginTransmission(address);
  Wire.write(reg);
  // Connect to device and send byte
  Wire.write(data); // low byte
  Wire.endTransmission();
}

void i2c_read(int address, byte reg, int count, byte* data) {
 int i = 0;

 // Send input register address
 Wire.beginTransmission(address);
 Wire.write(reg);
 Wire.endTransmission();
 // Connect to device and request bytes
 Wire.beginTransmission(address);
 Wire.requestFrom(address,count);
 while(Wire.available()){ // slave may send less than requested {
   char c = Wire.read(); // receive a byte as character
   data[i] = c;
   i++;
 }
 Wire.endTransmission();
}

void init_mag() {
  byte data = 0;
  //set up continuous measurement
  i2c_write(MAG_ADDRESS, MAG_REGISTER_MEASMODE, MAG_MEASMODE_CONT);

  //Sanity check, make sure the register value is correct.
  i2c_read(MAG_ADDRESS, MAG_REGISTER_MEASMODE, 1, &data);
  Serial.println((unsigned int)data);
}

int magnetometer_data[3];
void read_itg3200() {
 byte bytes[6];
 memset(bytes,0,6);

  //read 6 bytes from the HMC5843
 i2c_read(MAG_ADDRESS, MAG_REGISTER_XMSB, 6, bytes);

  //now unpack the bytes
 for (int i=0;i<3;++i) {
 magnetometer_data[i] = (int)bytes[2*i + 1] + (((int)bytes[2*i]) << 8);
 }
}

int mag_data[3];
void read_mag() {
 byte bytes[6];
 memset(bytes,0,6);

  //read 6 bytes from the HMC5843
 i2c_read(MAG_ADDRESS, MAG_REGISTER_XMSB, 6, bytes);

  //now unpack the bytes
 for (int i=0;i<3;++i) {
 mag_data[i] = (int)bytes[2*i + 1] + (((int)bytes[2*i]) << 8);
 }
}


void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  mag_data[0] = mag_data[1] = mag_data[2] = 0;
  init_mag();
}

void loop() {
  // put your main code here, to run repeatedly:
  read_mag();
  Serial.print("X: ");
  Serial.print(mag_data[0]);
  Serial.print(", Y: ");
  Serial.print(mag_data[2]);
  Serial.print(", Z: ");
  Serial.println(mag_data[1]);
  
 
}

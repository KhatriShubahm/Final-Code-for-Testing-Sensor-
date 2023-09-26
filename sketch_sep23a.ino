#include <Wire.h>                                                                        //These include the libraries for the connection 
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);                        // 12345 is the I2C address, you can change it if needed

void setup(void)                                                                          //The setup function is executed once when the Arduino starts. It initializes serial 
                                                                                          //communication at a baud rate of 9600 and prints "ADXL345 Test" to the serial monitor.
{
  Serial.begin(9600);
  Serial.println("ADXL345 Test");

  if(!accel.begin())
  {
    Serial.println("Could not find a valid ADXL345 sensor, check wiring!");               //It then checks if the ADXL345 sensor is responding by calling the begin method on the accel object. If the sensor is not found, it prints an error message and enters an infinite loop.
    while(1);
  }
}

void loop(void)
{
  sensors_event_t event;
  accel.getEvent(&event);

  // Display the accelerometer data
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");             //he accelerometer data (X, Y, and Z-axis acceleration) is then printed to the serial monitor along with the unit "m/s^2" (meters per second squared).
  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.println("  m/s^2");

  delay(500);                                                                              // Delay for 0.5 seconds
}

#include <Servo.h>
#define DIGITAL_SENSOR_PIN 2 // Chân kết nối D0 của cảm biến
#define RED_PIN 9      // Chân điều khiển màu đỏ
#define GREEN_PIN 10   // Chân điều khiển màu xanh lá
#define BLUE_PIN 11    // Chân điều khiển màu xanh dương
Servo servo_cuaSoTrai;//3
Servo servo_cuaChinhPhai;//5
Servo servo_cuaChinhTrai;//6
int cm = 0;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
void setup() {
   pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(DIGITAL_SENSOR_PIN, INPUT); // Cài đặt chân D0 làm đầu vào
  Serial.begin(9600);                // Khởi động giao tiếp Serial
  
  servo_cuaSoTrai.attach(3, 500, 2500);
servo_cuaChinhPhai.attach(5, 500, 2500);
servo_cuaChinhTrai.attach(6, 500, 2500);
// Tắt toàn bộ LED (vì là Common Anode)
  analogWrite(RED_PIN, 255);   // 255 = Tắt
  analogWrite(GREEN_PIN, 255); // 255 = Tắt
  analogWrite(BLUE_PIN, 255);  // 255 = Tắt
}

void loop() {

int sensorState = digitalRead(DIGITAL_SENSOR_PIN); // Đọc trạng thái cảm biến
  if (sensorState == HIGH) {
    Serial.println("Trong phòng đang tối"); // Ánh sáng đủ mạnh
    
     analogWrite(RED_PIN, 0);   
  analogWrite(GREEN_PIN, 150 );
  analogWrite(BLUE_PIN, 255);   
  delay(10);
    servo_cuaSoTrai.write(162);
delay(200);
    
  
    
  } else {
     Serial.println("Trong phòng đang sáng"); // Ánh sáng yếu hoặc tối
    servo_cuaSoTrai.write(0);
delay(200);
    analogWrite(RED_PIN, 255);   
  analogWrite(GREEN_PIN, 255 );
  analogWrite(BLUE_PIN, 255);  


    delay(10);
  
 
  }
  delay(10); // Đọc giá trị mỗi 


// measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  // convert to inches by dividing by 2.54
  
  Serial.print("Khoảng cách đến vật là : ");
  
  Serial.print(cm);
  Serial.println("cm");
  delay(50); // Wait for 100 millisecond(s)

 if(cm< 20)
      {             
         analogWrite(RED_PIN, 0);   
  analogWrite(GREEN_PIN, 0 );
  analogWrite(BLUE_PIN, 70); 
  delay(100) ;
      servo_cuaChinhPhai.write(65) ;
    delay (100);
     servo_cuaChinhTrai.write(100) ;
    delay (100);
        
  delay (2000);
      
      }
  else {
       
    servo_cuaChinhPhai.write(175) ;
    delay (200);
     servo_cuaChinhTrai.write(11) ;
    delay (200);
 
     }

  



}

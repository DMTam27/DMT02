#include<Servo.h>
const int gasPin = A0; // Chân kết nối cảm biến (analog)
int gasValue;          // Biến lưu giá trị khí gas đo được
int coiBaoDong =13;
Servo servo_cuaSoBep;//3
int ledPin1 = 4;   // Chân LED 1 do
int ledPin2 = 7;   // Chân LED 2 xanh
int ledPin3 = 8;   // Chân LED 3 vang
int ledPin4 = 12;  // Chân LED 4 trang
int delayTime = 100; // Thời gian trễ giữa các hiệu ứng (ms)

void setup() {
  Serial.begin(9600); // Khởi động Serial Monitor
  Serial.println("Đang đọc dữ liệu từ cảm biến khí gas MQ-2...");
  pinMode(coiBaoDong,OUTPUT);
  servo_cuaSoBep.attach(3, 500, 2500);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);

}

void loop() {
  gasValue = analogRead(gasPin); // Đọc giá trị từ cảm biến MQ-2
  Serial.print("Giá trị khí gas: ");
  Serial.println(gasValue); // In giá trị ra Serial Monitor

  // Cảnh báo khi giá trị khí gas vượt ngưỡng
  if (gasValue > 500) { // Điều chỉnh ngưỡng tùy theo nhu cầu
    Serial.println("Cảnh báo: Nồng độ khí gas cao!");
    servo_cuaSoBep.write(20);
    delay(100);
      
    digitalWrite(coiBaoDong, HIGH); 
    delay(1000);                     
    digitalWrite(coiBaoDong, LOW); 
    delay(50);    
    digitalWrite(coiBaoDong, HIGH); 
    delay(1000);                     
    digitalWrite(coiBaoDong, LOW); 
    delay(50);    
    digitalWrite(coiBaoDong, HIGH); 
    delay(1000);                     
    digitalWrite(coiBaoDong, LOW); 
    delay(50);    
      } 
   else{
  digitalWrite(coiBaoDong,LOW);
  servo_cuaSoBep.write(162);
    delay(100);}

  delay(100); // Chờ 1 giây trước khi đọc lần tiếp theo


//led cay thong
  // Hiệu ứng sáng lần lượt từ LED 1 đến LED 4
  digitalWrite(ledPin1, HIGH);
  delay(delayTime);
  digitalWrite(ledPin1, LOW);

  digitalWrite(ledPin2, HIGH);
  delay(delayTime);
  digitalWrite(ledPin2, LOW);

  digitalWrite(ledPin3, HIGH);
  delay(delayTime);
  digitalWrite(ledPin3, LOW);

  digitalWrite(ledPin4, HIGH);
  delay(delayTime);
  digitalWrite(ledPin4, LOW);

  // Hiệu ứng ngược lại từ LED 4 về LED 1
  digitalWrite(ledPin4, HIGH);
  delay(delayTime);
  digitalWrite(ledPin4, LOW);

  digitalWrite(ledPin3, HIGH);
  delay(delayTime);
  digitalWrite(ledPin3, LOW);

  digitalWrite(ledPin2, HIGH);
  delay(delayTime);
  digitalWrite(ledPin2, LOW);

  digitalWrite(ledPin1, HIGH);
  delay(delayTime);
  digitalWrite(ledPin1, LOW);

  delay(30);

digitalWrite(ledPin3, HIGH);
delay(10);
digitalWrite(ledPin2, HIGH);
  delay(50);
digitalWrite(ledPin2, LOW);
digitalWrite(ledPin3, LOW);

digitalWrite(ledPin1, HIGH);
delay(10);
digitalWrite(ledPin4, HIGH);
  delay(50);
digitalWrite(ledPin1, LOW);
digitalWrite(ledPin4, LOW);
delay(30);
  // nhấp nháy 3 lần
  for (int j = 0; j < 3; j++) { // Nháy 5 lần
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    delay(40);
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    delay(40);
  }
  digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);
    delay(100);


}

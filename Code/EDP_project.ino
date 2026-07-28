#include <Servo.h>
#include <EEPROM.h>
#include <U8g2lib.h>
#include <Wire.h>

// U8G2 Page Buffer Mode (low RAM)
U8G2_SH1106_128X64_NONAME_1_HW_I2C display(U8G2_R0, U8X8_PIN_NONE);
Servo myservo;

int angle = 80;
int address = 0;

float lower_threshold;
float upper_threshold;
float voltage_list[30] = {}; // reduced size to save RAM

int index = 0;
int up_index = 0;

void showSplashScreen() {
  display.setFont(u8g2_font_helvB10_tr);  // Stylish bold Helvetica font

  for (int x = -100; x < 5; x += 5) {    // Slide in from left
    display.firstPage();
    do {
      display.drawStr(x, 32, "SKYNET TRONICS");  // Animate X position
    } while (display.nextPage());
    delay(50);  // Small delay for smooth animation
  }

  delay(1500);  // Pause after animation

  // Optional: clear screen
  display.firstPage();
  do {
    // Blank screen
  } while (display.nextPage());
}

void setup() {
  myservo.attach(6);
  EEPROM.update(address, angle);
  angle = EEPROM.read(address);
  if (angle < 0 || angle > 180) angle = 0;
  myservo.write(angle);
  delay(1000);

  Serial.begin(9600);
  display.begin();
  showSplashScreen(); 
  pinMode(13, OUTPUT);
}

void loop() {
  // Read thresholds
  
  int low_voltage = analogRead(A2); //max = 550
  int up_voltage = analogRead(A0);

  lower_threshold = 10 + (low_voltage / 10);
  if (lower_threshold > 60) lower_threshold = 60;   // lower_threshold 0 - 50

  upper_threshold = 60 + (up_voltage / 10);
  if (upper_threshold > 100) upper_threshold = 100;   // upper_threshold 50 - 100

  // Read voltage input and calculate average
  float sum_of_average =0;
  for (int k =0;k<10;k++){
    int t = 0;
    for (int i = 0; i < 30; ) {
      int raw = analogRead(A1);
      float voltage = raw / 5;
      if (voltage > 0) {
        voltage_list[t] = voltage;
        delay(2);
        t++;
        i++;
      }
    }

    float total = 0.0;
    int count = 0;
    for (int j = 0; j < 30; j++) {
      if (voltage_list[j] > 5 && voltage_list[j] < 800) {
        total += voltage_list[j];
        count++;
      }
    }

    float average_1 = total / (count == 0 ? 1 : count); // prevent division by zero
    sum_of_average += average_1;
    delay(50);
  }
  float average = sum_of_average / 10 ;
  average = average - 60;

  if(average > 30){
  // Adjust index for servo movement
    if (average < lower_threshold) index++;
    else if (index > 0) index--;

    if (average > upper_threshold) up_index++;
    else if (up_index > 0) up_index--;


    if (index >= 5 && angle < 174) {
      if((lower_threshold - average) > 10 ){
        if (angle > 130){
          angle = 177;
        }
        else{
          angle += 50;
        }
      }
      else if((lower_threshold - average) > 5 ){
        if (angle > 155){
          angle = 177;
        }
        else{
          angle += 25;
        }
      }
      else{
      angle += 5;
      }
      myservo.write(angle);
      delay(500);
      index = 0;
    }

    if (up_index >= 4 && angle > 10) {
      if((average - upper_threshold) > 10 ){
        if (angle < 55){
          angle = 5;
        }
        else{
          angle -= 50;
        }
      }
      else if((average - upper_threshold) > 5 ){
        if (angle < 30){
          angle = 5;
        }
        else{
          angle -= 25;
        }
      }
      else{
      angle -= 5;
      }
      myservo.write(angle);
      delay(500);
      up_index = 0;
    }
  }

  if (average < 0) average = 0;

  EEPROM.update(address, angle);
  delay(20);

  // Display on OLED using page buffer
  display.firstPage();
  do {  
    display.setFont(u8g2_font_6x10_tr);
    display.setCursor(0, 8);
    display.print("VOLUME");

    display.setCursor(80, 8);
    display.print("GAIN");

    display.setFont(u8g2_font_10x20_tr);
    display.setCursor(80, 28);
    display.print(angle-80);

    display.setFont(u8g2_font_fub20_tr);
    display.setCursor(10, 34);
    display.print(average,0);

    display.setFont(u8g2_font_6x10_tr);
    display.setCursor(26, 50);
    display.print("-Thresholds-");
    
    display.setCursor(5, 63);
    display.print("UP: ");
    display.print(upper_threshold, 0);

    display.setCursor(72, 63);
    display.print("DOWN: ");
    display.print(lower_threshold, 0);

    // display.drawLine(67, 0, 67 , 39);      // (x1, y1, x2, y2)
    // display.drawLine(0, 39, 128 , 39 );    // (x1, y1, x2, y2)

  } while (display.nextPage());
}

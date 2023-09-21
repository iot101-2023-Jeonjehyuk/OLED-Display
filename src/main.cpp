#include <Arduino.h>
#include <SSD1306.h>

SSD1306             display(0x3c, 4, 5, GEOMETRY_128_32);

int val =0;

void setup() {
  Serial.begin(115200);
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
}

void loop() {
  display.setColor(BLACK);
  display.fillRect(10, 10, 120, 33); // 픽셀의 x,y 좌표 = 10,10
  display.setColor(WHITE);
  val = analogRead(0);
  display.drawString(10, 10 ,"Value : "+(String)val + " lux"); //조도 단위 lux(룩스)
  Serial.println(val);
  display.display();
  delay(100);

}
  




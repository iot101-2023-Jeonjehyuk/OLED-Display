#include <Arduino.h>
#include <SSD1306.h>

SSD1306             display(0x3c, 4, 5, GEOMETRY_128_32);

int val =0;
float alpha = 0.3;// 가중치 알파의 값
float EW = 0; //지수가중평균값 
void setup() {
  Serial.begin(115200);
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  
}

void loop() {
  display.setColor(BLACK);
  display.fillRect(0, 10, 130, 33); // 픽셀의 x,y 좌표 = (0,10)
  display.setColor(WHITE);
  val = analogRead(0);
  Serial.println(val);
  EW = alpha * val + (1 - alpha) * EW;
  Serial.println(EW);
  display.drawString(0, 10 ,"Val:"+(String)val + ",ema:"+(String)EW); 
  display.display();
  delay(100);
}
  




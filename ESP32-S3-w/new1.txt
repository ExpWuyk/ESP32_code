#include <Arduino.h>
#include <FastLED.h>


#define LED_PIN  48        //定义LED引脚
#define NUM_LEDS 1         //RGB灯个数
CRGB leds[NUM_LEDS];
uint8_t max_bright = 10;  // LED亮度控制变量，可使用数值为 0 ～ 255， 数值越大则光带亮度越高


void setup() 
{  
  Serial.begin(115200);

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS); // 初始化光带
  FastLED.setBrightness(max_bright);                     // 设置光带亮度
  // put your setup code here, to run once:
}

void loop() 
{
  
  Serial.println("huise");           //串口打印灯的颜色
  leds[0] = CRGB::Green;              //CRGB ( 122, 115, 116);  由三原色  红 绿 蓝 调节不同亮度改变灯的颜色 
  FastLED.show();                    // 更新LED色彩
  delay(1000);
 
 
}
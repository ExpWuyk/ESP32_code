
#define BLINKER_WIFI

#include <Blinker.h>

#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 1         //RGB灯个数
CRGB leds[NUM_LEDS];

char auth[] = "517931d32d0f";
char ssid[] = "W";
char pswd[] = "12345678";

// 新建组件对象
BlinkerButton Button1("btn-on");
BlinkerButton Button2("btn-off");
BlinkerNumber Number1("num-abc");


int counter = 0;

// 按下按键即会执行该函数
void button1_callback(const String & state)
{
    BLINKER_LOG("get button state: ", state);
    //digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    leds[0] = CRGB::Green;              //CRGB ( 122, 115, 116);  由三原色  红 绿 蓝 调节不同亮度改变灯的颜色 
    FastLED.show();
    
}

void button2_callback(const String & state)
{
    BLINKER_LOG("get button state: ", state);
    FastLED.clear();
    FastLED.show();

}

// 如果未绑定的组件被触发，则会执行其中内容
void dataRead(const String & data)
{
    BLINKER_LOG("Blinker readString: ", data);
    counter++;
    Number1.print(counter);
}

void setup()
{
    // 初始化串口
    Serial.begin(115200);
    BLINKER_DEBUG.stream(Serial);
    BLINKER_DEBUG.debugAll();

    // 初始化有LED的IO
    FastLED.addLeds<WS2812, 48, GRB>(leds, NUM_LEDS); // 初始化光带

    // 初始化blinker
    Blinker.begin(auth, ssid, pswd);
    Blinker.attachData(dataRead);

    Button1.attach(button1_callback);
    Button2.attach(button2_callback);
}

void loop() {
    Blinker.run();
}


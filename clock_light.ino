/*该程序主要功能是根据时间变化而改变灯光颜色
并在OLED中显示出当前时间和年月日以及星期等信息*/

/*引入相关库*/
#include <U8glib.h>
#include <stdio.h>
#include <string.h>
#include <DS1302.h>
#include <FastLED.h>
/* 接口定义*/
#define DATA_PIN 10
uint8_t RST_PIN   = 5;
uint8_t DAT_PIN   = 6;
uint8_t CLK_PIN   = 7;
/* LED灯珠数量*/
#define NUM_LEDS 8
/* 日期变量缓存 */
char buf[50];
char buf_day[10];
char buf_year[20];
char buf_date[20];
char buf_time[20];
char day[10];
/*时间标志*/
bool TIME_1 = false;
bool TIME_2 = false;
/*串口数据缓存*/
String comdata = "";
int numdata[7] ={0}, j = 0, mark = 0;

/*创建对象*/
CRGB leds[NUM_LEDS];
DS1302 rtc(RST_PIN, DAT_PIN, CLK_PIN);
U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE);
/*********************函数声明***********************/
void print_time(void);  //获取和格式化时间程序
void serial_set_time(void);  //串口设置设置时间程序
void u8g_setup(void);   //u8g库初始化设置程序
void oled_draw(void);   //OLED显示程序
void rgb_led(void);     //RGB灯显示程序

/*************************初始化*****************************/
void setup()
{
    Serial.begin(9600);
    rtc.write_protect(false);
    rtc.halt(false);
    u8g_setup();
    FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  //设置灯带型号、数据引脚、对象、灯珠数量
    FastLED.setBrightness(255);   //设置灯珠亮度0~255
}

/*************************主循环*****************************/
void loop()
{
    //serial_set_time();
    oled_draw();
    /* 打印当前时间 */
    print_time();
    //delay(1000);
    rgb_led();
}

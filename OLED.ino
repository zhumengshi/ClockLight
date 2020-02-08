/*************************u8g初始化*****************************/
void u8g_setup(){
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
}
/*************************OLED显示*****************************/
void oled_draw(){
  u8g.firstPage();  
  do {
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(0,15); 
  u8g.print("<");
  u8g.print(buf_year);
  u8g.print(">");
  u8g.print(" -");
  u8g.print(buf_day);
  u8g.print("-");
  u8g.setPrintPos(0,31); 
  u8g.print("<");
  u8g.print(buf_date);
  u8g.print(" ");
  u8g.print(buf_time);
  u8g.print(">");
  } while( u8g.nextPage());
}


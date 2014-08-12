#include <EEPROM.h>
#include <SPI.h>
#include <GD2.h>

#include "spinner_assets.h"

int i = 0;

void setup()
{
  GD.begin();
  LOAD_ASSETS();
}

void loop()
{
  //GD.ClearColorRGB(0x103000);
  GD.Clear();
  GD.cmd_text(240, 68, 31, OPT_CENTER, "56.7 mL/h");
  
  GD.Begin(POINTS); // draw 50-pixel wide green circles
  GD.ColorRGB(20, 91, 71);
  GD.PointSize(50 * 16);
  GD.BlendFunc(SRC_ALPHA, ONE);
  // additive blending
  for (int x = 100; x <= 380; x += 40)
  GD.Vertex2ii(x, 200);
  
  GD.Begin(BITMAPS);
  GD.Vertex2ii(240, 110, SPINNER_HANDLE, i);
  i += 1;
  if(i>11)
    i = 0;
    
  GD.swap();
}

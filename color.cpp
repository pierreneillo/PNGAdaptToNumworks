/*The purpose of this file is to transform any type of color
* accepted by png, this is to say rgb, grayscale, rgba and palette, in the rgb565 format used by Numworks Calculator.
*/

#include <cstdint>
#include <iostream>
#include <string>
template <typename Color>
using namespace std;

int _to_rgb565(string from, Color * color){
  uint16_t rgb565_color = 0;
  if (from == "rgb888" || from == "rgba"){
    //Format is rgb888
    /*First right shift the red green and blue values
    Then shift them back in position to be added
    Finally use logical OR to assemble them
    if there is alpha, simply ignore it*/
    //TODO: Take account for alpha value if there is any
    uint8_t r = color[0];
    uint8_t g = color[1];
    uint8_t b = color[2];
    rgb565_color = ((r >> 3) << 11) | ((g >> 2 ) << 5) | (b >> 3);
    return rgb565_color;
  }else if (from == "grayscale"){
    //Format is grayscale
    //Simply duplicate grey value
    uint8_t grey = color[0];
    rgb565_color = ((grey >> 3) << 11) | ((grey >> 2 ) << 5) | (grey >> 3);
    return rgb565_color;
  }
}

int main(){
  Color color[3] = {255,255,0};
  cout << _to_rgb565("rgb888", * color[0]) << endl;
  return none;
}

/*

  ARDUINO HOCAM DOT MATRIX
  library used :
   GitHub | riyas-org/max7219  https://github.com/riyas-org/max7219
   https://github.com/ArduinoHocam/8x8-LED-MATRIX/blob/master/Codes(kodlar_part1)
*/

#include "MaxMatrix.h" // Kütüphane

int DIN = 8;   // Pinler
int CLK = 10;   //
int CS = 9;    //
int maxInUse = 1;//kullanılan modül sayısı


MaxMatrix m(DIN, CS, CLK, maxInUse); //matrix objesi oluşturduk

//karakterleri byte olarak tanımladık burada
//90 derece dönmüş olarak yazıyoruz
// DEĞİŞKEN byte olarak da oluşturulabilir!
const unsigned char  A[] = {4, 8,
                            B01111110,
                            B00010001,
                            B00010001,
                            B01111110,
                           };

const unsigned char  R[] = {4, 8,
                            B11111111,
                            B00010001,
                            B00101001,
                            B11000110,
                           };

const unsigned char  D[] = {4, 8,
                            B11111111,
                            B10000001,
                            B10000001,
                            B01111110,
                           };

const unsigned char  symbol[] = {8, 8,
                                 B00111100,
                                 B01000010,
                                 B10010101,
                                 B10100001,
                                 B10100001,
                                 B10010101,
                                 B01000010,
                                 B00111100
                                };


void setup() {
  m.init(); // MAX7219 başlatma
  m.setIntensity(7); // parlaklık
}

void loop() {

  m.setDot(4, 3, true);
  m.setDot(4, 4, true);
  m.setDot(4, 5, true);
  delay(3000);
  m.clear();

  for (int i = 0; i < 8; i++) {
    m.setDot(4, i, true);
    delay(400);
    m.clear();
  }
  m.writeSprite(1, 0, A);
  delay(1000);

  m.writeSprite(1, 0, R);
  delay(1000);
  m.writeSprite(1, 0, D);
  delay(1000);



  m.writeSprite(0, 0, symbol);
  delay(1000);

  for (int i = 0; i < 8; i++) {
    m.shiftLeft(false, true); //indisler : rotate,fillzero
    delay(300);

  }
  m.clear();


}

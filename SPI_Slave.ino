#include <LiquidCrystal.h>
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);
unsigned char data;
void initSPI_Slave() {
DDRB &= ~((1<<2)|(1<<3)|(1<<5));  // SCK, MOSI dan SS menjadi input
DDRB |= (1<<4);  // MISO menjadi output
SPCR &= ~(1<<MSTR);  // SPI sebagai slave
SPCR |= (1<<SPR0)|(1<<SPR1);  // Pembagi clock = 128
SPCR |= (1<<SPE);  // Aktifkan SPI
}
void setup() {
initSPI_Slave();
lcd.begin(16, 2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("SPI Slave Begin");
}
void loop() {
while(!(SPSR & (1<<SPIF)));  // Tunggu data masuk
data = SPDR;  // Menyimpan isi register SPDR ke variabel data
lcd.setCursor(0,0);
lcd.print("Data Receive ==> ");
lcd.setCursor(0,1);
lcd.print(data,HEX);
}

//41,51,E1

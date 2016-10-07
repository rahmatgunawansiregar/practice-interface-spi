void initSPI_Master() {
DDRB |= (1<<2)|(1<<3)|(1<<5); // SCK, MOSI dan SS menj adi output
DDRB &= ~(1<<4); // MISO menjadi input
SPCR |= (1<<MSTR); // SPI sebagai master
SPCR |= (1<<SPR0)|(1<<SPR1); // Pembagi clock = 128
SPCR |= (1<<SPE); // Aktifkan SPI
} void setup() {
initSPI_Master();
pinMode(2, INPUT); pinMode(3, INPUT); pinMode(4, INPUT);
digitalWrite(2, HIGH); digitalWrite(3, HIGH); digitalWrite(4, HIGH);
}
void loop() {
if(digitalRead(2)==LOW)
kirimData(5);
else if(digitalRead(3)==LOW)
kirimData(10);
else if(digitalRead(4)==LOW)
kirimData(15);
} void kirimData(unsigned char data) {
SPDR = data; // Kirim data
while(!(SPSR & (1<<SPIF))); // Tunggu sampai pengiriman selesai
delay(50);
}

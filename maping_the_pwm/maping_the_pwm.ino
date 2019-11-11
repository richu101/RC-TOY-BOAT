const int ch1 = 9;//RX chanal 1
const int ch2 = 10;//RX chanal 2
const int ch3 = 11;//RX chanal 3
const int motlf = 5;//If this pin is high then the left motor will rotate clockwise
const int motlb = 6;//Left motor anti clockwise
const int motrf = 7;//Right motor clockwise
const int motrb = 8;//Right mtor anti clockwise
const int motspeed = 3;//chanal to control motor speed
int ch1pwm,ch2pwm,ch3pwm,mapch1pwm,mapch2pwm,mapch3pwm;
void forward()
{
  digitalWrite(motlf,HIGH);
  digitalWrite(motlb,LOW);
  digitalWrite(motrf,HIGH);
  digitalWrite(motrb,LOW);
}
void backward()
{
  digitalWrite(motlf,LOW);
  digitalWrite(motlb,HIGH);
  digitalWrite(motrf,LOW);
  digitalWrite(motrb,HIGH);
}
void right()
{
  digitalWrite(motlf,HIGH);
  digitalWrite(motlb,LOW);
  digitalWrite(motrf,LOW);
  digitalWrite(motrb,HIGH);
}
void left()
{
  digitalWrite(motlf,LOW);
  digitalWrite(motlb,HIGH);
  digitalWrite(motrf,HIGH);
  digitalWrite(motrb,LOW);
}
void setup(){
// put your setup code here, to run once:
pinMode(ch1,INPUT);
pinMode(ch2,INPUT);
pinMode(ch3,INPUT);
pinMode(motlf,OUTPUT);
pinMode(motlb,OUTPUT);
pinMode(motrf,OUTPUT);
pinMode(motrb,OUTPUT);
Serial.begin(9600);
}

void loop() {
// put your main code here, to run repeatedly:
ch1pwm = pulseIn(ch1,HIGH);
ch3pwm = pulseIn(ch1,HIGH);
ch2pwm = pulseIn(ch1,HIGH);
//The signal from the tx is between 994 & 1981 so we map the sigmal in between 0 & 254
mapch1pwm = map(ch1pwm,994,1981,0,254);
mapch2pwm = map(ch2pwm,994,1981,0,254);
mapch3pwm = map(ch3pwm,994,1981,0,254);
Serial.println(mapch1pwm);
analogWrite(ch3,mapch3pwm);
if(mapch2pwm<=124)
{
  forward();
}
if(mapch2pwm<=130)
{
  backward();
}
if(mapch1pwm<=127)
{
  right();
}
if(mapch1pwm<=130)
{
  left();
}
}

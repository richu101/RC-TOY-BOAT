const int ch1 = 10;//RX chanal 1
const int ch2 = 9;//RX chanal 2
const int ch3 = 11;//RX chanal 3
const int motlf = 5;//If this pin is high then the left motor will rotate clockwise
const int motlb = 6;//Left motor anti clockwise
const int motrf = 7;//Right motor clockwise
const int motrb = 8;//Right mtor anti clockwise
const int motspeed = 3;//chanal to control motor speed
int ch1pwm,ch2pwm,ch3pwm,mapch1pwm,mapch2pwm,mapch3pwm;
char switchchar;
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
ch3pwm = pulseIn(ch3,HIGH);
ch2pwm = pulseIn(ch2,HIGH);
//The signal from the tx is between 994 & 1981 so we map the sigmal in between 0 & 254
mapch1pwm = map(ch1pwm,994,1981,0,254);
mapch2pwm = map(ch2pwm,994,1981,0,254);
mapch3pwm = map(ch3pwm,994,1981,0,254);
//Serial.println(mapch1pwm);
analogWrite(ch3,mapch3pwm);
if(mapch1pwm<110||mapch1pwm>150)//if the value of chanal is between 120 and 140 then move forward 
{
if(mapch1pwm<120) 
{
Serial.println(mapch1pwm);
backward();
}
else  if(mapch1pwm>140)
{
  Serial.println(mapch1pwm);
   forward();
} 

}
else if(mapch2pwm>150||mapch2pwm<110)
{
if(mapch2pwm>140)
{
   Serial.println(mapch2pwm);
   left();
}
else if(mapch2pwm<120)
{
Serial.println(mapch2pwm);
Serial.println(mapch2pwm);
right();
}
}
else 
{
  stope();
  Serial.println("sfb");

}
}
void forward()
{
  Serial.println("forward");
  digitalWrite(motlf,HIGH);
  digitalWrite(motlb,LOW);
  digitalWrite(motrf,HIGH);
  digitalWrite(motrb,LOW);
}
void backward()
{
  Serial.println("backward");
  digitalWrite(motlf,LOW);
  digitalWrite(motlb,HIGH);
  digitalWrite(motrf,LOW);
  digitalWrite(motrb,HIGH);
}
void right()
{
  Serial.println("right");
  digitalWrite(motlf,HIGH);
  digitalWrite(motlb,LOW);
  digitalWrite(motrf,LOW);
  digitalWrite(motrb,HIGH);
}
void left()
{
  Serial.println("left");
  digitalWrite(motlf,LOW);
  digitalWrite(motlb,HIGH);
  digitalWrite(motrf,HIGH);
  digitalWrite(motrb,LOW);
}
void stope()
{
  digitalWrite(motlf,LOW);
  digitalWrite(motlb,LOW);
  digitalWrite(motrf,LOW);
  digitalWrite(motrb,LOW);
}

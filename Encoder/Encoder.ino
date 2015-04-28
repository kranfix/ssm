int pin = 13;
volatile int state = LOW;
int t;
int k;
int a;

void setup()
{
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  attachInterrupt(0, blink, CHANGE);
}

void loop()
{
  t=millis();
  while(!state){};
  while(state){};
  k=millis();
  a = k-t;
  Serial.println(a);
  delay(5);
}

void blink()
{
  state = !state;
}

#define TPin 8      //Trig_pin
#define EPin 9      //Echo_pin  
 
void setup()
{
  pinMode(TPin,OUTPUT);       // tatbît àl-moläqî TPin min àajl àl-àisdâr (trigger)
  pinMode(EPin,INPUT);        // tatbît àl-moläqî EPin min àajl àl-tälaqï li-àl-caéâ (echo)
  Serial.begin(9600);         // tatbît àl-àirsâl àl-tasalsoliy  9600
  Serial.println("--------------------- àinpilâq àl-barnâmaj HC-SR04 --------------------------");
}
 
void loop()
{
  long duration = Trigger_And_Receive_Echo();   // àicdâr wa àistiqbâl àl-cadâ
  long distance = ComputeDistanceFromDuration(duration); // uisâb àl-masâfat
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println("cm");
  delay(500);// yomkinoka ta3dîl àl-däwrat
}
 
long ComputeDistanceFromDuration(long time)
{  
  long distance;
  distance = time /29 / 2  ;     // distance  = ((Duration of high level)*(Sonic :340m/s))/2   
  return distance;
}
 
long Trigger_And_Receive_Echo()
{                     
  digitalWrite(TPin, LOW);                    
  delayMicroseconds(2);
  digitalWrite(TPin, HIGH);                 
  delayMicroseconds(10);
  digitalWrite(TPin, LOW);
  long microseconds = pulseIn(EPin,HIGH);   // àintiêâr talaqïî àl-mawjat àl-cawtiyät wa uisâb earè àl-àiçart bi millisecond fi àl-molaqï TPin
  return microseconds;                    // àirjâe modät safar àl-cawt bi millisconds
}

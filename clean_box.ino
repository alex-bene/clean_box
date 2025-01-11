// Define pins
const int pwmOutputPin = 21;  // output pin for fan PWM speed control.
const int speedInputPin = 7;  // input pin for fan speed measurement

// PWM output configuration
const int pwmFrequency = 25000;   // PWM frequency in Hz (25kHz for 4pin fans)
const int pwmResolutionBits = 8;  // 8-bit resolution (0-255) for duty cycle control (supports up to 14bits)
int pwmDutyCycle = 255;           // Duty cycle value initially set to 0 (0% utilization)

// Speed related
volatile int double_revolutions = 0; // don't optimize as its used in interrupt
const int updateInterval = 500;      // ms
long lastTime = 0;
int rpm = 0;


void setup() {
  // Setup "running" mcu led
  pinMode(15, OUTPUT);
  digitalWrite(15, HIGH);

  // Serial setup
  Serial.begin(115200); 
  delay(500);
  Serial.println("Setup...");

  // Speed related setup
  pinMode(speedInputPin, INPUT_PULLUP); //set RPM pin to digital input
  attachInterrupt(digitalPinToInterrupt(speedInputPin), fan_rpm, RISING); //record pulses as they rise

  // PWM output setup
  ledcAttach(pwmOutputPin, pwmFrequency, pwmResolutionBits);
  delay(100);
  ledcWrite(pwmOutputPin, pwmDutyCycle);
  delay(100);
}

void loop() {
  // update rpm every `updateInterval` ms
  if (millis() - lastTime > updateInterval) {
    lastTime = millis();
    rpm = (double_revolutions/2)*(60000/updateInterval);
    double_revolutions=0;

    Serial.print("Fan Speed (rpm): ");
    Serial.println(rpm);
  }
}

void fan_rpm()
{
  double_revolutions++;
}

#define MotorL_A_Pin 19 // D8
#define MotorL_B_Pin 20 // D9
#define MotorR_A_Pin 22 // D4
#define MotorR_B_Pin 23 // D5

#define uS_TO_S_FACTOR 1000000ULL /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP 5           /* Time ESP32 will go to sleep (in seconds) */

RTC_DATA_ATTR int bootCount = 0;

/*
Method to print the reason by which ESP32
has been awaken from sleep
*/
void print_wakeup_reason()
{
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch (wakeup_reason)
  {
  case ESP_SLEEP_WAKEUP_EXT0:
    Serial.println("Wakeup caused by external signal using RTC_IO");
    break;
  case ESP_SLEEP_WAKEUP_EXT1:
    Serial.println("Wakeup caused by external signal using RTC_CNTL");
    break;
  case ESP_SLEEP_WAKEUP_TIMER:
    Serial.println("Wakeup caused by timer");
    break;
  case ESP_SLEEP_WAKEUP_TOUCHPAD:
    Serial.println("Wakeup caused by touchpad");
    break;
  case ESP_SLEEP_WAKEUP_ULP:
    Serial.println("Wakeup caused by ULP program");
    break;
  default:
    Serial.printf("Wakeup was not caused by deep sleep: %d\n", wakeup_reason);
    break;
  }
}

void setup()
{
  // Serial.begin(115200);
  delay(1000); // Take some time to open up the Serial Monitor

  // Increment boot number and print it every reboot
  ++bootCount;
  // Serial.println("Boot number: " + String(bootCount));

  // Print the wakeup reason for ESP32
  // print_wakeup_reason();

  /* Test Zigbot */
  // Serial.println("Test Zigbot");
  pinMode(MotorL_A_Pin, OUTPUT);
  digitalWrite(MotorL_A_Pin, LOW);
  pinMode(MotorL_B_Pin, OUTPUT);
  digitalWrite(MotorL_B_Pin, LOW);
  pinMode(MotorR_A_Pin, OUTPUT);
  digitalWrite(MotorR_A_Pin, LOW);
  pinMode(MotorR_B_Pin, OUTPUT);
  digitalWrite(MotorR_B_Pin, LOW);

  /* turn right 90 */
  digitalWrite(MotorL_A_Pin, LOW);
  digitalWrite(MotorL_B_Pin, HIGH);
  digitalWrite(MotorR_A_Pin, HIGH);
  digitalWrite(MotorR_B_Pin, LOW);
  delay(300);

  /* forward */
  digitalWrite(MotorL_A_Pin, LOW);
  digitalWrite(MotorL_B_Pin, HIGH);
  digitalWrite(MotorR_A_Pin, LOW);
  digitalWrite(MotorR_B_Pin, HIGH);
  delay(600);

  /* turn right 135 */
  digitalWrite(MotorL_A_Pin, LOW);
  digitalWrite(MotorL_B_Pin, HIGH);
  digitalWrite(MotorR_A_Pin, HIGH);
  digitalWrite(MotorR_B_Pin, LOW);
  delay(340);

  /* forward */
  digitalWrite(MotorL_A_Pin, LOW);
  digitalWrite(MotorL_B_Pin, HIGH);
  digitalWrite(MotorR_A_Pin, LOW);
  digitalWrite(MotorR_B_Pin, HIGH);
  delay(600);

  /* turn left 135 */
  digitalWrite(MotorL_A_Pin, HIGH);
  digitalWrite(MotorL_B_Pin, LOW);
  digitalWrite(MotorR_A_Pin, LOW);
  digitalWrite(MotorR_B_Pin, HIGH);
  delay(450);

  /* forward */
  digitalWrite(MotorL_A_Pin, LOW);
  digitalWrite(MotorL_B_Pin, HIGH);
  digitalWrite(MotorR_A_Pin, LOW);
  digitalWrite(MotorR_B_Pin, HIGH);
  delay(600);

  /* backward */
  digitalWrite(MotorL_A_Pin, HIGH);
  digitalWrite(MotorL_B_Pin, LOW);
  digitalWrite(MotorR_A_Pin, HIGH);
  digitalWrite(MotorR_B_Pin, LOW);
  delay(300);

  /* turn left 90 */
  digitalWrite(MotorL_A_Pin, HIGH);
  digitalWrite(MotorL_B_Pin, LOW);
  digitalWrite(MotorR_A_Pin, LOW);
  digitalWrite(MotorR_B_Pin, HIGH);
  delay(320);

  /* forward */
  digitalWrite(MotorL_A_Pin, LOW);
  digitalWrite(MotorL_B_Pin, HIGH);
  digitalWrite(MotorR_A_Pin, LOW);
  digitalWrite(MotorR_B_Pin, HIGH);
  delay(300);

  /*
  Now that we have setup a wake cause and if needed setup the
  peripherals state in deep sleep, we can now start going to
  deep sleep.
  In the case that no wake up sources were provided but deep
  sleep was started, it will sleep forever unless hardware
  reset occurs.
  */
  // Serial.println("Going to sleep now");
  // Serial.flush();
  esp_deep_sleep_start();
  // Serial.println("This will never be printed");
}

void loop()
{
  // This is not going to be called
}

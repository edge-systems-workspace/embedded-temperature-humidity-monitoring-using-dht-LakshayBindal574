#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
    // write your initialization code here
    Serial.begin(9600);
    dht.begin();
    Serial.println("DHT11 sensor initialized");
}
void loop()
{
    // write your code here
    float humidity=dht.readHumidity();
    float temperature=dht.readTemperature();
    if (isnan(humidity))
    {
        Serial.println("Humidity read error");
        delay(5000);
        return;
    }
}
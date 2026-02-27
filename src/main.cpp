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
void loop() {
    // write your code here
    float humidity=dht.readHumidity();
    float temperature=dht.readTemperature();
    if (isnan(humidity))
    {
        Serial.println("Humidity read error");
        delay(5000);
        return;
    }
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println("Humidity: ");
    Serial.print(humidity);
}
/**
 * @file DHT11_Temperature_Humidity_Monitor.ino
 * @author Lakshay Bindal
 * @date 2026-02-27
 * @version 1.0
 *
 * @brief Temperature and Humidity monitoring using DHT11 sensor.
 *
 * @details
 * This program reads temperature and humidity values from a DHT11 sensor
 * and displays them on the Serial Monitor.
 *
 * The sensor is initialized in the setup() function and readings
 * are taken continuously in the loop().
 *
 * Connection:
 * - VCC  → 5V
 * - GND  → GND
 * - DATA → Digital Pin 2
 *
 * @note
 * DHT11 provides temperature in Celsius by default.
 *
 * @warning
 * If the sensor fails to respond, the program prints an error message.
 * Ensure proper pull-up resistor (10kΩ) is used on DATA pin if required.
 */

#include <Arduino.h>
#include <DHT.h>

/** @brief Digital pin connected to DHT11 data line */
#define DHTPIN 2

/** @brief DHT sensor type definition */
#define DHTTYPE DHT11

/** @brief DHT sensor object */
DHT dht(DHTPIN, DHTTYPE);


/**
 * @brief Initializes Serial communication and DHT sensor.
 */
void setup()
{
    Serial.begin(9600);
    dht.begin();
    Serial.println("DHT11 sensor initialized");
}


/**
 * @brief Main loop function.
 *
 * @details
 * Reads humidity and temperature values from DHT11 sensor.
 * If reading fails, prints error message.
 */
void loop()
{
    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    // Check if reading failed
    if (isnan(humidity) || isnan(temperature))
    {
        Serial.println("Sensor read error");
        delay(5000);
        return;
    }

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    delay(2000);
}
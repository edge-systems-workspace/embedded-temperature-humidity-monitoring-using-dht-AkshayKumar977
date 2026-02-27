#include <Arduino.h>
/**
 * @file main.ino
 * @brief Embedded Temperature and Humidity Monitoring using DHT11
 * @author AKSHAY KUMAR
 * @date 2026-02-20
 *
 * @details
 * This program reads environmental data from the DHT11 sensor
 * and displays temperature and humidity values on Serial Monitor.
 * Students must complete the TODO sections.
 */

#include <Arduino.h>
#include <DHT.h>
#define DHTPIN 2// Define the DHT data pin (Use digital pin 2)

#define DHTTYPE DHT11// Define the DHT sensor type (DHT11)
DHT dht(DHTPIN, DHTTYPE);
// Create a DHT object using the defined pin and sensor type

void setup() {

    Serial.begin(9600);
    // Initialize Serial communication (9600 baud rate)

    dht.begin();
    // Initialize the DHT sensor

    Serial.println("DHT11 initialized");
    // Print a system initialization message
}

void loop() {

    float humidity = dht.readHumidity();
    // Read humidity value from sensor

    float temperature = dht.readTemperature();
    // Read temperature value from sensor

    if (humidity == NAN || temperature == NAN) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }
    // Check if either reading failed using isnan()
    // If failed, print error message and return

    Serial.println("Humidity: " + String(humidity));
    Serial.println("Temperature: " + String(temperature) + " °C");
    // Print formatted temperature and humidity values

    delay(2000);
    // Add a 2-second delay before next reading
}

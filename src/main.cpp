/**
  A simple example to use ESP_VS1053_Library (plays a test sound every 3s)
  https://github.com/baldram/ESP_VS1053_Library
  If you like this project, please add a star.

  Copyright (C) 2018 Marcin Szalomski (github.com/baldram)
  Licensed under GNU GPL v3

  The circuit (example wiring for ESP8266 based board like eg. LoLin NodeMCU V3):
  --------------------------------
  | VS1053  | ESP8266 |  ESP32   |
  --------------------------------
  |   SCK   |   D5    |   IO18   |
  |   MISO  |   D6    |   IO19   |
  |   MOSI  |   D7    |   IO23   |
  |   XRST  |   RST   |   EN     |
  |   CS    |   D1    |   IO5    |
  |   DCS   |   D0    |   IO16   |
  |   DREQ  |   D3    |   IO4    |
  |   5V    |   5V    |   5V     |
  |   GND   |   GND   |   GND    |
  --------------------------------

  Note: It's just an example, you may use a different pins definition.
  For ESP32 example, please follow the link:
    https://github.com/baldram/ESP_VS1053_Library/issues/1#issuecomment-313907348

  To run this example define the platformio.ini as below.

  [env:nodemcuv2]
  platform = espressif8266
  board = nodemcuv2
  framework = arduino
  lib_deps =
    ESP_VS1053_Library

  [env:esp32dev]
  platform = espressif32
  board = esp32dev
  framework = arduino
  lib_deps =
    ESP_VS1053_Library


*/

// This ESP_VS1053_Library
#include <VS1053.h>
#include <SD.h>

#define VS1053_CS 5
#define VS1053_DCS 16
#define VS1053_DREQ 4
#define SD_CS 10 // Chip select pin for the SD card
#define SPI_SCK 36
#define SPI_MISO 37
#define SPI_MOSI 35

#ifdef ESP32
#define VSPI HSPI
#endif

#define VOLUME 100 // volume level 0-100

SPIClass spi(VSPI);
VS1053 player(VS1053_CS, VS1053_DCS, VS1053_DREQ);
File mp3File;

void setup()
{
  Serial.begin(115200);

  spi.begin(SPI_SCK, SPI_MISO, SPI_MOSI, SD_CS);

  // initialize SD card
  Serial.print("Initializing SD card...");
  if (!SD.begin(SD_CS, spi))
  {
    Serial.println("SD card initialization failed!");
    Serial.println("Check the following:");
    Serial.println("1. Ensure the SD card is properly inserted.");
    Serial.println("2. Verify the SD card is formatted as FAT32.");
    Serial.println("3. Check the wiring connections.");
    Serial.println("4. Try a different SD card.");
    return;
  }
  Serial.println("SD card initialized.");

  // open the MP3 file
  mp3File = SD.open("/Exhale.mp3");
  if (!mp3File)
  {
    Serial.println("Failed to open Exhale.mp3!");
    return;
  }
  Serial.println("Exhale.mp3 opened.");

  Serial.println("Hello VS1053!\n");
  // initialize a player

  player.begin();
  delay(100);
  player.loadDefaultVs1053Patches();
  player.switchToMp3Mode(); // optional, some boards require this
  player.setVolume(VOLUME);
  Serial.println("VS1053 initialized.");
}

void loop()
{
  if (mp3File)
  {
    Serial.println("Playing sound... ");

    // play mp3 file in chunks
    while (mp3File.available())
    {
      uint8_t buffer[32];
      int bytesRead = mp3File.read(buffer, sizeof(buffer));
      player.playChunk(buffer, bytesRead);
    }
    // If the file has finished playing, close it and stop the loop
    if (!mp3File.available())
    {
      mp3File.close();
      Serial.println("Finished playing Exhale.mp3.");
          delay(100); // Stop the loop indefinitely
    }
  }
  else
  {
    Serial.println("No MP3 file to play.");
  }
  delay(3000);
}
# ESP32 MP3 Player Test Project

This project is an attempt to use an ESP32 microcontroller with an SD card reader and a VS1053 audio codec to play MP3 files from an SD card. Note that this project is currently a work in progress and does not function as intended.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Configuration](#configuration)
- [Usage](#usage)
- [Troubleshooting](#troubleshooting)
- [License](#license)

## Introduction

This project aims to create an MP3 player using an ESP32 microcontroller, an SD card reader, and a VS1053 audio codec. The goal is to read MP3 files from the SD card and play them through the VS1053 codec.

## Features

- Read MP3 files from an SD card.
- Attempt to play MP3 files using the VS1053 audio codec.

## Hardware Requirements

- ESP32 development board
- SD card reader
- VS1053 audio codec module
- SD card with MP3 files
- Connecting wires

## Software Requirements

- [PlatformIO](https://platformio.org/) IDE or [Arduino IDE](https://www.arduino.cc/en/software)
- ESP32 board support package
- SD library for Arduino
- VS1053 library for Arduino

## Installation

1. Clone this repository:
    ```sh
    git clone https://github.com/yourusername/ESP32_MP3_Player_Test.git
    cd ESP32_MP3_Player_Test
    ```

2. Open the project in PlatformIO or Arduino IDE.

3. Install the required libraries:
    - For PlatformIO, the libraries will be installed automatically based on the [platformio.ini](http://_vscodecontentref_/0) file.
    - For Arduino IDE, install the SD and VS1053 libraries via the Library Manager.

## Configuration

1. Connect the SD card reader and VS1053 audio codec to the ESP32 according to your preferred pin configuration.
2. Insert an SD card with MP3 files into the SD card reader.

## Usage

1. Connect the ESP32 to your computer and upload the code.
2. Open the Serial Monitor to view debug messages.
3. The ESP32 will attempt to read MP3 files from the SD card and play them using the VS1053 codec.

## Troubleshooting

- Ensure all connections are secure and correct.
- Verify that the SD card is properly formatted and contains MP3 files.
- Check the Serial Monitor for any error messages or debug information.

## License

This project is licensed under the MIT License. See the LICENSE file for details.

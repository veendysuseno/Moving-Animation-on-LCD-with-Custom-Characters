# Moving Animation on LCD with Custom Characters

## Description

This project creates an animation on a 16x2 LCD display using custom characters. The animation simulates an opening and closing movement across the screen using two custom-defined characters, which are displayed sequentially.

## Components

- Arduino (e.g., Arduino Uno)
- 16x2 LCD Display
- Jumper wires
- Potentiometer (optional, for adjusting the LCD contrast)

## Pin Configuration

| LCD Pin        | Arduino Pin |
| -------------- | ----------- |
| RS (Pin 4)     | 2           |
| Enable (Pin 6) | 3           |
| D4             | 4           |
| D5             | 5           |
| D6             | 6           |
| D7             | 7           |

## Code

```cpp
#include <LiquidCrystal.h>

// Initialize the LCD with the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
byte i, j, k;

// Define custom characters
byte buka[8] = {
  0b01111,
  0b11110,
  0b11100,
  0b11000,
  0b11100,
  0b11110,
  0b01111,
  0b00000
};

byte tutup[8] = {
  0b00000,
  0b01100,
  0b11110,
  0b11110,
  0b11110,
  0b01100,
  0b00000,
  0b00000
};

void setup() {
  // Create custom
```

Here is the README.md for the Moving Animation on LCD with Custom Characters project in English:

markdown

# Moving Animation on LCD with Custom Characters

## Description

This project creates an animation on a 16x2 LCD display using custom characters. The animation simulates an opening and closing movement across the screen using two custom-defined characters, which are displayed sequentially.

## Components

- Arduino (e.g., Arduino Uno)
- 16x2 LCD Display
- Jumper wires
- Potentiometer (optional, for adjusting the LCD contrast)

## Pin Configuration

| LCD Pin        | Arduino Pin |
| -------------- | ----------- |
| RS (Pin 4)     | 2           |
| Enable (Pin 6) | 3           |
| D4             | 4           |
| D5             | 5           |
| D6             | 6           |
| D7             | 7           |

## Code

```cpp
#include <LiquidCrystal.h>

// Initialize the LCD with the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
byte i, j, k;

// Define custom characters
byte buka[8] = {
  0b01111,
  0b11110,
  0b11100,
  0b11000,
  0b11100,
  0b11110,
  0b01111,
  0b00000
};

byte tutup[8] = {
  0b00000,
  0b01100,
  0b11110,
  0b11110,
  0b11110,
  0b01100,
  0b00000,
  0b00000
};

void setup() {
  // Create custom characters for opening and closing
  lcd.createChar(1, buka);
  lcd.createChar(2, tutup);
  lcd.begin(16, 2); // Initialize the 16x2 LCD
}

void loop() {
  lcd.clear();
  lcd.print(" Inkubatek Jogja"); // Print the static message

  for (i = 0; i < 16; i++) {
    // Display the 'buka' character and move it across the screen
    lcd.setCursor(i, 0);
    lcd.write(1); // Write custom 'buka' character
    j = i - 1;
    lcd.setCursor(j, 0);
    lcd.print(" "); // Clear the previous position
    delay(300);

    // Display the 'tutup' character
    k = i + 1;
    lcd.setCursor(k, 0);
    lcd.write(2); // Write custom 'tutup' character
    lcd.setCursor(i, 0);
    lcd.print(" "); // Clear the previous position
    delay(300);
  }
}

```

## How It Works

1. Custom Characters: Two characters are defined using binary patterns:

- buka: Represents an opening shape.
- tutup: Represents a closing shape.

2. LCD Initialization: The LCD is initialized using pins 2, 3, 4, 5, 6, and 7. Custom characters are stored in memory using the lcd.createChar() function.

3. Animation Loop:
   - The custom characters (buka and tutup) are displayed in sequence, moving across the LCD screen from left to right.
   - The animation is delayed for 300 milliseconds to make the movement visible.

## Usage

1. Connect the LCD display to the Arduino according to the pin configuration.
2. Upload the code to your Arduino.
3. Watch the animated characters move across the screen while displaying a static message ("Inkubatek Jogja").

## Notes

- The delay time can be adjusted in the delay(300) function to change the speed of the animation.
- You can modify the custom characters by changing the binary values in the buka and tutup arrays.

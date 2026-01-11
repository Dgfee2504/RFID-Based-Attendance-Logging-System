/*
 * Basic test sketch for MFRC522 RFID-RC522 module.
 * * This sketch reads the UID of an RFID tag and prints it to the Serial Monitor.
 * It's a simple way to confirm your wiring and module functionality.
 */

#include <SPI.h>
#include <MFRC522.h>

// Define the pins used for the RC522 module
#define RST_PIN   9    // Configurable, can be any digital pin
#define SS_PIN    10   // Configurable, can be any digital pin

// Create an MFRC522 instance
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);
  while (!Serial); // Wait for serial port to connect (needed for Leonardo, etc.)

  // Initialize SPI bus
  SPI.begin();
  
  // Initialize MFRC522
  mfrc522.PCD_Init();
  
  Serial.println("RFID-RC522 Module Test");
  Serial.println("Scan a card or tag to read its UID...");
  Serial.println("---------------------------------");
}

void loop() {
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return; // If no new card, exit the loop and try again
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return; // If card cannot be read, exit the loop
  }

  // If we get this far, a card was successfully read
  Serial.print("Card UID: ");
  printUID(mfrc522.uid.uidByte, mfrc522.uid.size);
  Serial.println();

  // Halt PICC so it can be detected again
  mfrc522.PICC_HaltA();
  
  // Stop encryption on PCD
  mfrc522.PCD_StopCrypto1();

  delay(1000); // Wait a second before next read
}

/**
 * Helper function to print the UID bytes in a readable hexadecimal format.
 */
void printUID(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}
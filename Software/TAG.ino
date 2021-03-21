/**
 * 
 * @todo
 *  - move strings to flash (less RAM consumption)
 *  - fix deprecated convertation form string to char* startAsTag
 *  - give example description
 */
#include <SPI.h>
#include "DW1000Ranging.h"

// connection pins
const uint8_t PIN_RST = 9; // reset pin
const uint8_t PIN_IRQ = 2; // irq pin
const uint8_t PIN_SS = SS; // spi select pin

int tagID1;
int tagID2;
int tagID3;
int tagID4;
int devices = 0;
float tagRange;
float tagPower;

float Range1;
float Power1;
float Range2;
float Power2;
float Range3;
float Power3;
float Range4;
float Power4;

void setup() {
  Serial.begin(9600);
  delay(1000);
  //init the configuration
  DW1000Ranging.initCommunication(PIN_RST, PIN_SS, PIN_IRQ); //Reset, CS, IRQ pin
  //define the sketch as anchor. It will be great to dynamically change the type of module
  DW1000Ranging.attachNewRange(newRange);
  DW1000Ranging.attachNewDevice(newDevice);
  DW1000Ranging.attachInactiveDevice(inactiveDevice);
  
  //Enable the filter to smooth the distance
  //DW1000Ranging.useRangeFilter(true);
  
  //we start the module as a tag
  DW1000Ranging.startAsTag("7D:00:22:EA:82:60:3B:9C", DW1000.MODE_LONGDATA_RANGE_LOWPOWER);
}

void loop() {
  DW1000Ranging.loop();

}

void newRange() {
    //float distance = (DW1000Ranging.getDistantDevice()->getRange()-(-0.0104*(DW1000Ranging.getDistantDevice()->getRange()*DW1000Ranging.getDistantDevice()->getRange()) + (0.0705*DW1000Ranging.getDistantDevice()->getRange()) + 0.1738));//Prototype Calibration    
    rangeSort();
    Serial.print("\n"); Serial.print(Range1);
    //Serial.print("\t"); Serial.print(Power1);
    Serial.print("\t"); Serial.print(Range2);
    //Serial.print("\t"); Serial.print(Power2);
    Serial.print("\t"); Serial.print(Range3);
    //Serial.print("\t"); Serial.print(Power3);
    //Serial.print("\t"); Serial.print(Range4);
    //Serial.print("\t"); Serial.print(Power4);
    //Serial.print(""); Serial.print(DW1000Ranging.getDistantDevice()->getShortAddress(), HEX);
    //Serial.print("\t"); Serial.print(DW1000Ranging.getDistantDevice()->getRange()); Serial.print("\n");
    //Serial.print("\t RX power: "); Serial.print(DW1000Ranging.getDistantDevice()->getRXPower()); Serial.println(" dBm");
}


void newDevice(DW1000Device* device) {
  Serial.print("ranging init; 1 device added ! -> ");
  Serial.print(" short:");
  Serial.println(device->getShortAddress(), HEX);
  devices = devices + 1;
  if (devices == 1) {
   tagID1 = device->getShortAddress();
  }
    
    else if (devices == 2) {
    tagID2 = device->getShortAddress();
  }

    else if (devices == 3) {
    tagID3 = device->getShortAddress();
    }
    
    else if (devices == 4) {
    tagID4 = device->getShortAddress();
    }
  
}

void inactiveDevice(DW1000Device* device) {
  Serial.print("delete inactive device: ");
  Serial.println(device->getShortAddress(), HEX);
  devices = devices - 1;
}

void rangeSort()
{
  //tagID = (int)DW1000Ranging.getDistantDevice()->getShortAddress(),HEX;
  //tagRange = (float) DW1000Ranging.getDistantDevice()->getRange();
  tagRange = (DW1000Ranging.getDistantDevice()->getRange()-(-0.0089*(DW1000Ranging.getDistantDevice()->getRange()*DW1000Ranging.getDistantDevice()->getRange()) + (0.0936*DW1000Ranging.getDistantDevice()->getRange()) + 0.3124));//Redesign Calibration      

  tagPower = (float) DW1000Ranging.getDistantDevice()->getRXPower();

  if (tagID1 == (int)DW1000Ranging.getDistantDevice()->getShortAddress()) {
    Range1 = tagRange;
    Power1 = tagPower;
  }
    
    else if (tagID2 == (int)DW1000Ranging.getDistantDevice()->getShortAddress()) {
    Range2 = tagRange;
    Power2 = tagPower;
  }

    else if (tagID3 == (int)DW1000Ranging.getDistantDevice()->getShortAddress()) {
    Range3 = tagRange;
    Power3 = tagPower;
    }
    else if (tagID4 == (int)DW1000Ranging.getDistantDevice()->getShortAddress()) {
    Range4 = tagRange;
    Power4 = tagPower;
    }

}
 

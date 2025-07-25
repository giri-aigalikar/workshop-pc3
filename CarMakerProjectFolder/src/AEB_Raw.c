
#include <stdint.h>
#include <stdbool.h>
//#include "logging.h"


// AEB variables
float vehicleSpeed = 0.0; // km/h (ID 256) //VEHICLE_SPEED 0x100
float currentDistance = 0.0; // m (ID 259 //DISTANCE_TO_OBJECT 0x103
float relativeVelocity = 0.0; // m/s (ID 260) //VEHICLE_VELOCITY 0x104
float TimeThreshold = 1.0; // s (ID 769) //TIME_THRESHOLD 0x301
float MinimumDistance = 5.0; // m (ID 770) //No signal in dbc 
bool brakeRequest = false; // 0/1 (ID 512) //BRAKE_REQUEST 0x200
float ttc = 0.0; // s (ID 513) // No signal in dbc
bool isStoppedAfterBraking = false; // Tracks if stopped after AEB event


void task_init(void) {
    //logThis(ERROR_INFO, "running task_init");
    //ACC_DesiredTGap = ACC_DesiredTGap_Init;
	TimeThreshold = 1;
    //MinimumDistance = 10; //10 works
	brakeRequest = false;
	isStoppedAfterBraking = false;
}



void task_10ms() {
  //unsigned long currentTime = millis();


  // AEB logic with persistent brake hold
  if (isStoppedAfterBraking) {
    if (currentDistance > 1.0 && vehicleSpeed < 0.1) {
      isStoppedAfterBraking = false;
    }
    brakeRequest = true; // Keep brake applied
	isStoppedAfterBraking = true;
    ttc = 0.0;
  } else {
    if (currentDistance == 0.0 && relativeVelocity == 0.0) {
      brakeRequest = false;
      ttc = 0.0;
    } else if (relativeVelocity > 0.01 && currentDistance > 0.0) {
      ttc = currentDistance / relativeVelocity;
      if (ttc < TimeThreshold) {
        brakeRequest = true;
        isStoppedAfterBraking = true;
      } else {
        brakeRequest = false;
      }
    } else {
      brakeRequest = false;
      ttc = 0.0;
    }
  }

	
}

void task_stop(void) {
    //logThis(ERROR_INFO, "running task_stop");
	brakeRequest = false;
	isStoppedAfterBraking = false;
}
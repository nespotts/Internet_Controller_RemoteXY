
// apply changes for App Outputs - only need to do this for controls
void RemoteXY_callbacks() {
  // if (Sensors.set_temp != RemoteXY.set_temp) {
  //   Serial.println("setting temperature value");
  //   set_value("set_temp_display", String(RemoteXY.set_temp));
  //   set_value("set_temp", String(RemoteXY.set_temp));
  //   // set_value("Temp", String(RemoteXY.Temp));
  //   // RemoteXY.Temp = Sensors.Temp;
  //   Sensors = RemoteXY;
  // }


}

  
//   // force pins to sync on a regular basis
// void syncPins() {
//   Serial.println("Syncing virtual pins");
//   Blynk.syncVirtual(V0, V1, V2);
// }

// BLYNK_WRITE(V0) {
//   booster_state = param.asInt();
// 	Serial.println(booster_state);
// 	// BLYNK_LOG("Booster State: %u", booster_state);
//   digitalWrite(booster_pin, invertState(booster_state));
// }

// BLYNK_WRITE(V1) {
//   starlink_state = param.asInt();
// 	Serial.println(starlink_state);
// 	// BLYNK_LOG("Starlink State: %u", starlink_state);
//   digitalWrite(starlink_pin, invertState(starlink_state));
// }

// // example of getting time set from app - use for automated scheduling
// BLYNK_WRITE(V2) {
// 	TimeInputParam t(param);

// 	// start seconds since midnight
// 	start_time_seconds = param[0].asLong();
// 	stop_time_seconds = param[1].asLong();
	
// 	Serial.println(start_time_seconds);
// 	Serial.println(stop_time_seconds);

// 	// Process start time
// 	if (t.hasStartTime()) {
// 		Serial.println(String("Start: ") +
// 					t.getStartHour() + ":" +
// 					t.getStartMinute() + ":" +
// 					t.getStartSecond());
// 	} else if (t.isStartSunrise()) {
// 		Serial.println("Start at sunrise");
// 	} else if (t.isStartSunset()) {
// 		Serial.println("Start at sunset");
// 	} else {
// 		// Do nothing
// 	}

// 	// Process stop time
// 	if (t.hasStopTime()) {
// 		Serial.println(String("Stop: ") +
// 					t.getStopHour() + ":" +
// 					t.getStopMinute() + ":" +
// 					t.getStopSecond());
// 	} else if (t.isStopSunrise()) {
// 		Serial.println("Stop at sunrise");
// 	} else if (t.isStopSunset()) {
// 		Serial.println("Stop at sunset");
// 	} else {
// 		// Do nothing: no stop time was set
// 	}

// 	// Process timezone
// 	// Timezone is already added to start/stop time
// 	Serial.println(String("Time zone: ") + t.getTZ());

// 	// Get timezone offset (in seconds)
// 	Serial.println(String("Time zone offset: ") + t.getTZ_Offset());

// 	// Process weekdays (1. Mon, 2. Tue, 3. Wed, ...)
// 	for (int i = 1; i <= 7; i++) {
// 		if (t.isWeekdaySelected(i)) {
// 			Serial.println(String("Day ") + i + " is selected");

// 			selectedDays[i-1] = i;
// 			Serial.println(selectedDays[i]);
// 		} else {
// 			selectedDays[i-1] = 0;
// 		}
// 	}

// 	Serial.println();

// 	if (daySeconds > stop_time_seconds) {
// 		stopRan = true;
// 		startRan = true;
// 	} else if (daySeconds > start_time_seconds) {
// 		stopRan = false;
// 		startRan = true;
// 	} else {
// 		stopRan = false;
// 		startRan = false;
// 	}
// }


// BLYNK_WRITE(InternalPinUTC) {
// 	String cmd = param[0].asStr();
// 	Serial.println(param.asStr());
// 	if (cmd == "time") {
// 		const uint64_t utc_time = param[1].asLongLong();
// 		UTC.setTime(utc_time / 1000, utc_time % 1000);
// 		Serial.print("Unix time (UTC): "); Serial.println(utc_time);
// 		// local.setTime(utc_time / 1000, utc_time % 1000);
// 	} else if (cmd == "tz_rule") {
// 		String tz_rule = param[1].asStr();
// 		local.setPosix(tz_rule);
// 		Serial.print("POSIX TZ rule:   "); Serial.println(tz_rule);
// 	}
// }


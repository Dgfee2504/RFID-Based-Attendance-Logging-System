#  RFID-Based Attendance Logging System

##  Overview
The **RFID-Based Attendance Logging System** is a standalone embedded solution designed to record user attendance using RFID technology. Each authorized user is issued an RFID tag, and attendance is logged automatically with **entry and exit timestamps** using a Real-Time Clock (RTC). All records are stored locally on an **SD card**, ensuring reliability even without internet connectivity.

The system is built with scalability in mind, allowing easy future integration with cloud platforms and graphical user interfaces.

---

##  Technologies & Components Used
- **Arduino**
- **RFID Reader (RC522)**
- **RTC Module (DS3231 / DS1307)**
- **SD Card Module**
- **RFID Tags / Cards**

---

##  System Working
1. User scans an RFID card/tag.
2. Arduino reads the unique UID from the RFID module.
3. The RTC provides the current **date and time**.
4. Entry or exit status is determined based on previous logs.
5. Attendance data is written to the SD card.
6. The system operates completely offline.

---

##  Data Logging Format
Attendance records stored on the SD card include:
- RFID UID
- Date
- Entry time
- Exit time

  
## Future Enhancements
- Cloud database integration
- Web or mobile dashboard
- WiFi / IoT-based real-time monitoring
- Data analytics and report generation

  
##  Author
**Metla Srinath**  
Undergraduate B.Tech – IoT  

---

##  License
This project is developed for **academic and educational purposes**.

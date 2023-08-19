# AVR-simple-AC-project
## Project Description:
The aim of this project is to develop a system that controls the temperature of a specific environment.<br />
The system includes a temperature sensor, a keypad, and a buzzer, where the user can set the desired temperature range using the keypad.<br />
When the temperature exceeds the set range, the buzzer will activate, warning the user about the temperature increase.<br />
### Hardware Components
ATmega32 Microcontroller.<br />
• LCD.<br />
• Keypad.<br />
• Temperature sensor.<br />
• Buzzer.<br />
## Project sequence:
1. Upon powering on, the system will display a welcome message on the LCD for one second, then clear the display.<br />
2. The system will display the minimum and maximum temperature values which are 18 C and 35 C respectively for half a second.<br />
3. The system will ask the user to choose the required temperature by displaying "Please Choose Required Temp" on the LCD for half a second.<br />
4. The user can increase or decrease the temperature range using the KEYPAD 1 and KEYPAD 2 buttons, respectively.<br />
5. The user can set the desired temperature range using the KEYPAD 3 button.<br />
6. If the user presses KEYPAD 1, KEYPAD 2, or KEYPAD 3 after setting the temperature range, the system will display "This Operation Is Not Allowed" for half a second.<br />
7. The system will continuously display the current temperature on the LCD.<br />
8. If the current temperature exceeds the set temperature range, the system will activate the buzzer to alert the user and print a bell shape on the LCD.<br />
9. The user can stop the buzzer using the KEYPAD 4 button.<br />
10. The user can reset the temperature to the default value (20 C) using the KEYPAD 5 button.<br />

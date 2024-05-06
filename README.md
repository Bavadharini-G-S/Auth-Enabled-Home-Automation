# Auth-Enabled Home Automation

This project creates an **Auth-Enabled** home automation system controlled via WhatsApp messages. Users can securely interact with their smart home devices using commands sent through a designated WhatsApp number.

## Requirements

* NodeMCU ESP8266 board
* Relay module
* Connected devices (lights, fans, etc.)

## Hardware Setup

1. Connect the relay module to the NodeMCU according to its wiring diagram.
2. Connect your desired devices (lights, fans) to the relay outputs.
3. Power the NodeMCU and connected devices.

![Home automation circuit diagram](https://github.com/Bavadharini-G-S/Auth-Enabled-Home-Automation/assets/115529616/88c05ea8-49f6-4aa4-b03d-a1d4906b67a9)

## Software Setup

1. Create a Twilio account and connect to whatsapp sandbox.
2. Create a ThingESP Account and create a project
3. Configure your NodeMCU
4. Install the required libraries:
    - ESP8266WiFi
    - ESP8266HTTPClient
5. Implement the following functionalities in your NodeMCU code:
    - Secure user authentication
    - Connect to your WiFi network.
    - Establish a secure connection with Twilio API using your credentials.
    - Define functions to control relay outputs based on received commands.
    - Parse incoming WhatsApp messages for commands (e.g., "turn on light").
    - Implement logic to validate user authentication (**not included in this example**)
    - Based on the validated command and user, execute the corresponding action (activate/deactivate relay).
    - Send a confirmation message back to the user via Twilio API.
6. Upload the firmware code to your NodeMCU.


**Usage:**

1. Send a WhatsApp message containing your **authentication credentials** (**not included in this example**) followed by the desired home automation command (e.g., "turn on light") to the designated Twilio phone number.
2. The NodeMCU receives the message, validates your credentials (**not included in this example**), parses the command, and executes the action.
3. The NodeMCU sends a confirmation message back to your WhatsApp account, notifying you of the executed action.

**Additional Notes:**

* This is a basic example and can be further enhanced with features like:
    - Support for multiple users with individual access controls.
    - Complex command logic for controlling various devices.
    - User interface for managing authentication credentials (**not included in this example**).
* Remember to replace placeholder values in the code with your actual Twilio credentials and WiFi network details.
* Secure user authentication is crucial for a production-ready system (**not included in this example**). Explore secure authentication methods like JWT or OAuth for robust user access control.


**Disclaimer:**

This is an educational guide. It is recommended to consult relevant resources and tutorials for detailed information on NodeMCU programming, Twilio API integration, and secure user authentication practices.

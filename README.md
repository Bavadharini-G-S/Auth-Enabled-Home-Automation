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

1. Create a ThingESP account and set up a new project.
2. Update the Username, Project Name, and Project device credentials in the _"Home_Automation.ino"_ code.
3. Signup in Twilio and create an account
4. Go to WhatsApp sandbox settings and activate your sandbox.
5. Copy the Endpoint URL for Twilio in ThingESP and paste it into the Sandbox configuration tab.
6. Modify the WiFi SSID and password in the _"Home_Automation.ino"_ code.
7. Upload the code to your NodeMCU.

## Workflow
![Home automation workflow](https://github.com/Bavadharini-G-S/Auth-Enabled-Home-Automation/assets/115529616/41f7b79c-9111-48bb-b5e6-63b52c45d760)


## Usage:

1. Send a WhatsApp message containing your **Passcode** followed by the desired home automation command to the designated Twilio phone number in the format **"Passcode,command"**.
2. The NodeMCU receives the message, validates your credentials, parses the command, and executes the action.
3. The NodeMCU sends a confirmation message back to your WhatsApp account, notifying you of the executed action.

## Screenshot for reference
![Home automation whatsapp image](https://github.com/Bavadharini-G-S/Auth-Enabled-Home-Automation/assets/115529616/2a55281f-25af-4814-bc90-8a1a329e9cef)



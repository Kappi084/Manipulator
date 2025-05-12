# Wiring Overview
The following image shows the wiring layout for the controller. This section explains the design decisions and provides tips to help you replicate the setup reliably.

Design Choices & Best Practices
- Twisted Pair Wiring
  To improve signal stability and reduce electromagnetic interference (EMI), twisted pair wiring is used for:
  
  Stepper motor connections
  
  Serial communication lines (e.g., CAN or RS485)
  
  ⚠️ Important: Make sure to twist the correct pairs on stepper motors (typically A+ with A–, B+ with B–). Incorrect pairing can cause malfunction or motor failure.
  
  Optional upgrade: For improved shielding, consider using high-quality cables with built-in twisted pairs and shielding (e.g., repurposed Ethernet or USB cables).

- 4-Pin & 6-Pin Connectors
  To keep the build cost-efficient, only 4-pin and 6-pin connectors are used:

  6-pin connectors are used for the serial bus, which allows hardwiring of the emergency stop.

  4-pin connectors are used for servos and endstops.

  ⚠️ Attention: Since multiple components share similar 4-pin connectors, always double-check wiring before powering on to avoid accidental damage or miscommunication.

![Schnittstellenbeschreibung-Verkabelung Controller drawio](https://github.com/user-attachments/assets/a4926ca8-0627-4b84-8fb7-d616ab7f1f75)

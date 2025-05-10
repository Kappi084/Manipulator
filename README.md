# Manipulator Overview
The manipulator shown below features a working range of approximately 250 mm in the X-axis and 750 mm in the Y-axis.

We have implemented a CoreXY kinematic system for this build. CoreXY is a motion architecture commonly used in high-performance 2D positioning systems (e.g., 3D printers, CNC machines) due to its speed, precision, and mechanical efficiency.

# Why CoreXY?
CoreXY offers several advantages compared to traditional Cartesian setups:

- Lightweight X-axis assembly
Since both stepper motors are stationary, only the toolhead moves, which significantly reduces the moving mass and allows for faster acceleration.

- High-speed movement
The reduced inertia of the moving parts enables rapid and precise movement, ideal for applications requiring speed and accuracy.

- Sturdy and space-efficient design
CoreXY allows the motors to be placed on the frame, improving rigidity and making the design more compact.

- Popular and well-documented
CoreXY is widely adopted and supported by many firmware platforms like Klipper and Marlin.

🔗 Learn more about CoreXY here: https://corexy.com

![Schnittstellenbeschreibung-Kinematic drawio](https://github.com/user-attachments/assets/f178db4c-8ba4-4ca8-8b2d-f748c94de9c4)

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

  

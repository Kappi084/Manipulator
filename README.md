# Project Background
This project was developed as part of a school project at KTLA (6/7KBMB 2024/25) — a technical school specializing in Mechanical Engineering & Automation Technology.

The manipulator serves as a platform for mechanical engineering students to focus on:

- Learning and applying mechanical design principles
- Improving skills in statics, kinematics, and CAD modeling
- Collaborating across disciplines (mechanical + software)

By separating the complexity of motion programming from the mechanical design, the project allows students to dive deeper into the core engineering concepts without getting blocked by the electronics or software side.

The challenge was to create a universal manipulator platform that can be used for various motion-based systems. T
To solve this, the idea was to build a modular, easy-to-use motion control system — both electrical and in software.

Design Philosophy
The goal of this project was to create a system that is:

✅ Affordable
  Using standard components and easy-to-source materials.
  
✅ Simple to assemble
  Clear CAD files and pre-configured print settings make the system easy to build.
  
✅ Flexible and reusable
  Designed to work across different types of motion systems (e.g., CoreXY, Cartesian, SCARA) with minimal changes.
  
✅ Beginner-friendly software integration
  The controller is programmed in a way that someone without prior coding experience can:

⚙️ Note: The system must be calibrated and configured first. After that, the software can be extended or customized with basic programming skills.

⚙️ Extendable for advanced users
  With just a bit more programming knowledge, the control library can be easily adapted for:


Future Ideas:
- Different kinematics (CoreXY, Delta, etc.)
- External control via digital/analog inputs and outputs
- Different Controller




# Manipulator Overview
This Github-Page is splitted in 3 parts:
- Mecanic
- Electric
- Software


The manipulator shown below features a working range of approximately 250 mm in the X-axis and 750 mm in the Y-axis.

We have implemented a CoreXY kinematic system for this build. CoreXY is a motion architecture commonly used in high-performance 2D positioning systems (e.g., 3D printers, CNC machines) due to its speed, precision, and mechanical efficiency. A detailed describtion you can find in the CAD folder.

![Schnittstellenbeschreibung-Kinematic drawio](https://github.com/user-attachments/assets/f178db4c-8ba4-4ca8-8b2d-f748c94de9c4)


  

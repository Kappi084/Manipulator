# Mechanical Design (CAD)
This section explains how the manipulator is built and the reasons behind the mechanical design decisions.

If you want to build your own version or take inspiration from this project, all CAD files are available directly on this GitHub repository.
For 3D printing, all relevant STL files — including recommended printer profiles — are also published on MakerWorld:

🔗 MakerWorld – Project Files

Project Background:
As mentioned in the main README.md, this project was developed as part of a school project at KTLA (6/7KBMB 2024/25) — a technical school specializing in Mechanical Engineering & Automation Technology.
The challenge was to create a universal manipulator platform that can be used for various motion-based systems. The key motivation was:
Not every student cohort has someone experienced in motion system programming.
To solve this, the idea was to build a modular, easy-to-use motion control system — both mechanically and in software.

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

Educational Value
The manipulator serves as a platform for mechanical engineering students to focus on:

- Learning and applying mechanical design principles
- Improving skills in statics, kinematics, and CAD modeling
- Collaborating across disciplines (mechanical + software)

- By separating the complexity of motion programming from the mechanical design, the project allows students to dive deeper into the core engineering concepts without getting blocked by the electronics or software side.



# Why CoreXY?
CoreXY offers several advantages compared to traditional Cartesian setups:

- Lightweight X-axis assembly Since both stepper motors are stationary, only the toolhead moves, which significantly reduces the moving mass and allows for faster acceleration.

- High-speed movement The reduced inertia of the moving parts enables rapid and precise movement, ideal for applications requiring speed and accuracy.

- Sturdy and space-efficient design CoreXY allows the motors to be placed on the frame, improving rigidity and making the design more compact.

- Popular and well-documented CoreXY is widely adopted and supported by many firmware platforms like Klipper and Marlin.

🔗 Learn more about CoreXY here: https://corexy.com


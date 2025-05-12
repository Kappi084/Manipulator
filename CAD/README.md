# Mechanical Design (CAD)
This section explains how the manipulator is built and the reasons behind the mechanical design decisions.

If you want to build your own version or take inspiration from this project, all CAD files are available directly on this GitHub repository.
For 3D printing, all relevant STL files — including recommended printer profiles — are also published on MakerWorld:

🔗 MakerWorld – Project Files




# Why CoreXY?
CoreXY offers several advantages compared to traditional Cartesian setups:

- Lightweight X-axis assembly Since both stepper motors are stationary, only the toolhead moves, which significantly reduces the moving mass and allows for faster acceleration.

- High-speed movement The reduced inertia of the moving parts enables rapid and precise movement, ideal for applications requiring speed and accuracy.

- Sturdy and space-efficient design CoreXY allows the motors to be placed on the frame, improving rigidity and making the design more compact.

- Popular and well-documented CoreXY is widely adopted and supported by many firmware platforms like Klipper and Marlin.

🔗 Learn more about CoreXY here: https://corexy.com
![image](https://github.com/user-attachments/assets/7af0c239-4a08-4631-8e9b-f040a55c6f9e)



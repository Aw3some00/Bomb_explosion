# Chain Reaction Simulator 🔥💣

[![Build Status](https://img.shields.io/badge/build-passing-darkgreen)](https://shields.io/)
[![License](https://img.shields.io/badge/license-MIT-blue)](https://opensource.org/licenses/MIT)
![Last Commit](https://img.shields.io/github/last-commit/Aw3some00/Bomb_explosion)
![Version](https://img.shields.io/badge/version-v1.0.1-blue)

![Stars](https://img.shields.io/github/stars/username/repository?style=social)




Welcome to the **Chain Reaction Simulator**! 🎉

**Chain Reaction Simulator** is a program that analyzes the mutual positions of bombs on a 10,000 x 10,000 2D grid. The goal is to find the bomb that, when exploded, triggers the largest chain reaction, and calculates the total damage area, considering intersections of bomb radii.

---

## 📋 Description

The program takes the number of bombs, their coordinates, and the blast radius for each bomb as input. It does the following:
1. Finds the bomb that initiates the largest chain reaction.
2. Calculates the total number of detonated bombs.
3. Computes the total explosion area, including overlaps of bomb radii.

A bomb explodes if the blast radius of any previously detonated bomb intersects with it.

---
## ⚡ Program Functionality

- **Efficient Chain Reaction Simulation**: The program finds the bomb 💣 that, when exploded, triggers the largest chain reaction 🔥 among all possible bombs.
- **Accurate Damage Area Calculation**: The program calculates the total area affected by the explosions 🌍, considering overlaps between bomb radii.
- **Step-by-Step Data Input Interface**: The program allows the user to input the number of bombs, their coordinates 📍, and blast radius (r) with detailed feedback at each step.
- **Loading Progress Visualization**: To enhance user experience, a loading indicator ⏳ shows the progress of the calculations, giving real-time feedback.
- **Maximum Chain Reaction Search**: During the simulation, the program automatically finds the bomb that causes the largest chain reaction 🔄 when detonated.
- **Support for Various Bomb Configurations**: The program allows users to input different parameters for each bomb 🔢 and takes their interactions into account for chain reaction calculations.

### Step-by-Step Process:
1. **Input Bomb Data** 📥: The user enters the number of bombs 🔢, followed by the coordinates (x, y) 📍 and blast radius (r) ⚡ for each bomb.
2. **Simulate Chain Reactions** 🔥: The program simulates the chain reactions 🔄, where a bomb 💥 explodes if its radius intersects with any previously detonated bomb.
3. **Identify the Maximum Chain Reaction** 💣: The program identifies which bomb, when detonated, triggers the most significant chain reaction ⚡.
4. **Calculate Total Blast Area** 🌍: The program calculates the total area 🌏 of the explosion, including overlaps between bomb radii.
5. **Display Results** 🎉: After the simulation is complete, the program displays the bomb indexes that initiated the maximum chain reaction 🔥, as well as the total damage area 📏.

These features make the program a powerful tool ⚙️ for modeling chain reactions under specific conditions, such as bomb radius intersections and varying initial bomb positions.


## 📥 Input Data

The program accepts the following parameters:
1. **Number of bombs (N)** — a positive integer.
2. **List of bombs** — each bomb is defined by its coordinates and blast radius:
   - Coordinates (x, y) — integers in the range [-10000, 10000].
   - Blast radius (r) — a positive number not exceeding 5000.

### 📥📥 Example Input Data

**Enter the number of bombs: 3**

**Enter the coordinates and radius of bomb #1:**

- **X coordinate**: 2
- **Y coordinate**: 2
- **Radius**: 2

Bomb added! Coordinates: (2, 2), Radius: 2

**Enter the coordinates and radius of bomb #2:**

- **X coordinate**: 4
- **Y coordinate**: 4
- **Radius**: 2

Bomb added! Coordinates: (4, 4), Radius: 2

**Enter the coordinates and radius of bomb #3:**

- **X coordinate**: 200
- **Y coordinate**: 200
- **Radius**: 2

Bomb added! Coordinates: (200, 200), Radius: 2

---

### 📥📥 Entered Data:

- **Bomb 1** at (2, 2) with radius 2
- **Bomb 2** at (4, 4) with radius 2
- **Bomb 3** at (200, 200) with radius 2

---

### 🚀 Search for Maximum Chain Reaction in Progress...

**Loading**  
0% 10% 20% 30% 40% 50% 60% 70% 80% 90%

**Loading completed!**

---

### 🔥 Results:

- **Indexes of the maximum chain reaction**: 1, 2, 3
- **Total blast area (detonated)**: 12.5664

---

## ⚡ Features

- **Efficient chain reaction simulation**: Finds the bomb with the most massive chain reaction.
- **Accurate damage calculation**: Computes the total explosion area, including intersections.
- **Real-time loading indicator**: Visual feedback for users during calculation.

---

## 🛠️ Installation

To use the Chain Reaction Simulator, you need to have **C++** installed on your machine. Follow these steps to run the program:

1. Clone the repository:

   ```bash
   git clone https://github.com/Aw3some00/Bomb_explosion.git
2. Navigate into the project folder:
   ```bash 
   cd Bomb_explosion
3. Compile the program:
    ```bash 
   g++ -o chain_reaction_simulator main.cpp 
4. Run the program:
    ```bash 
   ./chain_reaction_simulator
   
---

## 🤝 Contributing

We welcome contributions! To contribute to the project:

1. Fork the repository 🍴
2. Create a new branch for your feature or fix 🌱
3. Commit your changes 📝
4. Push your branch🚀
5. Open a pull request🔄

Please ensure your code follows the project's coding standards and includes tests for any new functionality. If your pull request fixes an issue or adds a feature, be sure to reference the issue number in the pull request description.

---

## 📝 License

This project is licensed under the [MIT License](https://opensource.org/licenses/MIT). 🎉

You are free to use, modify, and distribute this project as long as you retain the original license and copyright notice.

---

## 📞 Contact

For any inquiries, please reach out to
### **kotnarkot962@gmail.com**

---
## ♥️ Support us on Patreon
If you like this project, feel free to support it via donations! 🙌

[![Support me on Patreon](https://img.shields.io/badge/Support_Patreon-FF424D?style=for-the-badge&logo=patreon&logoColor=white)](https://www.patreon.com/c/Aw3some?fromConcierge=true)

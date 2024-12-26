# Chain Reaction Simulator 🔥💣

[![Build Status](https://img.shields.io/badge/build-passing-darkgreen)](https://shields.io/)
[![License](https://img.shields.io/badge/license-MIT-blue)](https://opensource.org/licenses/MIT)
![Last Commit](https://img.shields.io/github/last-commit/Aw3some00/Bomb_explosion)
![Version](https://img.shields.io/badge/version-v1.0.2-blue)

![Stars](https://img.shields.io/github/stars/username/repository?style=social)

## Table of Contents
- [Description](#-description)
- [Program Functionality](#-program-functionality)
- [Input Data and example](#-input-data)
- [Features](#-features)
- [Installation](#-installation)
- [Math based part](#math-based-part-)
- [Functions Description](#functions-description-)
  -  [Namespace `checkers`](#namespace-checkers)
   - [Namespace `b`](#namespace-b)
- [Functions Description(bombs_input.cpp)](#functions-descriptionbombs_inputcpp)
- [Contributing](#-contributing)
- [License](#-license)
- [Contact](#-contact)
- [Support us on patreon](#-support-us-on-patreon)





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

- **Indexes of the maximum chain reaction**: 1, 2
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
3. Compile the program(example shows how to compile with g++ compilator you can do it on Cmake):
    ```bash 
   g++ -o chain_reaction_simulator main.cpp

3.1.  If you use Cmake,everything you need were put in Cmakelists.txt file,just use "CmakeLists.txt" file to compile 
and enjot the process of "EXPLOSION"🔥

4. Run the program(on g++ compiler):
    ```bash 
   ./chain_reaction_simulator


   
5. P.S do you hear "Ka-Boooooooom?"💣
   
---
## Math based part 
Those program is based on math formulas like:
1. Area of the circle 
   ```bash
   𝛑𝚛^2
2. Area of the intersection between 2 circles
      ```bash
   S = R1² * acos((d² + R1² - R2²) / (2 * d * R1)) + R2² * acos((d² + R2² - R1²) / (2 * d * R2)) - sqrt((-d + R1 + R2) * (d + R1 - R2) * (d - R1 + R2) * (d + R1 + R2))

#### Variables:
- `R1` — radius of the first circle.
- `R2` — radius of the second circle.
- `d` — distance between the centers of the two circles.

This formula is used to compute the intersection area of two circles in Euclidean geometry.

---
## Functions Description(bombs.cpp)

### Namespace `checkers`
1. **`borders_check(double x)`**  
   Verifies if the coordinate `x` is within the valid range [-10000, 10000].

 2. **`count_checker(double count)`**  
   Ensures the number of bombs is valid. Throws an exception if `count` is less than 0. Returns `false` if no bombs are present.

3. **`r_checker(double radius)`**  
   Checks if the bomb's radius is within the allowed range [0, 10000]. Throws exceptions for invalid values.

---

### Namespace `b`
1. **`is_in_radius(const Bomb a, const Bomb b)`**  
   Determines if bomb `b` is within the blast radius of bomb `a`. Throws exceptions for invalid bomb data or identical bombs.

2. **`intersection_area(double R1, double R2, double d)`**  
   Computes the intersection area between two circles representing explosion zones with radii `R1` and `R2` at distance `d`.

3. **`simulate_chain_reaction(std::vector<Bomb>& bombs, int start_index)`**  
   Simulates a chain reaction starting from the bomb at `start_index`. Returns the total number of detonated bombs.

4. **`circle(double R1)`**  
   Calculates the area of a circle with radius `R1`.

5. **`calculate_total_area_with_intersections(std::vector<Bomb>& bombs)`**  
   Computes the total affected area, accounting for overlapping explosion zones and fully contained zones.

6. **`find_indexes_of_max_chain_reaction(std::vector<Bomb>& bombs, std::vector<int>& max_indexes, double& max_area)`**  
   Identifies the indices of bombs that trigger the maximum chain reaction. Updates `max_indexes` and `max_area` with the results.


---
## Functions Description(bombs_input.cpp)
1. **`is_duplicate(const std::vector<b::Bomb>& bombs, const b::Bomb& new_bomb);`**
  Checks if bombs in input duplicates or not,if yes returns true,else returns false
2. **`Animation()`**
  Simple animation of loading from 0 to 100;
3. **`collect_info(std::vector<b::Bomb>& bombs)`**
   A function that collects information from the user. The user enters the count of bombs, the X and Y coordinates, and the radii of the bombs. If any mistakes are found in the input, the function will inform the user about them
---
   ### **For example:**
3.1 **Ошибка в данных бомбы под номером 1. Пожалуйста, введите данные снова.
    Введите координаты и радиус бомбы под номером 1:**
---
4. **`print_result(std::vector<b::Bomb>& bombs, std::vector<int>& max_indexes, double max_area)`**
A function that prints your entered information after some checks and shows it in a right way,then start animation(),after animation,calculates indexex that create maximum chain reaction and exploded area,and shows final result(it is exploded area and maximum indexex)

**NOTE:** We taking into account the subtracted intersection
5. **`strrtodbl(const std::string& input);`**
 Changes string to double

6.   **`is_valid_input(const std::string& input)`**
Ensures that user-provided coordinates and radius values are valid numbers before converting and storing them.
7.   **` is_int(const std::string& input)`**
     Confirms that the count of bombs entered by the user is an integer before further processing.

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
### **fuadrashidov06@gmail.com emilyafandieva123@gmail.com** 

---
## ♥️ Support us on Patreon
If you like this project, feel free to support it via donations! 🙌

[![Support me on Patreon](https://img.shields.io/badge/Support_Patreon-FF424D?style=for-the-badge&logo=patreon&logoColor=white)](https://www.patreon.com/c/Aw3some?fromConcierge=true)

# Chain Reaction Simulator 🔥💣  

**Chain Reaction Simulator** — программа, которая анализирует взаимное расположение бомб на 2D-карте размером 10,000 на 10,000. Цель — найти бомбу, взорвав которую, будет запущена наибольшая цепная реакция, и рассчитать общую площадь поражения.

---

## 📋 Описание  

На вход подаётся количество бомб, их координаты, и радиус поражения для каждой бомбы. Программа:  
1. Находит бомбу, инициирующую самую масштабную цепную реакцию.  
2. Считает общее количество взорванных бомб.  
3. Рассчитывает площадь поражения.  

Бомба взрывается, если радиус поражения любой другой взорвавшейся бомбы пересекает её.  

---

## 📥 Входные данные  

Программа принимает следующие параметры:  
1. **Количество бомб (`N`)** — положительное целое число.  
2. **Список бомб** — для каждой бомбы задаются её координаты и радиус:  
   - Координаты (`x, y`) — целые числа в пределах `[0, 10,000]`.  
   - Радиус поражения (`r`) — положительное число.  

## 📤 Выходные данные 


Введите количество бомб: 5  
Введите радиус поражения для всех бомб: 50  

Введите координаты каждой бомбы (через пробел):  
1. Бомба 1: 100 200  
2. Бомба 2: 150 250  
3. Бомба 3: 400 500  
4. Бомба 4: 600 600  
5. Бомба 5: 200 200  

----------------------------------  
Результат:  
----------------------------------  
💣 **Бомба с наибольшей цепной реакцией:** 2  
💥 **Количество взорванных бомб:** 4  
📏 **Общая площадь поражения:** 31,415.93  


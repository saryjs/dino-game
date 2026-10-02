# Dino Game
# Змінні (та константи)
<u>size_t score = 0;</u> <br>
При кожному оновленні екрану додаває єдиницю.
<br>

<u>const size_t screenWidth = 60;</u> <br>
Довжина екрану <br>

<u>const size_t pos = screenWidth / 3;</u> <br>
Позиція на екрані: 1/3
<br>

<u>size_t chance = 20;</u> <br>
Шанс створення дерев (зазвичай 20)
<br>

<u>size_t speed = 100;</u> <br>
Швідкість оновлення екрану у мс (зазвичай 100)
<br>

<u>bool jumping = false;</u> <br>
Булеан для стрибання
<br>

<u>size_t airTime = 0;</u> <br>
Час для стрибання, є годинником
<br>
# Чарсет для об'єктів
<u>char dino = '&';</u><br>
Персонаж
<br>
<u>char air = ' ';</u><br>
Повітря
<br>
<u>char flr = '-';</u><br>
Підлога
<br>
<u>char dbg = 'X';</u><br>
Дебаг
<br>
# Функції
<u>char getObs()</u><br>
Возвращає об'єкти
<br>
<u>size_t printHighscore()</u><br>
Prints out the highscore from the file
<br>
<u>char getObs()</u><br>

<br>
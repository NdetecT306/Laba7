# Laba7

Задание 1: Кривая Коха. 

Задание 2: Алиса и Боб соревнуются в стрельбе из лука. На соревнованиях установлены следующие правила: - Сначала Алиса стреляет numArrows стрел, а затем Боб numArrows стрел. - Затем баллы рассчитываются следующим образом: 
o Цель имеет целочисленные части подсчета очков в диапазоне от 0 до 11 включительно. 
o Для каждой части мишени со счетом k (между 0 и 11) предполагается, что Алиса и Боб выпустили 𝑎𝑘 and 𝑏𝑘 стрел в этой части соответственно. Если 𝑎𝑘 ≥ 𝑏𝑘, то Алиса получает k очков. Если 𝑎𝑘 < 𝑏𝑘, то Боб получает k очков. 
o Однако если ak == bk == 0, то никто не получает k баллов. 
Например, если Алиса и Боб оба выпустили 2 стрелы в секцию со счетом 11, то Алиса получает 11 очков. С другой стороны, если Алиса выпустила 0 стрел в секцию с 11 очками, а Боб выстрелил 2 стрелы в ту же секцию, то Боб получает 11 очков. 
Вам дано целое число numArrows и целочисленный массив aliceArrows размера 12, который представляет собой количество стрел, выпущенных Алисой на каждом участке подсчета очков от 0 до 11. Теперь Боб хочет максимизировать общее количество очков, которое он может получить. Возвратите массив, bobArrows который представляет количество стрел, выпущенных Бобом на каждом участке подсчета очков от 0 до 11. Сумма значений bobArrows должна равняться numArrows. 
Если у Боба есть несколько способов заработать максимальное количество очков, верните любой из них.

Задание 3:  Разместить на шахматной доске максимальное количество коней так, чтобы они не находились друг у друга «под боем».

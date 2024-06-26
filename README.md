# misis2023f-22-01-popov-a-yu
Личный репозиторий студента НИТУ МИСИС Попова Артемия из группы БПМ-22-1
 
# Индивидуальное задание в проекте 
Создание _автоматизаций_ и их визуализация. Под автоматизацией подразумевается кусочно-заданная функция, 
заданная произвольный количеством функций сглаживания:

![image](https://github.com/cymdaspec/misis2023f-22-01-popov-a-yu/assets/90800517/44ec3411-dd1e-48f6-8e6d-09983e167a63)

Каждый сегмент представляет собой функцию сглаживания и может иметь произвольную длительность.

# Использование функций сглаживания
Функциями сглаживания называется набор из 30 функций, придуманный Робертом Пеннером. Эти функции часто применяются для анимаций.
Пример использования функций сглаживания. В данном случае к параметру привязан _процент прохождения объектом пути_:

![347ca67f2010d160e3bf5bf35a92078d](https://github.com/cymdaspec/misis2023f-22-01-popov-a-yu/assets/90800517/d85a598d-b514-494c-8137-ffa09c88f600)

В библиотеке Automations Constructor реализованы все функции сглаживания, не выходящие за пределы [0, 1].

# Терминология

Под _<ins>автоматизацией</ins>_ понимается функция, описывающая изменение нормализованного параметра на протяжении времени. Она может быть задана как несколькими функциями сглаживания (тогда автоматизация являет собой кусочно-заданную функцию), так и одной (в этом случае автоматизация представляет собой одну функцию сглаживания произвольной длины)

![image](https://github.com/cymdaspec/misis2023f-22-01-popov-a-yu/assets/90800517/238349a2-3c7f-425d-9f0a-a35e188b9661)


_<ins>Таймкоды</ins>_ - числовые значения, задающие длительность каждой сглаживающей функции (на рисунке отмечены под осью t).

Упомянутые ранее _<ins>функции сглаживания</ins>_ являются объектами библиотеки Choreograph. Они заданы либо строго математически (например функция EaseInQuad описана y = x² и возвращает квадрат числа), либо математически в сочетании с логическими условиями (например если поданный на вход параметр больше 0.5, то возвращается значение по одной формуле, иначе по другой). 

Для построения графиков автоматизацию необходимо преобразовать в _<ins>последовательность</ins>_ (Sequence()), описанную в библиотеке Choreograph. Главный метод последовательности, благодаря которому при помощи SFML формируется визуализация - choreograph::getValue(time).

Понятие _<ins>составной функции</ins>_ используется в .h файле для определения автоматизаций, состоящих из единственной функции сглаживания (т.е. автоматизация представлена одним сегментом).
 

# Шаблон таймлайна
Из примеров выше можно выделить общий шаблон реализации таймлайна. Панель таймлайна обязательно должна иметь:
- Дорожки для проставления на них событий
- Горизонтальную ось времени

# Используемые библиотеки
[Choreograph](https://github.com/sansumbrella/Choreograph) - библиотека для работы со временем (тайминги событий) 

[SFML](https://github.com/SFML/SFML) - библиотека для построения графиков
 
# Хранилище проекта
https://github.com/cymdaspec/vimaker

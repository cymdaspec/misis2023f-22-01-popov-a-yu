# misis2023f-22-01-popov-a-yu
Личный репозиторий студента НИТУ МИСИС Попова Артемия из группы БПМ-22-1
 
# Индивидуальное задание в проекте ViMaker
Главная индивидуальная задача - реализация модуля таймлайна.
 
<ins>Панелью таймлайна</ins> называется окно в приложении, где пользователь создает *события*, настраивает время и характер срабатывания события, 
а события в свою очередь образуют *последовательность событий*.
Под <ins>событием</ins> подразумевается моментальное либо длительное изменение какого - либо параметра, связанного с отображением исследуемого 3D объекта.
Каждое событие обладает несколькими свойствами, такими как *таймкод начала выполнения*, *таймкод конца выполнения*, привязанный к событию *параметр отображения*, *динамика изменения привязанного параметра*.
К <ins>параметрам отображения</ins> относятся *зум*, *положение камеры*, *угол поворота камеры*.
 
# Примеры  реализации
Уместными референсными приложениями с реализованным модулем таймлайна являются Adobe Premiere Pro и FL Studio

![image](https://github.com/cymdaspec/misis2023f-22-01-popov-a-yu/assets/90800517/dc39eda1-4109-4030-8cbb-e90ab738d4ea)
<div align="center">
  Плейлист в FL Studio
</div> 

![image](https://github.com/cymdaspec/misis2023f-22-01-popov-a-yu/assets/90800517/4fcef28b-142f-408d-a1a4-e75bbfe03b5f)
<div align="center">
  Плейлист в FL Studio
</div> 

# Шаблон таймлайна

Из примеров выше можно выделить общий шаблон реализации таймлайна. Панель таймлайна обязательно должна иметь:
- Дорожки для проставления на них событий
- Горизонтальную ось времени
 
# Хранилище проекта
https://github.com/cymdaspec/vimaker

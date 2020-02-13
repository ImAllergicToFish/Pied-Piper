
# Задание 5 - Порты ввода-вывода общего назначения

# Срок сдачи: Бессрочно

# Статус: Не сдано

# Оценка: 0



## Задание

### Отличия от других заданий

1. В этом задании тесты проверяют только дату. К сожалению, я пока не смог изобрести способ автоматической проверки корректности подобных программ. Поэтому вам придется быть более аккуратными, чем вы привыкли :)
2. Защищать эту работу не нужно :(
3. Вам нужно написать, фактически, три программы, каждая из которых должна работать "вечно" - пока есть питание на микроконтроллере, поэтому распихивать их в разные файлы или в разные функции не очень удобно. В этот раз мы воспользуемся условной компиляцией.
4. А да, отчет не нужен :)

В файле `src/main/main.c` определены 3 области условной трансляции с помощью директив `#if`, каждая область соответствует части задания.

Чтобы включить компиляцию определенной части задания, определите макрос 

## Просьба

Пожалуйста, в точности соблюдайте предписанную по заданию структуру файлов, названия функций, их сигнатуры и т.д.! Это сделано для облегчения автоматического тестирования кода - т.е. для ускорения проверки работ.

## **Важное замечание**

 Все контакты микроконтроллера, прямо не относящиеся к заданию, должны оставаться в состоянии по-умолчанию (general purpose input floating), их режимы работы или функции меняться не должны! Ваша программа не должна менять состояния соответствующих битов в регистрах портов общего назначения!

 Так же нельзя рассчитывать на то, что ваша программа начинает работу с портом в состоянии после сброса; не рассчитывайте на состояния регистров по-умолчанию!

При считывании кнопок ваша программа должна проверять только состояния явно указанных контактов, состояние остальных контактов ваша программа контролировать не должна!

Представьте, что все остальные выводы микроконтроллера используются другим программистом; вы не должны ему мешать или надеяться, что он делает что-то строго определенное.

Слишком слабая мотивация? Окей, представьте, что все остальные ноги контроллера управляют чем-нибудь очень важным, например, подъемом стержней-замедлителей в ядерном реакторе. Если ноги будут настроены неправильно, то реактор расплавится и начнется термоядерный апокалипсис с Кевином Костнером в главной роли почтальона!

Перед сдачей, пожалуйста, визуально убедитесь (с помощью соответствующих окон отладчика), что все входы и выходы настроены в нужные режимы, а остальные ноги не задействованы.
Убедитесь так же, что записи и чтения портов записывают или читают только нужные биты!

## Умолчания

Если не оговорено иное, то:

 - все светодиоды загораются при подаче логической 1 на соответствующий выход (т.е. при подаче высокого уровня напряжения);
  
 - все кнопки имеют внешнюю подтяжку к земле, т.е. когда кнопка нажата на входе считывается лог. 1;

 - все части программы должны работать "вечно", пока на микроконтроллере есть питание, т.е. должны выполняться в бесконечном цикле;

## Часть первая - мигание по нажатию кнопки

К выводу `PC.8` подключен светодиод. К выводу `PA.0` подключена кнопка.
Необходимо, чтобы светодиод горел **только** тогда, когда нажата кнопка.


## Часть вторая - попеременное мигание

 К выводам `PC.8` и `PC.9` подключены светодиоды. Необходимо мигать ими попеременно (т.е. сначала горит один, потом другой и т.д.). Частота мигания должна быть в диапазоне от 50 до 0.1 Гц.

 Частоту мигания следует измерять в симуляторе с помощью точек останова и поля "Sec." либо с помощью [виртуального осциллографа](https://github.com/spbstu-microprocessors/lectures_2019/blob/master/keil_logic_analyzer.md).

 ![wizads_club](.images/seconds.png)

## Часть третья - 7 светодиодов

К порту A (к выводам с `PA.1` по `PA.7`) подключено 7 светодиодов. Светодиоды имеют номера с нулевого по шестой.   
К порту B к ножкам с `PB.0` по `PB.2` подключены три кнопки (с нулевой по вторую).  

Ноги для кнопок должны быть настроены как входы с подтяжкой к земле; кнопка считается нажатой, если на ноге высокий уровень.

Нажатием на кнопки задается номер светодиода (в двоичном коде), который должен загореться.
Например, нажаты нулевая и вторая кнопки (101), что соответствует числу 5. Значит, должен гореть только пятый светодиод.  
Например, не нажата ни одна кнопка - должен гореть нулевой светодиод.

### Дополнительный балл: 

Cодержимое бесконечного цикла для третьей части можно уместить в две строки кода на языке С без операторов ветвлений и суммарной длиной около 80 символов.

## Как отлаживаться?

- См. презентацию [№16 - GPIO](https://github.com/spbstu-microprocessors/lectures/blob/master/Презентации/16%20-%20GPIO.pptx)
- См. [документ про виртуальный осциллограф](https://github.com/spbstu-microprocessors/lectures/blob/master/keil_logic_analyzer.md)
  
Вкратце:

Для отладки ваших программ на симуляторе воспользуйтесь окнами работы с периферией: 
- В режиме отладки меню `Peripherals->General Purpose I/O->нужный порт`.
- Чтобы окна обновлялись, когда программа запущена, во время отладки установите галочку в меню `View->Periodic Window Update.`
- Чтобы запустить программу не по шагам, а просто запустить, в режиме отладки нажмите `F5`.

### Эмуляция нажатия на кнопку:
  
Установка галочки в графе `Pins` (кликом мыши) соответствует подаче высокого логического уровня на вход, если вход настроен соответствующим образом. Появление галочки в регистре `IDR` (засереная область) "подтверждает" появление высокого логического уровня:

![wizads_club](.images/gpio_first.png)

### Эмуляция светодиода:

Если контакт микроконтроллера настроен на выход, то запись единицы в соответствующий бит регистра ODR приведет к появлению галочки в соответствующем бите регистра IDR (серая область) и в бите графы Pins:

![wizads_club](.images/gpio_second.png)

Помните, что перед тем, как что-то писать в регистры порта, порт нужно затактировать (подать питание). О наличии питания/тактирования свидетельствует надпись `Clock Enabled` в графе `Settings`.

![wizads_club](.images/gpio_third.png)

К сожалению, симулятору наплевать, затактирован порт или нет; в регистры все равно можно писать. Только на настоящей плате потом ничего не заработает.



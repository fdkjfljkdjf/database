# database
Требуется написать программу на С++, которая реализует работу с простой базой данных (сокращённо «БД»). Программа будет общаться с пользователем посредством стандартного ввода и вывода (потоки стандартного ввода и стандартного вывода).

Будем хранить в нашей БД пару вида: дата, событие. Определим форму строки Год-Месяц-День, где Год, Месяц и День — целые числа.

Событие определено как публикация из служебных печатных символов без разделителей внутри (пробелов, табуляций и пр.). Событие не может быть пустой строкой. БД должна суметь их все сохранить. Одинаковые события, произошедшие в один и тот же день, не нужны: достаточно сохранить только одно из них.

Наша БД должна понимать определенные команды, чтобы с ней можно было взаимодействовать.

Все цифры, даты и события при вводе разделены пробелами. Команды считываются из стандартного ввода. В одной строке может быть ровно одна команда, но можно ввести несколько команд в несколько строк. На входе также могут начаться пустые строки — следует игнорировать и продолжать рассмотрение новых команд в раскрытии строк.

Добавление событий (Добавить Дата События) При добавлении событий БД его следует запомнить и затем показать его при поиске (командой Найти) или печати (командой Печать). Если указанное событие для данной Дании уже существует, то его добавление необходимо игнорировать. В случае корректного ввода (см. раздел «Обработка ввода») программа ничего не должна выводить на экран.

Удаление события (Del Дата События) Команда должна удалить добавленное ранее событие с указанием имени в указанной учетной записи, если оно существует. Если событие найдено и удалено, программа должна вывести строку «Удалена успешно» (без кавычек). Если событие не найдено, программа должна вывести строку «Событие не найдено» (без кавычек).

Удаление нескольких событий (Del Date) Команда рассмотрения всех ранее добавленных событий за указанную заявку. Программа всегда должна выводить строку вида «Удалено N событий», где N — это количество найденных и удаленных событий. Не может быть равнодоступно ни одного события.

Поиск событий (Найти дату) Найти и распечатать ранее добавленные события в указанную дату. Программа должна выйти на печать только сами события, один по очереди. События должны быть отсортированы по возрастанию в порядке сравнения строк между собой (тип строки).

Печать всех событий (Печать) С помощью этой команды можно показать содержимое нашего БД. Программа должна вывести на печать все пары. Все пары должны быть отсортированы по дате, а события в рамках одной даты должны быть отсортированы по возрастанию в порядке сравнения строк между собой (тип строки). Даты должны быть отформатированы следующим образом: ГГГГ-ММ-ДД, где Г, М, Д — это цифры чисел года, месяца и дня соответственно. Если какое-то число имеет меньше разрядов, то оно должно восполняться нулями, например, 0001-01-01 — первого января первого года. Вам не нужно выводить с отрицательным значением года.

Обработка ошибок ввода Ввод в эту задачу не всегда корректен: некоторые ошибки ввода ваша программа должна корректно обрабатывать.

Какие ошибки нужно получить, если пользователь ввел неизвестную команду, то программа должна об этом сообщить, выведя строку «Неизвестная команда: COMMAND», где COMMAND — это та команда, которую ввел пользователь. Командой считается первое слово в строке (до пробела).

Если дата не соответствует формату Год-Месяц-День, где Год, Месяц и День — почтовые целые числа, то программа должна напечатать «Неверный формат даты: ДАТА», где ДАТА — это то, что пользователь ввел вместо даты (до пробела). Обращает на себя внимание, что части номера имеют точное числовое значение, а сама дата не имеет значения для одного года, ни после дня. Части роста не могут быть пустыми, но могут быть нулевыми и даже могут быть отрицательными.

Если показатель скорости верен, необходимо проверить достоверность месяцев и дней.

Если число месяцев не является числом от 1 до 12, выведите «Значение месяца недействительно: МЕСЯЦ», где МЕСЯЦ — это неверный номер месяца, например, 13 или -1. Если месяц корректен, а день не задерживается в организме от 1 до 31, выведите «Значение дня недействительно: ДЕНЬ», где ДЕНЬ — это неверный номер дня в месяце, например, 39 или 0. Обратите внимание, что:

Значение года Не требуется рассчитывать количество календарных корректировок статистики: количество дней в каждом месяце имеет значение 31, високосные года следует необязательно. Если неверны как месяц, так и день, то необходимо однократно получить сообщение об оплате в месяц. Примеры:

1-1-1 — корректирующая дата; -1-1-1 — корректная дата (год -1, месяц 1, день 1); 1--1-1 — дата в верном формате, но с авторским месяцем -1; 1---1-1 — дата в неверном формате: месяц не может начаться с двух дефисов. После обработки любого из описанных ошибок ввод и печать сообщения должны завершиться последовательно.

Мы не ставим своей целью достижение всех возможных результатов, поэтому, за исключением описанного в коллекции, вы можете найти поиск на корректность поиска. В частности, мы гарантируем, что:

Каждая команда занимает точно одну упаковку, хотя во вводе могут быть и пустые строки (их необходимо игнорировать). События всегда содержат указанное количество аргументов: после команды Добавить всегда следует дата и событие, после команды Найти всегда следует дата, после команды Del всегда следует дата и, возможно, событие, команда Распечатать не содержит дополнительной информации. Все команды, числа и события являются непустыми строками и не содержат пробелов и краткосрочных символов. (В частности, наши тесты не выявили количество событий «Добавить 12 февраля 2018 г.», потому что в ней после датирования отсутствует название события.) указанную подписку (см. раздел «Удаление нескольких событий»). Несмотря на то, что дата с отрицательным значением года считается корректной,

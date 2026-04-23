// Билет номер 3

/*
1. Обработка исключений в C#

Исключения в C# — это механизм обработки ошибок во время выполнения программы. Когда возникает непредвиденная ситуация (например, деление на ноль, отсутствие файла, проблемы с сетью), программа генерирует исключение. Это позволяет:

отделить код обработки ошибок от основного кода;

централизованно обрабатывать ошибки разных типов;

предотвратить аварийное завершение программы;

предоставить информацию о возникшей проблеме.

Конструкция try-catch-finally

Конструкция состоит из трёх блоков:

try — блок кода, в котором может возникнуть исключение.

catch — блок для обработки исключений определённого типа. Может быть несколько блоков catch для разных типов исключений.

finally — блок, который выполняется всегда, независимо от того, было ли исключение. Используется для освобождения ресурсов (например, закрытия файлов или соединений).

Пример:

csharp
try
{
    int result = 10 / 0;
}
catch (DivideByZeroException ex)
{
    Console.WriteLine($"Ошибка: {ex.Message}");
}
finally
{
    Console.WriteLine("Блок finally выполнен.");
}
Типы исключений

В C# существует иерархия исключений, все они наследуются от базового класса Exception. Некоторые распространённые типы:

Exception — базовый класс всех исключений.

ArgumentException — возникает, когда один из аргументов метода недействителен.

NullReferenceException — попытка использовать ссылку на объект, который равен null.

IOException — ошибки ввода‑вывода (например, файл не найден).

FileNotFoundException — файл не найден.

DivideByZeroException — деление на ноль.

IndexOutOfRangeException — выход за границы массива.

Создание собственных исключений

Чтобы создать собственное исключение, нужно унаследовать класс от Exception (или его подкласса) и добавить необходимые конструкторы.

Пример:

csharp
public class MyCustomException : Exception
{
    public MyCustomException() { }
    public MyCustomException(string message) : base(message) { }
    public MyCustomException(string message, Exception inner) : base(message, inner) { }
}

throw new MyCustomException("Произошла ошибка.");
Когда использовать и когда не злоупотреблять исключениями

Использовать исключения стоит:

для обработки непредвиденных ситуаций (ошибки ввода‑вывода, сетевые проблемы);

когда ошибка не может быть обработана на текущем уровне кода;

для передачи информации о критической ошибке вверх по стеку вызовов.

Не стоит злоупотреблять исключениями:

для управления потоком выполнения программы;

в случаях, когда ошибку можно проверить заранее (например, проверка на null вместо обработки NullReferenceException);

для часто возникающих «нормальных» ситуаций (например, неверный ввод пользователя).

2. Generics (обобщения) в C#
Что такое обобщения и зачем они нужны

Обобщения (Generics) позволяют создавать классы, интерфейсы и методы, которые работают с различными типами данных без потери типобезопасности. Они позволяют отложить спецификацию типа данных до момента использования.

Преимущества перед обычными типами (object)

Типобезопасность. Компилятор проверяет типы на этапе компиляции, предотвращая ошибки приведения типов.

Производительность. Исключается упаковка (boxing) и распаковка (unboxing) типов‑значений.

Читаемость кода. Код становится более понятным и самодокументируемым.

Повторное использование кода. Один обобщённый класс может работать с разными типами.

Обобщённые классы и методы

Обобщённые классы — классы, которые принимают тип в качестве параметра. Пример: List<T>.

Обобщённые методы — методы, которые могут работать с разными типами данных. Пример:

csharp
public T GetDefault<T>()
{
    return default(T);
}
Ограничения (where T : class, new() и др.)

Ограничения позволяют указать, какие типы могут использоваться в качестве параметров обобщения:

where T : class — тип должен быть ссылочным.

where T : struct — тип должен быть типом‑значением.

where T : new() — тип должен иметь конструктор без параметров.

where T : <base class> — тип должен наследоваться от указанного класса.

where T : <interface> — тип должен реализовывать указанный интерфейс.

Пример:

csharp
public class Repository<T> where T : class, new()
{
    public T Create()
    {
        return new T();
    }
}
Примеры использования

Коллекция с типобезопасностью:

csharp
List<int> numbers = new List<int>();
numbers.Add(1);
numbers.Add("string"); // Ошибка компиляции
Обобщённый метод для поиска максимума:

csharp
public static T Max<T>(T a, T b) where T : IComparable<T>
{
    return a.CompareTo(b) > 0 ? a : b;
}
Словарь:

csharp
Dictionary<string, int> ages = new Dictionary<string, int>();
ages["Alice"] = 25;
3. Взаимодействие с файловой системой
Классы File, Directory, Path

File — предоставляет статические методы для создания, копирования, удаления, перемещения и открытия файлов.

Directory — предоставляет статические методы для создания, перемещения и перечисления каталогов и подкаталогов.

Path — предоставляет методы и свойства для работы с путями к файлам и каталогам (объединение путей, получение имени файла и т. д.).

Чтение и запись файлов

Чтение:

File.ReadAllText(path) — читает весь файл в строку.

File.ReadAllLines(path) — читает файл построчно в массив строк.

Запись:

File.WriteAllText(path, content) — записывает строку в файл.

File.WriteAllLines(path, lines) — записывает массив строк в файл.

Работа с потоками (StreamReader, StreamWriter)

StreamReader — используется для чтения символов из байтового потока. Подходит для больших файлов.

StreamWriter — используется для записи символов в поток.

Пример чтения файла:

csharp
using (StreamReader reader = new StreamReader("file.txt"))
{
    string line;
    while ((line = reader.ReadLine()) != null)
    {
        Console.WriteLine(line);
    }
}
Пример записи в файл:

csharp
using (StreamWriter writer = new StreamWriter("file.txt"))
{
    writer.WriteLine("Hello, World!");
}
Обработка ошибок при работе с файлами

При работе с файловой системой возможны ошибки:

файл не найден (FileNotFoundException);

нет прав доступа (UnauthorizedAccessException);

диск заполнен (IOException).

Для обработки используйте try-catch:

csharp
try
{
    string content = File.ReadAllText("file.txt");
}
catch (FileNotFoundException)
{
    Console.WriteLine("Файл не найден.");
}
catch (UnauthorizedAccessException)
{
    Console.WriteLine("Нет прав доступа.");
}
catch (IOException ex)
{
    Console.WriteLine($"Ошибка ввода‑вывода: {ex.Message}");
}*/

// Задание 1 

using System;
using System.Collections.Generic;

class Storage<T>
{
    private List<T> items = new List<T>();

    public void Add(T item)
    {
        items.Add(item);
    }

    public List<T> GetAll()
    {
        return items;
    }
}

class Program
{
    static void Main()
    {
        Console.WriteLine("Работа с типом int:");
        Storage<int> intStorage = new Storage<int>();
        intStorage.Add(10);
        intStorage.Add(20);
        intStorage.Add(30);

        List<int> intItems = intStorage.GetAll();
        foreach (int item in intItems)
        {
            Console.WriteLine(item);
        }

        Console.WriteLine();

        Console.WriteLine("Работа с типом string:");
        Storage<string> stringStorage = new Storage<string>();
        stringStorage.Add("Привет");
        stringStorage.Add("Мир");
        stringStorage.Add("C#");

        List<string> stringItems = stringStorage.GetAll();
        foreach (string item in stringItems)
        {
            Console.WriteLine(item);
        }
    }
}


// Задание 2 

using System;
using System.IO;

class FileHandler
{
    static void Main()
    {
        string filePath = "data.txt";

        try
        {
            Console.WriteLine("Содержимое файла:");
            string content = File.ReadAllText(filePath);
            Console.WriteLine(content);
        }
        catch (FileNotFoundException)
        {
            Console.WriteLine($"Ошибка: Файл '{filePath}' не найден.");
            return;
        }
        catch (IOException ex)
        {
            Console.WriteLine($"Ошибка чтения файла: {ex.Message}");
            return;
        }

        try
        {
            string newLine = "Новая строка";
            File.AppendAllText(filePath, newLine + Environment.NewLine);
            Console.WriteLine($"\nСтрока '{newLine}' успешно добавлена в файл.");
        }
        catch (IOException ex)
        {
            Console.WriteLine($"Ошибка записи в файл: {ex.Message}");
        }
    }
}

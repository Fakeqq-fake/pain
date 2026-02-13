using System;

public delegate void StringProcessor(string input);

class Program
{
    static void PrintString(string text)
    {
        Console.WriteLine(text);
    }

    static void Main(string[] args)
    {
        StringProcessor processor = new StringProcessor(PrintString);

        processor("Привет, мир!");
    }
}


using System;

public delegate int MathOperation(int a, int b);

class Program
{
    static int Add(int x, int y)
    {
        return x + y;
    }

    static int Multiply(int x, int y)
    {
        return x * y;
    }

    static void Main(string[] args)
    {
        MathOperation operation;

        operation = Add;
        
        int resultAdd = operation(5, 3);
        Console.WriteLine($"5 + 3 = {resultAdd}");

        operation = Multiply;
        
        int resultMultiply = operation(5, 3);
        Console.WriteLine($"5 * 3 = {resultMultiply}");
    }
}


using System;

public delegate void MessagePrinter(string message);

class Program
{
    static void Main(string[] args)
    {
        MessagePrinter printer = (text) => 
        {
            Console.WriteLine($"Сообщение: {text}");
        };

        printer("Привет, мир!");
        printer("Это тестовое сообщение.");
    }
}


using System;

public delegate void ValueChangedHandler(int newValue);

class Counter
{
    private int value;

    public event ValueChangedHandler ValueChanged;

    public void Increment()
    {
        value++;
        OnValueChanged(value);
    }

    protected virtual void OnValueChanged(int newValue)
    {
        if (ValueChanged != null)
        {
            ValueChanged(newValue);
        }
    }

    public int GetValue()
    {
        return value;
    }
}

class Program
{
    static void Main(string[] args)
    {
        Counter counter = new Counter();

        counter.ValueChanged += (newValue) =>
        {
            Console.WriteLine("Значение изменилось. Новое значение: " + newValue);
        };

        counter.Increment();
        counter.Increment();
        counter.Increment();
        counter.Increment();
    }
}


using System;

public delegate void TaskCompletedHandler();

class TaskRunner
{
    public event TaskCompletedHandler TaskCompleted;

    public void RunTask()
    {
        Console.WriteLine("Задача выполняется...");

        OnTaskCompleted();
    }

    protected virtual void OnTaskCompleted()
    {
        if (TaskCompleted != null)
        {
            TaskCompleted();
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        TaskRunner runner = new TaskRunner();

        runner.TaskCompleted += () =>
        {
            Console.WriteLine("Задача завершена!");
        };

        runner.RunTask();
    }
}

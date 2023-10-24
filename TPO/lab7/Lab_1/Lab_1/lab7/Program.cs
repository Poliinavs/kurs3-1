using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lab7
{
    public class Calculator
    {
        public double Add(double num1, double num2)
        {
            return num1 + num2;
        }

        public double Subtract(double num1, double num2)
        {
            return num1 - num2;
        }

        public double Multiply(double num1, double num2)
        {
            return num1 * num2;
        }

        public double Divide(double num1, double num2)
        {
            if (num2 == 0)
            {
                 throw new ArgumentException("Деление на ноль!");
               // Console.WriteLine("Деление на ноль!");
            }
            return num1 / num2;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Calculator calculator = new Calculator();

            Console.WriteLine("Выберите операцию:");
            Console.WriteLine("1. Сложение");
            Console.WriteLine("2. Вычитание");
            Console.WriteLine("3. Умножение");
            Console.WriteLine("4. Деление");

            int choice = int.Parse(Console.ReadLine());

            Console.Write("Введите первое число: ");
            double num1 = double.Parse(Console.ReadLine());

            Console.Write("Введите второе число: ");
            double num2 = double.Parse(Console.ReadLine());

            double result = 0;

            switch (choice)
            {
                case 1:
                    result = calculator.Add(num1, num2);
                    break;
                case 2:
                    result = calculator.Subtract(num1, num2);
                    break;
                case 3:
                    result = calculator.Multiply(num1, num2);
                    break;
                case 4:
                    try
                    {
                        result = calculator.Divide(num1, num2);
                    }
                    catch (ArgumentException e)
                    {
                        Console.WriteLine(e.Message);
                        return;
                    }
                    break;
                default:
                    Console.WriteLine("Неверный выбор операции.");
                    return;
            }

            Console.WriteLine("Результат: " + result);
        }
    }
}

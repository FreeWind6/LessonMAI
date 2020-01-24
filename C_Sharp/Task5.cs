using System;
using System.Collections.Generic;

/*
 * Написать программу, считающую Фибоначчи с использованием указателей.
 * Последовательность начинается с 0.
*/

namespace SystemProgramming
{
    class Task5 : ITask
    {
        private int number = 5;

        private int countNumber;

        public int GetNumber()
        {
            return number;
        }

        public override string ToString()
        {
            return "Написать программу, считающую Фибоначчи с использованием указателей. Последовательность начинается с 0.";
        }

        unsafe public void Start()
        {
            try
            {
                Console.Write("Введите количество символов в последовательности: ");
                countNumber = Convert.ToInt32(Console.ReadLine());
            }
            catch (FormatException)
            {
                countNumber = 100;
            }
            countNumber--;

            int* fib = stackalloc int[countNumber];
            int* p = fib;
            *p++ = *p++ = 1;
            for (int i = 2; i < countNumber; ++i, ++p)
            {
                *p = p[-1] + p[-2];
            }

            Console.WriteLine();
            Console.WriteLine("Ряд Фибоначчи:");
            Console.Write("0 ");
            for (int i = 0; i < countNumber; ++i)
            {
                Console.Write("{0} ", fib[i]);
            }
            Console.WriteLine();
            for (int i = 0; i <= countNumber; ++i)
            {
                Console.Write( Fibonachi(i) + " " );
            }
            Console.WriteLine();
        }

        int Fibonachi(int n)
        {
            int a = 0;
            int b = 1;
            int tmp;

            for (int i = 0; i < n; i++)
            {
                tmp = a;
                a = b;
                b += tmp;
            }

            return a;
        }
    }
}

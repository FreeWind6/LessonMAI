using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//Имеются 3 стека. Один из них пустой. Другие два заполнены 10 случайными числами от 1 до 1000. Написать программу которая перенесет числа из 2-х заполненных стеков в пустой так, чтобы сначала в стеке шли четные числа, а затем нечетные. И отсортировать их по возростанию

namespace ConsoleApplication7
{
    class Program
    {
        static void Main(string[] args)
        {
            Random random = new Random();

            int[] randommas1 = new int[10]; //пустой массив для заполнение
            int[] randommas2 = new int[10]; //пустой массив для заполнение

            for (int i = 0; i < 10; i++)
            {
                randommas1[i] = random.Next(1000);
                randommas2[i] = random.Next(1000);
            }

            Console.WriteLine("Стэк 1");
            Stack<int> stack1 = new Stack<int>(randommas1);
            foreach (var i in stack1)
            {
                Console.WriteLine(i);
            }

            Console.WriteLine();
            Console.WriteLine("Стэк 2");
            Stack<int> stack2 = new Stack<int>(randommas2);
            foreach (var i in stack2)
            {
                Console.WriteLine(i);
            }


            Stack<int> stack3 = new Stack<int>();
            foreach (var i in stack1)
            {
                stack3.Push(i);
            }

            foreach (var i in stack2)
            {
                stack3.Push(i);
            }

            Console.WriteLine();
            Console.WriteLine("Стэк 3");
            Console.WriteLine("Чётные");
            foreach (var i in stack3)
            {
                if (i % 2 == 0)
                {
                    Console.WriteLine(i);
                }
            }

            Console.WriteLine();
            Console.WriteLine("Не чётные");
            foreach (var i in stack3)
            {
                if (i % 2 != 0)
                {
                    Console.WriteLine(i);
                }
            }

            Console.ReadLine();
        }
    }
}

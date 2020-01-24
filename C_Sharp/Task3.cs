using System;
using System.IO;
using System.Text.RegularExpressions;
using System.Threading;

/*
 * Написать программу для удаления комментариев и тегов из html-файла и обеспечить правильную подстановку для знаков < > & “
 * Результат должен быть записан в новый файл.
*/

namespace SystemProgramming
{
    class Task3 : ITask
    {
        private int number = 3;
        private string path, text;
        static Random random = new Random();

        public int GetNumber()
        {
            return number;
        }

        public override string ToString()
        {
            return "Написать программу для удаления комментариев и тегов из html-файла и обеспечить правильную подстановку для знаков <, >, &, “. Результат должен быть записан в новый файл.";
        }

        public void Start()
        {
            Console.WriteLine("Вставьте полный или относительный от exe файла путь к html файлу. По умолчанию: ./index.html");

            while (true)
            {
                path = Console.ReadLine();

                if(path == "")
                {
                    path = "index.html";
                }

                if (File.Exists(path))
                {
                    Console.WriteLine();
                    Console.WriteLine("Файл найден");
                    break;
                }
                else
                {
                    Console.WriteLine("Файл не найден. Введите путь еще раз!");
                    path = "";
                }
            }
            
            try
            {
                using (StreamReader sr = new StreamReader(path, System.Text.Encoding.Default))
                {
                    text = sr.ReadToEnd();
                }
                Console.WriteLine("Файл прочитан");
                Thread.Sleep(random.Next(3, 9) * 100);

                text = Regex.Replace(text, @"<[^>!]+?>|<!--([^-]*)-->", "${1}");
                Console.WriteLine("Удаляю теги");
                Thread.Sleep(random.Next(3, 9) * 100);

                text = Regex.Replace(text, @"[\s\r\n]+", " ").Trim();
                Console.WriteLine("Удаляю лишние переносы строк");
                Thread.Sleep(random.Next(3, 9) * 100);

                using (StreamWriter sw = new StreamWriter(path + "-untags.txt", false, System.Text.Encoding.Default))
                {
                    sw.WriteLine(text);
                }
                Console.WriteLine("Файл записан. Новый файл: " + path + "-untags.txt");
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }


        }

    }
}

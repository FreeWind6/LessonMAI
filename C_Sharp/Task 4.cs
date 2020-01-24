using System;
using System.IO;
using System.Xml.Serialization;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Json;




namespace ConsoleApp
{

    [Serializable]
    public class Disciplines
    {
        public string Disciplin;

        public Disciplines() { }

        public Disciplines(string disciplin) {
            Disciplin = disciplin;
        }
    }
       
    [Serializable]
    public class Courses
    {
        public int Cours;

        public Courses() { }

        public Courses(int cours)
        {
            Cours = cours;
        }
    }

    [Serializable]
    public class Groups
    {
        public string Group;

        public Groups() { }
        public Groups(string group)
        {
            Group = group;
        }
    }

    [Serializable]
    public class Person
    {
        public string Name;
        public int Age;
        public Disciplines Disciplines;
        public Courses Courses;
        public Groups Groups;

        // стандартный конструктор без параметров
        public Person()
        { }

        public Person(string name, int age, Disciplines dis, Courses cour, Groups grou)
        {
            Name = name;
            Age = age;
            Disciplines = dis;
            Courses = cour;
            Groups = grou;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Person person1 = new Person("Tom", 21, new Disciplines("All"), new Courses(1), new Groups("IBT"));
            Person person2 = new Person("Bill", 11, new Disciplines("All"), new Courses(2), new Groups("IBT"));
            Person[] people = new Person[] {person1, person2};

            XmlSerializer formatter = new XmlSerializer(typeof(Person[]));

            using (FileStream fs = new FileStream("people.xml", FileMode.OpenOrCreate))
            {
                formatter.Serialize(fs, people);
            }

            using (FileStream fs = new FileStream("people.xml", FileMode.OpenOrCreate))
            {
                Person[] newpeople = (Person[])formatter.Deserialize(fs);

                foreach (Person p in newpeople)
                {
                    Console.WriteLine("Имя: {0} --- Возраст: {1} --- Дисциплина: {2} --- Курс: {3} --- Группа: {3}", p.Name, p.Age, p.Disciplines.Disciplin, p.Courses.Cours, p.Groups.Group);
                }
            }

            //JSON
					DataContractJsonSerializer jsonFormatter = new DataContractJsonSerializer(typeof(Person[]));

                       using (FileStream fs = new FileStream("people.json", FileMode.OpenOrCreate))
                       {
                           jsonFormatter.WriteObject(fs, people);
                       }


            /*           using (FileStream fs = new FileStream("people.json", FileMode.OpenOrCreate))
                       {
                           Person[] newpeople = (Person[])jsonFormatter.ReadObject(fs);

                           foreach (Person p in newpeople)
                           {
                               Console.WriteLine("Студент: {0} --- Группа: {1} --- Курс: {2} --- Предметы: {3}", p.Student, p.Group, p.Courses, p.Disciplines);
                           }
                       }
             */


            Console.ReadLine();
        }
    }
}

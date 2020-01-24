import java.util.Scanner;

//Найдите самое длинное слово в введенной строке и вывести его на консоль. Предполагается, что слова разделены пробелами
public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        System.out.print("Введите предложение: ");
        String string = scanner.nextLine();

        long startTime = System.currentTimeMillis();
        splitMethod(string);
        long timeSpent = System.currentTimeMillis() - startTime;
        System.out.println("программа выполнялась " + timeSpent + " миллисекунд");

        System.out.println();

        long startTime2 = System.currentTimeMillis();
        BufferMethod(string);
        long timeSpent2 = System.currentTimeMillis() - startTime2;
        System.out.println("программа выполнялась " + timeSpent2 + " миллисекунд");
    }


    //1 способ решения
    private static void splitMethod(String string) {
        String[] mas_string = string.split("[\\s,.!?]+");

        String max = mas_string[0];

        for (int i = 1; i < mas_string.length; ++i) {
            if (max.length() < mas_string[i].length())
                max = mas_string[i];
        }

        System.out.println("Самое длинное слово без split: " + max);
    }

    //2 способ решения
    private static void BufferMethod(String string) {
        StringBuffer stringBuffer = new StringBuffer(string);
        stringBuffer.reverse();

        String[] shaSplit = Main.split(stringBuffer);
        String shaMax = shaSplit[0];

        for (int i = 1; i < shaSplit.length; ++i) {
            if (shaMax.length() < shaSplit[i].length())
                shaMax = shaSplit[i];
        }

        System.out.println("Самое длинное слово при помощи split: " + shaMax);
    }

    //собственная реализация split
    public static String[] split(StringBuffer s) {
        int count = 0;
        char[] c = s.toString().toCharArray();

        for (int i = 0; i < c.length; i++) {
            if (c[i] == ' ') {
                count++;
            }
        }
        String temp = "";
        int k = 0;
        String[] rev = new String[count + 1];
        for (int i = c.length - 1; i >= 0; i--) {
            if (c[i] == ' ') {
                rev[k++] = temp;
                temp = "";
            } else
                temp = temp + c[i];
        }
        rev[k] = temp;
        return rev;
    }

}

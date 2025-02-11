import java.util.Scanner;
import java.lang.Character;
import static java.lang.System.exit;

class Main {
    public static void main(String[] args) {
        String strIn;
        String answer;
        System.out.println("Choose operation: (Write 1-3)");
        System.out.println("1. Compress");
        System.out.println("2. Decompress");
        System.out.println("3. Exit");
        Scanner sc = new Scanner(System.in);
        answer = sc.nextLine();
        switch (answer) {
            case "1" -> {
                System.out.println("Enter string to compress: ");
                strIn = sc.nextLine();
                if (strIn.isEmpty()) {
                    System.out.println("String is empty");
                } else {
                    System.out.println("Output: " + compress(strIn));
                }
            }
            case "2" -> {
                System.out.println("Enter string to decompress: ");
                strIn = sc.nextLine();
                if (strIn.isEmpty()) {
                    System.out.println("String is empty");
                } else {
                    try {
                        System.out.println("Output: " + deCompress(strIn));
                    } catch (IllegalArgumentException e) {
                        System.out.println("Invalid input: " + e.getMessage());
                    }
                }
            }
            case "3" -> exit(0); // Exit
            default ->    // Mistake
                    System.out.println("Invalid input. Try again!");
        }
        sc.close();
    }


    private static String compress(String str) {
        int strLen = str.length();

        char[] charIn = str.toCharArray();
        StringBuilder result = new StringBuilder();
        int tempInt = 1;

        for (int i = 0; i < strLen; i++) {
            if (charIn[i] < 'a' || charIn[i] > 'z') { // Ensure lowercase letters only
                System.out.println("Only lowercase letters allowed");
                exit(0);
            }
            if (i < strLen - 1 && charIn[i] == charIn[i + 1]) { // Count repetitions
                tempInt++;
            } else {
                result.append(charIn[i]).append(tempInt);
                tempInt = 1;
            }
        }
        return result.toString();

    }

    private static String deCompress(String str) {
        int strLen = str.length();
        StringBuilder result = new StringBuilder();
        int i = 0; // While loop counter

        while (i < strLen) {
            char letter = str.charAt(i++);

            // Ensure first character is a lowercase letter
            if (letter < 'a' || letter > 'z') {
                System.out.println("Invalid format: Expected letter before number");
                exit(0);
            }

            StringBuilder countStr = new StringBuilder();

            // Extract multi-digit number
            while (i < strLen && Character.isDigit(str.charAt(i))) {
                countStr.append(str.charAt(i++));
            }

            if (countStr.isEmpty()) {
                System.out.println("Invalid format: Missing number after letter");
                exit(0);
            }

            int count = Integer.parseInt(countStr.toString());

            if (count <= 0) {
                System.out.println("Count must be greater than 0");
                exit(0);
            }

            result.append(String.valueOf(letter).repeat(count)); // Append letter 'count' times
        }
        return result.toString();
    }
}
package IOJava1;
//C:\instit\kurs3_1\TPO\lab5\String\directory_structure.txt
import java.io.*;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
      /*  if (args.length != 1) {
            System.out.println("Пожалуйста, укажите путь к директории или текстовому файлу.");
            return;
        }*/
        Scanner scanner = new Scanner(System.in);

        System.out.print("Введите путь к директории или текстовому файлу: ");
        String path = scanner.nextLine();

        scanner.close();

      //  File directory = new File(directoryPath);

      //  String path = args[0];
        File file = new File(path);

        if (file.exists() && file.isFile() && path.endsWith(".txt")) {
            analyzeTextFile(file);
        } else if (file.exists() && file.isDirectory()) {
            generateDirectoryStructure(file);
        } else {
            System.out.println("Указанный путь не является допустимым.");
        }
    }

    private static void analyzeTextFile(File file) {
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            String line;
            int folderCount = 0;
            int fileCount = 0;
            int totalFileLength = 0;

            while ((line = reader.readLine()) != null) {
                if (line.contains("|-----")) {
                    folderCount++;
                } else if (!line.trim().isEmpty()) {
                    fileCount++;
                    totalFileLength += line.trim().length();
                }
            }

            double averageFilesPerFolder = (folderCount == 0) ? 0 : (double) fileCount / folderCount;
            double averageFileNameLength = (fileCount == 0) ? 0 : (double) totalFileLength / fileCount;

            System.out.println("Количество папок: " + folderCount);
            System.out.println("Количество файлов: " + fileCount);
            System.out.println("Среднее количество файлов в папке: " + averageFilesPerFolder);
            System.out.println("Средняя длина названия файла: " + averageFileNameLength);
        } catch (IOException e) {
            System.out.println("Ошибка при чтении файла: " + e.getMessage());
        }
    }

    private static void generateDirectoryStructure(File directory) {
        try {
            FileWriter writer = new FileWriter("directory_structure.txt");
            writeDirectoryStructure(directory, "", writer);
            writer.close();
            System.out.println("Структура директории успешно записана в файл directory_structure.txt.");
        } catch (IOException e) {
            System.out.println("Ошибка при записи в файл: " + e.getMessage());
        }
    }

    private static void writeDirectoryStructure(File directory, String indent, FileWriter writer) throws IOException {
        writer.write(indent + directory.getName() + "\n");
        indent += "    |";

        File[] files = directory.listFiles();
        if (files != null) {
            for (File file : files) {
                if (file.isDirectory()) {
                    writeDirectoryStructure(file, indent, writer);
                } else {
                    writer.write(indent + "-----" + file.getName() + "\n");
                }
            }
        }
    }
}

/*
package IOJava1;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Введите путь к директории: ");
        String directoryPath = scanner.nextLine();

        scanner.close();

        File directory = new File(directoryPath);

        if (!directory.exists() || !directory.isDirectory()) {
            System.out.println("Указанный путь не является директорией.");
            return;
        }

        try {
            FileWriter writer = new FileWriter("directory_structure.txt");
            writeDirectoryStructure(directory, "", writer);
            writer.close();
            System.out.println("Структура директории успешно записана в файл directory_structure.txt.");
        } catch (IOException e) {
            System.out.println("Ошибка при записи в файл: " + e.getMessage());
        }
    }

    private static void writeDirectoryStructure(File directory, String indent, FileWriter writer) throws IOException {
        writer.write(indent + directory.getName() + "\n");
        indent += "    |";

        File[] files = directory.listFiles();
        if (files != null) {
            for (File file : files) {
                if (file.isDirectory()) {
                    writeDirectoryStructure(file, indent, writer);
                } else {
                    writer.write(indent + "-----" + file.getName() + "\n");
                }
            }
        }
    }
}
*/

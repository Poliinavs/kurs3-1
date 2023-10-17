package String;

import java.util.Arrays;
import java.util.Comparator;
import java.util.regex.Pattern;

public class Main {
    public static void main(String[] args) {
        System.out.println("---------------MainTask" +
                "--------------------------");
        //Вывести все предложения в порядке возрастания количества слов:
        String text = " Это текст, в котором мы сортируем предложения по количеству слов. Слова п. В предложениях пп. Это.";

        String[] sentences = text.split("[.!?]");

        Arrays.sort(sentences, Comparator.comparing(s -> s.split("\\s+").length));

        for (String sentence : sentences) {
            System.out.println(sentence);
        }
        //
        System.out.println("----------------------");
        //Все слова текста рассортировать по возрастанию количества заданной буквы в слове.
        // Слова с одинаковым количеством расположить в алфавитном порядке.
        String text1 = "Это текст для задачи. Слова в тексте будут отсортированы.";

        // Разделение текста на слова
        String[] words = text1.split("\\s+");

        char targetLetter = 'о';

        Arrays.sort(words, Comparator.comparing((String word) -> {
            int count = 0;
            for (char letter : word.toCharArray()) {
                if (Character.toLowerCase(letter) == Character.toLowerCase(targetLetter)) {
                    count++;
                }
            }
            return count;
        }).thenComparing(String.CASE_INSENSITIVE_ORDER));

        for (String word : words) {
            System.out.println(word);
        }
        System.out.println("----------------------3");
        // Напечатать слова текста в алфавитном порядке по первой букве.
        // Слова, начинающиеся с новой буквы, печатать с красной строки
        String text3 = "это текст для задачи. слова  в тексте будут сова отсортированы.";

        String[] words3 = text3.split("\\s+");

        // Сортировка слов в алфавитном порядке
        Arrays.sort(words3);

        char currentLetter = 0; // Текущая буква
        for (String word : words3) {
            char firstLetter = Character.toLowerCase(word.charAt(0));
            if (firstLetter != currentLetter) {

                System.out.println();
                currentLetter = firstLetter;
            }
            System.out.print(word + " ");
        }
        System.out.println();
        System.out.println("----------------------4");
      //  В каждом предложении текста поменять местами первое слово с последним, не изменяя длину предложения
        String text4 = "Это первое предложение. Второе предложение. Третье предложение.";

        // Разделение текста на предложения
        String[] sentences4 = text4.split("[.!?]");

        StringBuilder result = new StringBuilder();

        for (String sentence : sentences4) {
            String[] words4 = sentence.trim().split("\\s+");
            if (words4.length >= 2) {

                String firstWord = words4[0];
                words4[0] = words4[words4.length - 1];
                words4[words4.length - 1] = firstWord;

                String modifiedSentence = String.join(" ", words4);
                result.append(modifiedSentence).append(". "); //  точку после предложения
            } else {
                result.append(sentence).append(". ");
            }
        }

        System.out.println(result.toString());
        System.out.println();
        System.out.println("----------------------5");
        //12.  Из текста удалить все слова заданной длины, начинающиеся на согласную букву.
        String text5 = "Это текст для  Удалить слова длиной восемь букв.";

        int targetLength = 6; // Длина слова, которое нужно удалить
        String consonants = "бвгджзйклмнпрстфхцчшщ"; // Согласные буквы

        String[] words5 = text5.split("\\s+");

        StringBuilder result5 = new StringBuilder();

        for (String word : words5) {
            String cleanedWord = word;

            if (word.length() == targetLength) {
                char firstChar = Character.toLowerCase(word.charAt(0));
                if (consonants.indexOf(firstChar) != -1) {
                    continue;
                }
            }

            result5.append(cleanedWord).append(" ");
        }

        String cleanedText = result5.toString().trim(); // Удаляем лишний пробел в конце

        System.out.println(cleanedText);



    }
}
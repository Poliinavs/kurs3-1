package Collections;

public class Main {
    public static void main(String[] args) {


        Bouquet bouquet = new Bouquet();

        // Добавление цветов и аксессуаров в букет
        bouquet.addFlower(new Flower("Роза", 30.0, 5, 10.0));
        bouquet.addFlower(new Flower("Тюльпан", 25.0, 4, 5.0));
        bouquet.addFlower(new Flower("Лилия", 40.0, 6, 12.0));
        bouquet.addAccessory(new Accessory("Ленточка", 2.0));
        bouquet.addAccessory(new Accessory("Коробка", 3.0));

        System.out.println("Стоимость букета: " + bouquet.calculateCost());

        System.out.println("Сортировка цветов по свежести:");
        bouquet.sortByFreshness();
        for (Flower flower : bouquet.findFlowersByStemLength(25.0, 35.0)) {
            System.out.println("Цветок: " + flower.getName() + ", Стебель: " + flower.getStemLength());
        }
    }
}
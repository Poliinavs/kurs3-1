package Collections;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

class Bouquet {
    private List<Flower> flowers;
    private List<Accessory> accessories;

    public Bouquet() {
        flowers = new ArrayList<>();
        accessories = new ArrayList<>();
    }

    public void addFlower(Flower flower) {
        flowers.add(flower);
    }

    public void addAccessory(Accessory accessory) {
        accessories.add(accessory);
    }

    public double calculateCost() {
        double flowerCost = flowers.stream().mapToDouble(Flower::getPrice).sum();
        double accessoryCost = accessories.stream().mapToDouble(Accessory::getPrice).sum();
        return flowerCost + accessoryCost;
    }

    public void sortByFreshness() {
        flowers.sort(Comparator.comparingInt(Flower::getFreshness));
    }

    public List<Flower> findFlowersByStemLength(double minLength, double maxLength) {
        List<Flower> result = new ArrayList<>();
        for (Flower flower : flowers) {
            if (flower.getStemLength() >= minLength && flower.getStemLength() <= maxLength) {
                result.add(flower);
            }
        }
        return result;
    }
}
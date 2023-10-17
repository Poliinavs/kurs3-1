package Collections;
class Flower {
    private String name;
    private double stemLength;
    private int freshness;
    private double price;

    public Flower(String name, double stemLength, int freshness, double price) {
        this.name = name;
        this.stemLength = stemLength;
        this.freshness = freshness;
        this.price = price;
    }

    public String getName() {
        return name;
    }

    public double getStemLength() {
        return stemLength;
    }

    public int getFreshness() {
        return freshness;
    }

    public double getPrice() {
        return price;
    }
}
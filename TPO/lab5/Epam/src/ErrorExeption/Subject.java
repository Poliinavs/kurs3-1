package ErrorExeption;
class Subject {
    private String name;
    private double grade;

    public Subject(String name, double grade) {
        this.name = name;
        if (grade < 0 || grade > 10) {
            throw new IllegalArgumentException("Оценка должна быть между 0 и 10");
        }
        this.grade = grade;
    }

    public String getName() {
        return name;
    }

    public double getGrade() {
        return grade;
    }
}
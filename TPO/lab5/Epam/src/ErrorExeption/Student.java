package ErrorExeption;
import java.util.ArrayList;
import java.util.List;

class Student {
    private String name;
    private List<Subject> subjects = new ArrayList<>();

    public Student(String name) {
        this.name = name;
    }

    public void addSubject(Subject subject) throws NoSubjectsException {
        if (subject != null) {
            subjects.add(subject);
        } else {
            throw new NoSubjectsException("У студента должен быть хотя бы один предмет");
        }
    }
    public List<Subject> getSubjects() {
        return subjects;
    }

    public double calculateAverageGrade() {
        if (subjects.isEmpty()) {
            throw new IllegalArgumentException("Отсутствуют предметы у студента");
        }

        double totalGrade = 0;
        for (Subject subject : subjects) {
            totalGrade += subject.getGrade();
        }

        return totalGrade / subjects.size();
    }
    public class NoSubjectsException extends Exception {
        public NoSubjectsException(String message) {
            super(message);
        }
    }
}
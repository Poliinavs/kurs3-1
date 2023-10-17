package ErrorExeption;
import java.util.ArrayList;
import java.util.List;

class Group {
    public String name;
    public List<Student> students = new ArrayList<>();

    public Group(String name) {
        this.name = name;
    }


    public void addStudent(Student student) throws NoStudentsInGroupException {
        if (student != null) {
            students.add(student);
        } else {
            throw new NoStudentsInGroupException("Отсутствие студентов в группе");
        }
    }

  /*  public double calculateAverageGradeBySubject(String subjectName, String GroupName, String FacultyName ) throws NoStudentsInGroupException {
        if (students.isEmpty()) {
            throw new NoStudentsInGroupException("Отсутствие студентов в группе");
        }
        if (students.isEmpty()) {
            throw new NoStudentsInGroupException("Отсутствие студентов в группе");
        }

        double totalGrade = 0;
        int studentCount = 0;
        for (Student student : students) {
            for (Subject subject : student.getSubjects()) {
                if (subject.getName().equals(subjectName)) {
                    totalGrade += subject.getGrade();
                    studentCount++;
                }
            }
        }

        if (studentCount == 0) {
            throw new IllegalArgumentException("Нет студентов с предметом: " + subjectName);
        }

        return totalGrade / studentCount;
    }*/
    public class NoStudentsInGroupException extends Exception {
        public NoStudentsInGroupException(String message) {
            super(message);
        }
    }
}

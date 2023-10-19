package Classes;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class StudentArray {
    private List<Student> students = new ArrayList<>();

    public void addStudent(Student student) {
        students.add(student);
    }

    public List<Student> getStudentsByFaculty(String faculty) {
        List<Student> result = new ArrayList<>();
        for (Student student : students) {
            if (student.faculty.equals(faculty)) {
                result.add(student);
            }
        }
        return result;
    }

    public List<Student> getStudentsByFacultyAndCourse(String faculty, int course) {
        List<Student> result = new ArrayList<>();
        for (Student student : students) {
            if (student.faculty.equals(faculty) && student.getCourse() == course) {
                result.add(student);
            }
        }
        return result;
    }

    public List<Student> getStudentsBornAfterYear(int year) {
        List<Student> result = new ArrayList<>();
        for (Student student : students) {
            if (student.getBirthDate().getYear() + 1900 > year) {
                result.add(student);
            }
        }
        return result;
    }

    public List<Student> getStudentsByGroup(String group) {
        List<Student> result = new ArrayList<>();
        for (Student student : students) {
            if (student.getGroup().equals(group)) {
                result.add(student);
            }
        }
        return result;
    }
}
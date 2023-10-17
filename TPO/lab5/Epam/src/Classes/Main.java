package Classes;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

public class Main {
    public static void main(String[] args) throws ParseException {
        SimpleDateFormat dateFormat = new SimpleDateFormat("dd-MM-yyyy");
        StudentArray studentArray = new StudentArray();


        Student student1 = new Student(1, "Иванов", "Иван", "Иванович", dateFormat.parse("15-03-1998"), "Адрес1", "123-456-789", "Факультет1", 1, "Группа1");
        studentArray.addStudent(student1);

        Student student2 = new Student(2, "Петров", "Петр", "Петрович", dateFormat.parse("20-05-1997"), "Адрес2", "987-654-321", "Факультет2", 2, "Группа2");
        studentArray.addStudent(student2);

        // Выводим список студентов заданного факультета
        List<Student> facultyStudents = studentArray.getStudentsByFaculty("Факультет1");
        for (Student student : facultyStudents) {
            System.out.println(student);
        }

        // Выводим список студентов для каждого факультета и курса
        List<Student> facultyAndCourseStudents = studentArray.getStudentsByFacultyAndCourse("Факультет2", 2);
        for (Student student : facultyAndCourseStudents) {
            System.out.println(student);
        }

        // Выводим список студентов, родившихся после заданного года
        List<Student> bornAfterYearStudents = studentArray.getStudentsBornAfterYear(1997);
        for (Student student : bornAfterYearStudents) {
            System.out.println(student);
        }

        // Выводим список учебной группы
        List<Student> groupStudents = studentArray.getStudentsByGroup("Группа1");
        for (Student student : groupStudents) {
            System.out.println(student);
        }
    }
}

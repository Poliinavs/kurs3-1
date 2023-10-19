package ErrorExeption;
import java.util.ArrayList;
import java.util.List;










public class Main {
    public static void main(String[] args) {
        try {
         /*   //1 Добавление пустого факультета
            University university = new University("My University");
            Faculty faculty1 = null;
            //university.addFaculty(faculty1);

            // 2 Отсутствие групп на факультете
            Faculty faculty = new Faculty("Science Faculty");
            Group group1 = null;
            //  faculty.addGroup(group1);

            //3 Отсутствие студентов в группе
            Group group = new Group("Physics Group");
            Student student1 = null;
            group.addStudent(student1);*/
            //Оценка ниже 0 или выше 10
            Subject physics = new Subject("Physics", 9.0);
            Subject math = new Subject("Math", 8);
          //  Subject math1 = new Subject("Math", -1);

            //Ошибка:Отсутсвие предметов у студента (должен быть хотя бы один),
            // Функция: Посчитать средний балл по всем предметам студента
            Student student = new Student("John");
            Student student1 = new Student("John");

            student.addSubject(physics);
            student.addSubject(math);

            student1.addSubject(physics);
            student1.addSubject(math);

            double studentAvgGrade = student.calculateAverageGrade();
            System.out.println("Средний балл студента: " + studentAvgGrade);

            //Отсутствие групп на факультете, Отсутствие студентов в группе
            //Функция: Посчитать средний балл по конкретному предмету в конкретной группе и на конкретном факультете

            // Расчет средней оценки по факультету и группе
            University university = new University("My University");
            University university1 = new University("My University");
            Faculty faculty = new Faculty("Science");
            Faculty faculty1 = new Faculty("Biology");
            Group group = new Group("Physics");
            Group group1 = new Group("Biol");



            group.addStudent(student);
            faculty.addGroup(group);
            group.addStudent(student1);
            faculty.addGroup(group1);

            university.addFaculty(faculty);
            university.addFaculty(faculty1);


            double groupAvgGrade = university.calculateAverageGradeBySubject("Math","Physics","Science");
            System.out.println("Средний балл по факультету и группе по физике: " + groupAvgGrade);


//Посчитать средний балл по предмету для всего университета

           double universityAvgGrade = university1.calculateAverageGradeBySubjectInUniversity("Physics");

            System.out.println(" средний балл по предмету для всего университета по физике: " + groupAvgGrade);








        }
        catch(Faculty.InvalidGradeException e) {
            System.err.println("Ошибка: " + e.getMessage());
        }
        catch(Exception e) {
            System.err.println("Ошибка: " + e.getMessage());
        }

    }
}
package ErrorExeption;

import java.util.ArrayList;
import java.util.List;

class University {
    private String name;
    private List<Faculty> faculties = new ArrayList<>();

    public University(String name) {
        this.name = name;
    }

    public void addFaculty(Faculty faculty) {
        if (faculty != null) {
            faculties.add(faculty);
        } else {
            throw new IllegalArgumentException("Отсутствие факультетов в университете");
        }
    }
    public double calculateAverageGradeBySubjectInUniversity(String subjectName) throws Exception {
        double totalGrade = 0;
        int studentCount = 0;

        for (Faculty faculty : faculties) {
            if (faculty.groups.isEmpty()) {
                throw new Exception("Отсутствие групп");
            }
            for (Group group : faculty.groups) {
                if (group.students.isEmpty()) {

                    throw new Exception("Отсутствие студентов");
                }
                for (Student student : group.students) {
                    for (Subject subject : student.getSubjects()) {
                        if (subject.getName().equals(subjectName)) {
                            totalGrade += subject.getGrade();
                            studentCount++;
                        }
                    }
                }
            }
        }

        if (studentCount == 0) {
            throw new Exception("Нет студентов с предметом: " + subjectName);
        }

        return totalGrade / studentCount;
    }



    public double calculateAverageGradeBySubject(String subjectName, String groupName, String facultyName)
            throws NoStudentsInGroupException, NoGroupException, NoFacultyException {
        if (faculties.isEmpty()) {
            throw new NoFacultyException("Отсутствие факультетов");
        }

        double totalGrade = 0;
        int studentCount = 0;

        for (Faculty faculty : faculties) {
            if (faculty.name.equals(facultyName)) {
                if (faculty.groups.isEmpty()) {
                    throw new NoGroupException("Отсутствие групп");
                } else {
                    for (Group group : faculty.groups) {
                        if (group.name.equals(groupName)) {
                            if (group.students.isEmpty()) {
                                throw new NoStudentsInGroupException("Отсутствие студентов");
                            } else {
                                for (Student student : group.students) {
                                    for (Subject subject : student.getSubjects()) {
                                        if (subject.getName().equals(subjectName)) {
                                            totalGrade += subject.getGrade();
                                            studentCount++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if (studentCount == 0) {
            throw new NoStudentsInGroupException("Нет студентов с предметом: " + subjectName);
        }

        return totalGrade / studentCount;
    }

    public class NoStudentsInGroupException extends Exception {
        public NoStudentsInGroupException(String message) {
            super(message);
        }
    }

    public class NoFacultyException extends Exception {
        public NoFacultyException(String message) {
            super(message);
        }
    }

    public class NoGroupException extends Exception {
        public NoGroupException(String message) {
            super(message);
        }
    }
}



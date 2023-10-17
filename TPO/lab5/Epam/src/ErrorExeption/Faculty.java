package ErrorExeption;
import java.util.ArrayList;
import java.util.List;

class Faculty {
    public String name;
    public List<Group> groups = new ArrayList<>();

    public Faculty(String name) {
        this.name = name;
    }

    public void addGroup(Group group) throws InvalidGradeException {
        if (group != null) {
            groups.add(group);
        } else {
            throw new InvalidGradeException("Отсутствие групп на факультете");
        }
    }
    public class InvalidGradeException extends Exception {
        public InvalidGradeException(String message) {
            super(message);
        }
    }



}

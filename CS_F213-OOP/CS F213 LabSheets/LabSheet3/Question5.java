package LabSheet3;

class Student {
    int id, age;
    String name;
    int marks[] = { 0, 0, 0 };

    Student(int inputId, String inputName, int inputAge) {
        id = inputId;
        name = inputName;
        age = inputAge;
    }

    void setMarks(int x, int y, int z){
        marks[0] = x;
        marks[1] = y;
        marks[2] = z;
    }

    void studentDetails(){
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("ID: " + id);
        System.out.println(marks);
    }
}

public class Question5 {
    public static void main(String args[]){
        Student raj = new Student(105, "Raj", 21);
        raj.setMarks(67, 90, 65);
        Student gopal = new Student(105, "Gopal", 21);
        gopal.setMarks(70, 75, 55);

        raj.studentDetails();
        gopal.studentDetails();
    }
}

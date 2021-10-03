class Student{
    static Student[] students=new Student[3];
    static int studentcount=0;
    String name;
    String studentId;
    int questionsAttended;
    public Student(String name, String studentId, int questionsAttended) {
        this.name = name;
        this.studentId = studentId;
        this.questionsAttended = questionsAttended;
        studentcount++;
    }
    public static double avg(){
        double avg=0;
        int k=0;
        for (int i = 0; i < studentcount; i++) {
            k+=students[i].questionsAttended;
        }
        avg=k/studentcount;
        return avg;
    }
}
public class StudentMain {
    
    public static void main(String[] args){
        Student.students[0]=new Student("Yash","S20200010234",7);
        Student.students[1]=new Student("Jack","S20200010235",8);
        Student.students[2]=new Student("Jill","S20200010236",9);
        double average;
        average=Student.avg();
        System.out.println(average);
    }
}

class Student{
    private int rollno;
    private String firstName;
    private String lastName;
    public int getRollno() {
        return rollno;
    }
    public void setRollno(int rollno) {
        this.rollno = rollno;
    }
    public Student(int rollno, String firstName, String lastName) {
        this.rollno = rollno;
        this.firstName = firstName;
        this.lastName = lastName;
    }
    public String getFirstName() {
        return firstName;
    }
    @Override
    public String toString() {
        return "Student [firstName=" + firstName + ", lastName=" + lastName + ", rollno=" + rollno + "]";
    }
    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }
    public String getLastName() {
        return lastName;
    }
    public void setLastName(String lastName) {
        this.lastName = lastName;
    }
    
}
abstract class StudentRecords{
    Student[] record=new Student[10];
    int studcounter=0;
    public void addStudent(Student student) {
        record[studcounter++]=student;
    }
    public abstract Student searchStudentByFname(String firstName);
    public abstract Student searchStudentByLname(String LastName);
}
class SimpleSortStudentRecords extends StudentRecords {
    
    public SimpleSortStudentRecords simpleSortFname(){
        SimpleSortStudentRecords x=this;
        for(int i=0;i<x.studcounter;i++){
            for(int j=i;j<x.studcounter;j++){
                if (x.record[i].getFirstName().compareTo(x.record[j].getFirstName())>0) {
                    Student y=x.record[i];
                    x.record[i]=x.record[j];
                    x.record[j]=y;
                    
                }
            }
        }
        return x;
    }
    public SimpleSortStudentRecords simpleSortLname(){
        SimpleSortStudentRecords x=this;

        for(int i=0;i<x.studcounter;i++){
            for(int j=i;j<x.studcounter;j++){
                if (x.record[i].getLastName().compareTo(x.record[j].getLastName())>0) {
                    Student y=x.record[i];
                    x.record[i]=x.record[j];
                    x.record[j]=y;
                    
                }
            }
        }
        return x;
    }
    public
    Student searchStudentByFname(String fname) {
        SimpleSortStudentRecords x=this;

        int l = 0, r = x.studcounter - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            String ref = x.record[mid].getFirstName();
            if (ref.compareTo(fname) < 0) {
                l = mid + 1;
            } else if (ref.compareTo(fname) > 0) {
                r = mid - 1;
            } else if (ref.compareTo(fname) == 0) {
                return x.record[mid];
            }
        }
        return null;
    }
    public
    Student searchStudentByLname(String lname){
        SimpleSortStudentRecords x=this;

        int l = 0, r = x.studcounter - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            String ref = x.record[mid].getLastName();
            if (ref.compareTo(lname) < 0) {
                l = mid + 1;
            } else if (ref.compareTo(lname) > 0) {
                r = mid - 1;
            } else if (ref.compareTo(lname) == 0) {
                return x.record[mid];
            }
        }
        return null;
    }
    
}
class QuickSortStudentRecords extends StudentRecords{
    public QuickSortStudentRecords quickSortFname(){
        QuickSortStudentRecords x=this;
        x.sort_list_first(0,9);
        return x;
    }
    private int partition_first(int low,int high)
    {
        QuickSortStudentRecords x=this;

        String pivot =x.record[high].getFirstName();
        int i=low-1;
        for(int j=low; j<high;j++)
        {
            if((x.record[j].getFirstName()).compareTo(pivot)<0)
            {
                i+=1;
                Student temp=x.record[i];
                x.record[i]=x.record[j];
                x.record[j]=temp;
            }
        }
        Student temp=x.record[i+1];
                x.record[i+1]=x.record[high];
                x.record[high]=temp;
        return i+1;
    }
    public void sort_list_first(int low,int high)
    {
        if(low<high)
        {
            int par=partition_first(low, high);
            sort_list_first(low,par-1);
            sort_list_first(par+1,high);
        }
        
    }
    public QuickSortStudentRecords quickSortLname(){
        QuickSortStudentRecords x=this;
        x.sort_list_last(0,9);
        return x;
    }
    private int partition_last(int low,int high)
    {
        QuickSortStudentRecords x=this;

        String pivot =x.record[high].getLastName();
        int i=low-1;
        for(int j=low; j<high;j++)
        {
            if((x.record[j].getLastName()).compareTo(pivot)<0)
            {
                i+=1;
                Student temp=x.record[i];
                x.record[i]=x.record[j];
                x.record[j]=temp;
            }
        }
        Student temp=x.record[i+1];
                x.record[i+1]=x.record[high];
                x.record[high]=temp;
        return i+1;
    }
    public void sort_list_last(int low,int high)
    {
        if(low<high)
        {
            int par=partition_last(low, high);
            sort_list_last(low,par-1);
            sort_list_last(par+1,high);
        }
    }
    public
    Student searchStudentByFname(String fname) {
        QuickSortStudentRecords x=this;

        int l = 0, r = x.studcounter - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            String ref = x.record[mid].getFirstName();
            if (ref.compareTo(fname) < 0) {
                l = mid + 1;
            } else if (ref.compareTo(fname) > 0) {
                r = mid - 1;
            } else if (ref.compareTo(fname) == 0) {
                return x.record[mid];
            }
        }
        return null;
    }
    public
    Student searchStudentByLname(String lname){
        QuickSortStudentRecords x=this;

        int l = 0, r = x.studcounter - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            String ref = x.record[mid].getLastName();
            if (ref.compareTo(lname) < 0) {
                l = mid + 1;
            } else if (ref.compareTo(lname) > 0) {
                r = mid - 1;
            } else if (ref.compareTo(lname) == 0) {
                return x.record[mid];
            }
        }
        return null;
    }
}

public class S20200010234_StudentRecordsTestMain{
    public static void main(String[] args) {
        Student S1 = new Student(101,"Samyak","Bansal");
        Student S2 = new Student(102,"Abhay","Ray");
        Student S3 = new Student(103,"Shardul","Kurdukar");
        Student S4 = new Student(104,"Yash","Gupta");
        Student S5 = new Student(105,"Pranjay","Gupta");
        Student S6 = new Student(106,"Shobhit","Gupta");
        Student S7 = new Student(107,"Satya","Patnala");
        Student S8 = new Student(108,"Aritro","Ghosh");
        Student S9 = new Student(109,"Madhur","Saxena");
        Student S10 = new Student(110,"Sanju","Sabu");
        SimpleSortStudentRecords record= new SimpleSortStudentRecords();
        record.addStudent(S1);
        record.addStudent(S2);
        record.addStudent(S3);
        record.addStudent(S4);
        record.addStudent(S5);
        record.addStudent(S6);
        record.addStudent(S7);
        record.addStudent(S8);
        record.addStudent(S9);
        record.addStudent(S10);
        QuickSortStudentRecords record2= new QuickSortStudentRecords();
        record2.addStudent(S1);
        record2.addStudent(S2);
        record2.addStudent(S3);
        record2.addStudent(S4);
        record2.addStudent(S5);
        record2.addStudent(S6);
        record2.addStudent(S7);
        record2.addStudent(S8);
        record2.addStudent(S9);
        record2.addStudent(S10);
        SimpleSortStudentRecords fnamesorted= record.simpleSortFname();
        SimpleSortStudentRecords lnamesorted= record.simpleSortLname();
        System.out.println(fnamesorted.searchStudentByFname("Yash"));
        System.out.println(lnamesorted.searchStudentByLname("Gupta"));
        System.out.println(fnamesorted.searchStudentByFname("Pranjay"));
        System.out.println(lnamesorted.searchStudentByLname("Ray"));
        QuickSortStudentRecords fnamesorted2 = record2.quickSortFname();
        QuickSortStudentRecords lnamesorted2 = record2.quickSortLname();
        System.out.println(fnamesorted2.searchStudentByFname("Aritro"));
        System.out.println(lnamesorted2.searchStudentByLname("Ghosh"));
        System.out.println(fnamesorted2.searchStudentByFname("Aritro"));
        System.out.println(lnamesorted2.searchStudentByLname("Bansal"));
    }
}
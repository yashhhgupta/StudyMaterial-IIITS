import java.util.Arrays;
import java.util.Comparator;

class Employee{
    int id;
    String name;
    int salary;

    public Employee(String name,int id,  int salary){
        this.id = id;
        this.name = name;
        this.salary = salary;
    }
    public String getName(){
        return this.name;
    }
    public int getSalary(){
        return this.salary;
    }
    public int getId(){
        return this.id;
    }
    public void setName(String name){
        this.name = name;
    }
    public void setId(int id){
        this.id = id;
    }
    public void setSalary(int salary){
        this.salary = salary;
    }
}
interface Queue{
    void enqueue(Employee emp);
    Employee dequeue();
}
class ArrayQueue implements Queue{
    int f=-1;
    int r=-1;
    int size;
    Employee[] employee;

    public ArrayQueue(int size){
        this.size = size;
        employee = new Employee[size];
    }
    public void enqueue(Employee emp){
        if (f==-1 && r==-1) {
            f++;
            r++;
            employee[f]=emp;
        }
        else if(f==size-1) {
            System.out.println("Queue is full");

        }
        else {
            f++;
            employee[f]=emp;
        }
    }
    public Employee dequeue(){
        Employee ref=null;
        if (r==-1) {
            System.out.println("Queue is empty");
            
        }
        else if(r==-1) {
            ref = employee[r];
            r = -1;
            f = -1;
        }
        else {
            ref=employee[r];
            r++;
        }
        return ref;
    }
    int getQueueSize(){
        if(f == -1 && r == -1)return 0;
        return f-r+1;
    }
    int findById(int ref){
        int index = -1;
        for(int i = r; i <= f; i++){
            if(employee[i].id == ref){
                index = i;
                break;
            }
        }
        return index;
    }
    void emptyQueue(){
        int ref = f;
        for(int i = r; i <= ref; i++){
            dequeue();
        }
    }
    public void display() {
        Arrays.sort(employee, new Comparator<Employee>() {
            @Override
            public int compare(Employee o1, Employee o2) {
                if (o1 == null && o2 == null) {
                    return 0;
                }
                if (o1 == null || (o1.getId() > o2.getId())) {
                    return 1;
                }
                if (o2 == null || (o1.getId() < o2.getId())) {
                    return -1;
                }
                return 0;
            }
        });
        r = getQueueSize() - 1;
        f = 0;
        for (int i = 0; i <= r; i++) {
            System.out.println("Employee " + Integer.toString(i + 1));
            System.out.println("Name: " + employee[i].getName());
            System.out.println("Id: " + employee[i].getId());
            System.out.println("Salary: " + employee[i].getSalary());
        }
    }
}
public class S20200010234_QueueTest {
    public static  ArrayQueue doublesize(ArrayQueue queEmployee) {
        ArrayQueue temp = new ArrayQueue(5);
        temp = queEmployee;
        queEmployee = new ArrayQueue(10);
        for (int i = 0; i < temp.getQueueSize(); i++) {
            queEmployee.enqueue(temp.employee[i]);
        }
        return queEmployee;
    }
    public static void main(String[] args) {
        Employee obj1=new Employee("bholu", 1, 1000);
        Employee obj2=new Employee("ram", 2, 2000);
        Employee obj3=new Employee("shyam", 3, 3000);
        Employee obj4=new Employee("ramu", 4, 4000);
        Employee obj5=new Employee("poonam", 5, 5000);
        Employee obj6=new Employee("riya", 6, 5000);
        Employee obj7=new Employee("shreya", 7, 5000);
        Employee obj8=new Employee("priya", 8, 5000);
        Employee obj9=new Employee("priyanka", 9, 5000);
        Employee obj10=new Employee("shivam", 10, 5000);
        ArrayQueue que=new ArrayQueue(5);
        ArrayQueue newque;
        que.enqueue(obj1);
        que.enqueue(obj2);
        que.enqueue(obj3);
        newque=doublesize(que);
        newque.enqueue(obj4);
        newque.enqueue(obj5);
        newque.enqueue(obj6);
        newque.enqueue(obj7);
        newque.enqueue(obj8);
        newque.enqueue(obj9);
        newque.enqueue(obj10);
        System.out.println(newque.findById(5));
        newque.display();
        newque.dequeue();
        newque.dequeue();
        newque.dequeue();
        newque.dequeue();
        newque.dequeue();
        newque.dequeue();
    }
}

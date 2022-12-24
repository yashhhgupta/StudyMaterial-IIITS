import java.util.ArrayList;
import java.util.List;

class Employee {
    int EmployeeID;
    String Name;
    Double BasicPay;
    Double AllowancePay;
    public static int count = 0;

    public int getEmployeeID() {
        return EmployeeID;
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public Double getBasicPay() {
        return BasicPay;
    }

    public void setBasicPay(Double basicPay) {
        BasicPay = basicPay;
    }

    public Double getAllowancePay() {
        return AllowancePay;
    }

    public void setAllowancePay(Double allowancePay) {
        AllowancePay = allowancePay;
    }

    public String getDate() {
        return Date;
    }

    public void setDate(String date) {
        Date = date;
    }

    String Date;

    public Employee(String Name, Double BasicPay, Double AllowancePay, String Date) {
        this.Name = Name;
        this.BasicPay = BasicPay;
        this.AllowancePay = AllowancePay;
        this.Date = Date;
        setEmployeeID();
    }

    public void setEmployeeID() {

        this.EmployeeID = ++count;
    }

    public void calculateSalary() {
        double salary = BasicPay + AllowancePay;
        System.out.println("Employee ID: " + EmployeeID);
        System.out.println("Employee Salary: " + salary);
    }

    @Override
    public String toString() {
        return "Employee [AllowancePay=" + AllowancePay + ", BasicPay=" + BasicPay + ", Date=" + Date + ", EmployeeID="
                + EmployeeID + ", Name=" + Name + "]";
    }

}

class RegularEmployee extends Employee {

    int hikePercent;

    public RegularEmployee(String Name, Double BasicPay, Double AllowancePay, String Date, int hikePercent) {
        super(Name, BasicPay, AllowancePay, Date);
        this.hikePercent = hikePercent;
        setEmployeeID();

    }

    @Override
    public void calculateSalary() {
        String s[] = Date.split("-", 2);
        int year = Integer.parseInt(s[0]);
        Double salary;
        if (year > 2015) {
            salary = BasicPay + AllowancePay;
        } else {
            salary = BasicPay + AllowancePay + (BasicPay * hikePercent / 100);
        }
        System.out.println("Employee Salary: " + salary);
    }

    public int getHikePercent() {
        return hikePercent;
    }

    public void setHikePercent(int hikePercent) {
        this.hikePercent = hikePercent;
    }
}

class PartTimeEmpoyee extends Employee {
    int hoursWorked;

    public PartTimeEmpoyee(String Name, Double BasicPay, Double AllowancePay, String Date, int hoursWorked) {
        super(Name, BasicPay, AllowancePay, Date);
        this.hoursWorked = hoursWorked;
        setEmployeeID();
    }

    public int getHoursWorked() {
        return hoursWorked;
    }

    public void setHoursWorked(int hoursWorked) {
        this.hoursWorked = hoursWorked;
    }

    @Override
    public void calculateSalary() {
        Double salary = hoursWorked * getBasicPay();
        System.out.println("Employee ID: " + EmployeeID);
        System.out.println("Employee Salary: " + salary);
    }
}

public class EmployeeMain_S20200010234 {
    static List<Employee> empList = new ArrayList<Employee>();

    public static void main(String[] args) {
        Employee e1 = new Employee("Thomas", 40000.0, 2000.0, "2010-01-12");
        Employee e2 = new Employee("James", 20000.0, 2000.0,"2020-04-09");
        Employee e3 = new RegularEmployee("Percy", 20000.0, 2000.0, "2010-03-15", 10);
        Employee e4 = new RegularEmployee("Toby", 50000.0, 5000.0, "2000-06-15", 12);
        Employee e5 = new PartTimeEmpoyee("Gordon", 2000.0, 0.0,"2021-11-01", 30);
        Employee e6 = new PartTimeEmpoyee("Emily", 2000.0, 0.0, "2021-11-01", 60);

        empList.add(e1);
        empList.add(e2);
        empList.add(e3);
        empList.add(e4);
        empList.add(e5);
        empList.add(e6);

        for (Employee e : empList) {
            System.out.println(e);
            e.calculateSalary();
            System.out.println("\n");
        }
    }
}

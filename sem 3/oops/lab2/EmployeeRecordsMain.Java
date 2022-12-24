class Employee{
    int ID;
    String name;
    String role;
}
public class EmployeeRecordsMain{
    public static Employee[] records=new Employee[4];

    public static Employee createEmployee(int id,String name,String role){
        Employee e=new Employee();
        e.ID=id;e.name=name;e.role=role;
        return e;
    }
    public static void printEmployeeDetail(Employee e){
        if (e!=null){
        System.out.println("ID="+e.ID);
        System.out.println("Name="+e.name);
        System.out.println("Role="+e.role);
        System.out.println("--------------------------------------");
        }
    }
    public static Employee findEmployeeById(int id){

        int i;
        for(i=0;i<4;i++){
            if(id==records[i].ID){
                return records[i];
            }
        }
        return null;
    }
    public static Employee[] findEmployeeByRole(String s){
        Employee[] arra=new Employee[4];
        int j=0;
        for(int i=0;i<4;i++){
            if(s==records[i].role){
                arra[j]=records[i];
                j++;
            }
        }
        return arra;
    }
    public static Employee[] findEmployeeByName(String s){
        Employee[] arra=new Employee[4];
        int j=0;
        for(int i=0;i<4;i++){
            if(s==records[i].name){
                arra[j]=records[i];
                j++;
            }
        }
        return arra;
    }
    public static void main(String[] args){
        records[0]=createEmployee(1,"Jack","Manager");
        records[1]=createEmployee(2,"Jill","Engineer");
        records[2]=createEmployee(3,"Tom","Manager");
        records[3]=createEmployee(4,"Jack","Supervisor");

        Employee e1;
        e1=findEmployeeById(3);
        printEmployeeDetail(e1);
        System.out.println("--------------------------------------");
        System.out.println("--------------------------------------");

        Employee[] arr1=findEmployeeByRole("Manager");
        for(int i=0;i<4;i++){
            printEmployeeDetail(arr1[i]);
        }
        System.out.println("--------------------------------------");
        System.out.println("--------------------------------------");

        Employee[] arr=findEmployeeByName("Jack");
        for(int i=0;i<4;i++){
            printEmployeeDetail(arr[i]);
        }
    }
}
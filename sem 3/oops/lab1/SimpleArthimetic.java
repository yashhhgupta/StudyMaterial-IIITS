class SimpleArthimetic {
    public static void main(String[] args) {
        addnumbers();
        subnumbers();
        mulnumbers();
        divnumbers();
    }

    static void addnumbers(){
        int num1=10,num2=20;
        System.out.printf("Sum=%d\n",num1+num2);
    }

    static void subnumbers(){
        int num1=10,num2=20;
        System.out.printf("Difference=%d\n",num2-num1);
    }

    static void mulnumbers(){
        int num1=10,num2=20;
        System.out.printf("Multiplication=%d\n" ,num1*num2);
    }

    static void divnumbers(){
        int num1=10,num2=20;
        System.out.printf("Division=%d\n",num2/num1);
    }
}
class Point{
    float coordinateX;
    float coordinateY;
    public Point(float coordinateX, float coordinateY) {
        this.coordinateX = coordinateX;
        this.coordinateY = coordinateY;
    }
    void print()
    {
        System.out.println("X coordinate:"+coordinateX+" Y coordinate:"+coordinateY);
    }
}
class Rectangle{
    Point pointOne;
    Point pointTwo;
    public Rectangle(Point pointOne , Point pointTwo){
        this.pointOne = pointOne;
        this.pointTwo = pointTwo;
    }
    public float getHeight(){
        return(Math.abs(pointOne.coordinateY-pointTwo.coordinateY));
    }
    public float getWidth(){
        return(Math.abs(pointOne.coordinateX-pointTwo.coordinateX));
    }
    public float getAreaRectangle(){
        return(getWidth()*getHeight());
    }
    public boolean isSmaller(Rectangle r){
        return(this.getAreaRectangle()>r.getAreaRectangle());
    }
    public void print(){
        System.out.print("First Point of the Rectangle: ");
        this.pointOne.print();
        System.out.print("Second Point of the Rectangle: ");
        this.pointTwo.print();
        System.out.println("Height: "+this.getHeight());
        System.out.println("Width: "+this.getWidth());
        System.out.println("Area: "+this.getAreaRectangle());
    }
    public boolean isSmallerCircle(Circle c){
        return(this.getAreaRectangle()>c.getAreaCircle());
    }
}
class Circle{
    Point centrePoint;
    float radius;
    public Circle(Point centrePoint, float radius) {
        this.centrePoint = centrePoint;
        this.radius = radius;
    }
    public double getAreaCircle(){
        return(Math.PI*Math.sqrt(this.radius));
    }
    public boolean isSmaller(Circle c){
        return(this.getAreaCircle()>c.getAreaCircle());
    }
    public void print(){
        System.out.print("The Centre Point: ");
        this.centrePoint.print();
        System.out.println("Radius: "+this.radius);
        System.out.println("Area: "+this.getAreaCircle());
    }
    public boolean isSmallerRectangle(Rectangle r){
        return(this.getAreaCircle()>r.getAreaRectangle());
    }
}
public class ShapeComparisonMain {
    public static void main(String[] args) {
        Point p1 = new Point(0,0);
        Point p2 = new Point(5,6); 
        Rectangle r1 = new Rectangle(p1,p2);
        Point p3 = new Point(-2,-3);
        Rectangle r2 = new Rectangle(p1,p3);
        Circle c1 = new Circle(p1,5);
        Point p4 = new Point(2,4);
        Circle c2 = new Circle(p4,3);
        System.out.println("First Rectangle: ");
        r1.print();
        System.out.println("\nSecond Rectangle: ");
        r2.print();
        System.out.println("\nFirst Circle: ");
        c1.print();
        System.out.println("\nSecond Circle: ");
        c2.print();
        System.out.println("\nRectangle2<Rectangle1"+r1.isSmaller(r2));
        System.out.println("\nCircle2<Circle1 "+c1.isSmaller(c2));
        System.out.println("\nRectangle1>Circle1 "+r1.isSmallerCircle(c1));
        System.out.println("\nRectangle2>Circle1 "+r2.isSmallerCircle(c1));
        System.out.println("\nRectangle1<Circle2 "+c2.isSmallerRectangle(r1));
        System.out.println("\nRectangle2<Circle2 "+c2.isSmallerRectangle(r2));

        System.out.println("\nRectangle1>Circle1 "+c1.isSmallerRectangle(r1));
        System.out.println("\nRectangle2>Circle1 "+c1.isSmallerRectangle(r2));
        System.out.println("\nRectangle1<Circle2 "+r1.isSmallerCircle(c2));
        System.out.println("\nRectangle2<Circle2 "+r2.isSmallerCircle(c2));
    }    
}

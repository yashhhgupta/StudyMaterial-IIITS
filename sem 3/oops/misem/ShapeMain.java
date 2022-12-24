class Shape{
    double area;
    double perimeter;
    public Shape(double area, double perimeter) {
        this.area = area;
        this.perimeter = perimeter;
    }
}
class Circle extends Shape{
    public Circle (double area, double perimeter){
        super(area, perimeter);
    }
    public void findRadius(){
        
    }
}

public class ShapeMain {
    
}

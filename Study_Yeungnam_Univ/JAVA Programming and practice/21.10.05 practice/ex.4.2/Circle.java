public class Circle {
  private double x, y;
  private int radius;
  
  public Circle(double x, double y, int radius) {
    this.x = x;
    this.y = y;
    this.radius = radius;
  }

  public void show() {
    System.out.println("(" + x + "," + y + ")" + radius); //컴파일러가 x,y,radius를 문자열로 만들어 주는겁니다.
  }

}

/*내꺼
public class Circle {
  private double x, y;
  private int radius;
  
  public Circle(double x, double y, int radius) {
    this.x = x;
    this.y = y;
    this.radius = radius;
  }

  public void show() {
    System.out.println("(" + x + "," + y + ")"+radius);
  }

}
*/

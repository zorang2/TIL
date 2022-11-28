import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    
    Scanner scanner = new Scanner(System.in);
    Circle c [] = new Circle[3];
    for(int i=0; i<3 ; i++) { //for(int i=0; i<c.length; i++) 교수님추천코드, 왜? 배열이늘어나도 바로바로되니까
      System.out.println("x, y, radius >>");
      double x = scanner.nextDouble();
      double y = scanner.nextDouble();
      int radius = scanner.nextInt();
      c[i] = new Circle(x, y, radius); //Circle 객체생성파트
    }
    
    for(int i=0; i<c.length; i++)
      c[i].show(); //모든 Circle 객체 출력
    
    scanner.close();
  }
}

/* 
중간고사 언급 :

포털사이트에 시험겹치는 과목과 시간 적어라 그럼 조정해주겠다.(보통한시간씩뒤로무르심)
시험문제가 실습예제처럼나온다. 코드비워놓고 단답형으로 적으시오. (대부분)
코드지워놓고 결과를 적어라 등.

내 코드
import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    Circle c [] =
    for(int i=0; i<3 ; i++) {
      System.out.println("x, y, radius >>");
      double x = scanner.nextDouble();
      double y = scanner.nextDouble();
      int radius = scanner.nextInt();
      c[i] =
    }
    
    for(int i=0; i<c.length; i++) show(); //모든 Circle 객체 출력
    scanner.close();
  }
}
*/

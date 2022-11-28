//정수 3개를 입력 받아 중간값을 뽑아내시오. (평균값구하라는게아님.)


import java.util.Scanner;
public class h0204 {
  public static void main(String[] args) {
    Scanner s=new Scanner(System.in);
    
    int a,b,c;
    
    System.out.println("정수 3개 입력>>");
    a=s.nextInt();
    b=s.nextInt();
    c=s.nextInt();
    
    if(a<b && b<c)
      {System.out.println("중간 값은"+b+"입니다.");}
    else if(b<a && a<c)
      {System.out.println("중간 값은"+a+"입니다.");}
    else
      {System.out.println("중간 값은"+c+"입니다.");}
    
    s.close();
    
  }

}


/*
//논리연산자좀 쓰자!!
//조건연산자 잘모르면서 쓸려고했다.
//그냥 if로 가자.
import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.println("정수 3개를 입력하시오 : ");
    int a = scanner.nextInt();
    int b = scanner.nextInt();
    int c = scanner.nextInt();
    
    if ((a>=b)? 1 : -1){
      if ((a<=c)? 1 : -1)
        System.out.println("중간값은 " + a + " 입니다.");
    }
    
    else if(b>=c ? b : c){
      if (b<=a ? b : a)
        System.out.println("중간값은 " + b + " 입니다.");
    }
    else if(c>=a ? c : a){
      if (c<=a ? c : a)
        System.out.println("중간값은 " + c + " 입니다.");
    }
    

    scanner.close();
    
  }
}
*/
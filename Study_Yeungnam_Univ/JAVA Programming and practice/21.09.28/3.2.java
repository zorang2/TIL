import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int[] unit = {50000, 10000, 1000, 500, 100, 50, 10, 1};

    System.out.print("금액을 입력하세요>>");
    int money = scanner.nextInt();

    //for -each
    for(int x:unit) {
      int res = money / x;
      
      if(res > 0) {
        System.out.println(x + "원 짜리 : " + res +"개");
      }
      money = money % x;
    scanner.close();
    }

/*
    //for
    for(int i=0; i < unit.length; i++) {
      int res = money / unit[i];
        if(res > 0) {
          System.out.println(unit[i] + "원 짜리 : " + res +"개");
      }
      money = money % unit[1];
    scanner.close();
    }
*/


  }
}

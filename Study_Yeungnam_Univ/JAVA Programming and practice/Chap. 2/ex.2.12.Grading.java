// 다중 if-else문으로 학점매기기


//교재 코드 다적진않았고 이런느낌이고, System.out.println 1번밖에 안적었다는거에서 의미가있지.
import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.println("점수를 입력하세요~!");
    char grade;
    int score = scanner.nextInt();
    if (score >= 90)
      grade = 'A';
    else if ( score >= 80)
      grade = 'B';
    else
      grade = 'F';
    System.out.println("당신의 학점은 "+ grade + "입니다.");
    
  }
}

/* 내 코드
import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    System.out.print("점수를 입력하시오 : ");
    int number = scanner.nextInt();

    if (number >= 90)
      System.out.println("A학점입니다.");
    else if (90 > number && number >= 80)
      System.out.println("B학점입니다.");
    else if (80 > number && number >= 70)
      System.out.println("C학점입니다.");
    else
      System.out.println("공부를 너무 못하시네요..");
  }
}
*/

/*중첩 if-else문 사례
점수와 학년을 입력받아 60점 이상이면 합격,
미만이면 불합격을 출력한다.
4학년의 경우 70점 이상이어야 합격이다.
*/

import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    System.out.println("점수를 입력하세요(0~100) : ");
    double score = scanner.nextDouble();

    System.out.println("학년을 입력하세요(1~4) : ");
    int year = scanner.nextInt();

    if (score >= 60) {
      if(year != 4)
        System.out.println("합격!!");
      else if (score >=70)
        System.out.println("합격!");
      else
      System.out.println("불합격ㅠㅠ");
    }
    else
      System.out.println("불합겨규ㅠ");

    scanner.close();

    
  }
}
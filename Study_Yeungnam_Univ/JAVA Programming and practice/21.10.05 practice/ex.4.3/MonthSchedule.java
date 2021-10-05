import java.util.Scanner;

public class MonthSchedule {
  private int nDays;
  private Day[] days;

  public MonthSchedule(int nDays) {
    this.nDays = nDays;
    days = new Day[nDays];
  }

  
  public void run() {
    System.out.println("이번달 스케쥴 관리 프로그램.");

    Scanner scanner = new Scanner(System.in);

    while(true) {
      System.out.println("할일(입력:1, 보기:2, 끝내기:3) >>");
      int menu = scanner.nextInt();

      switch(menu) {
        case 1:
          input();
          break;
        case 2:
          view();
          break;
        case 3:
          System.out.println("프로그램을 종료합니다.");
          return;
          // finish(); 필요없겠대 어차피끝나니까??그런듯
          //break;
        default: // 입력한값이 1~3이아닌다른값일때
          System.out.println("다시 입력하세요!");
      }

      System.out.println();
      
    }
  }


  public void input() {
    System.out.print("날짜(1~"+nDays+")?");
    Scanner scanner = new Scanner(System.in);
    int day = scanner.nextInt();
    System.out.print("할일(빈칸없이입력)?");
    String work = scanner.next();
    if(day >=1 && day <=nDays) {
      days[day-1] = new Day();
      days[day-1].setWork(work);
    } else{
      System.out.println("날짜를 잘못 입력하셨습니다!");
    }
  }

  public void view() {
    System.out.print("날짜(1~"+nDays+")?");
    Scanner scanner = new Scanner(System.in);
    int day = scanner.nextInt();
    if(days[day-1] != null && day >=1 && day <=nDays) {
      System.out.print( (day)+"일의 할 일은 ");
      days[day-1].show();
    } else{
      System.out.println("날짜를 잘못 입력하셨거나, 할 일을 등록하지 않았습니다!");
    }
  }
}


/* 내 코드 ㅠㅠ.
public class MonthSchedule {
  public int input();
  public int view();
  public int finish();
}
*/

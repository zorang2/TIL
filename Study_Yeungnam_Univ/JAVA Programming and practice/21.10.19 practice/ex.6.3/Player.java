import java.util.Scanner;

public class Player{
  private String name;
  private final String[] s = {"가위", "바위", "보"};
  protected int select; // 1:가위, 2:바위, 3:보

  public Player(String name) {
    this.name = name;
  }

  public String getName() { return name;}

  public String getString() { return s[select-1];}

  public int turn() {
    Scanner scanner = new Scanner(System.in);

    while(true) {
      System.out.print(name + "[가위:1, 바위:2, 보:3, 종료:4]>>");
      try {
        select = scanner.nextInt();
      } catch(Exception e) {
        continue; // while문 첫번째로 돌아가는 거다.
      }
      if(select < 1 || select > 4) continue;
      return select;
    }
  }
}

/*내코드
package base;

public class MathRandom {
  public void M{
    int a = (int)(Math.random() * 3 + 1);
    
  }
}
*/

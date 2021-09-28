//교수님 code
class Main {
  public static void main(String[] args) {

    int sum = 0;
    for(String arg : args) {
      System.out.println(arg);
      try{
      sum += Integer.parseInt(arg);
      }
      catch(NumberFormatException e) {
        System.out.println(arg +"는 정수가 아님");
      }
    }

    System.out.println(sum);
  }
}





/* mycode
import java.util.Scanner;

class Main {
  public static void main(String[] args) {

    
    // TODO Auto-generated method stub
    int sum = scanner.next();
    for(int i=0; i<args.length; i++) {
       try {
          sum += Integer.parseInt(args[i]);
        }catch(NumberFormatException e) {
          continue;
        }
    }
    System.out.println(sum);

  }
}
*/

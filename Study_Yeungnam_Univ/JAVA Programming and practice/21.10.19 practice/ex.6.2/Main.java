/*
교수님이 디자인패턴gof책 추천하시네
더 deep한 내용임.
class 를 어케 만드는지 등.
추천한대.
gof가 아니더라도 ㄱㅊ

*/

import java.util.Calendar;



class Main {
  public static void main(String[] args) {
    Calendar now = Calendar.getInstance();

    int hour = now.get(Calendar.HOUR_OF_DAY);
    int min = now.get(Calendar.MINUTE);

    System.out.println("현재 시간"+hour+":"+min);
    //표준시간이라서그렇다. 서울은 +9시간.

    if (hour>4&&hour<=12)
      System.out.println("good morning");
    else if(hour > 12 && hour <=18)
      System.out.println("good afternoon");
    else if(hour >18 && hour <= 22)
      System.out.println("good evening");
    else
      System.out.println("good night!");

  }
}

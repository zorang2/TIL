//private class 나중에 볼 수 있는데 중급 넘어 가야 볼수 있다.

public class Grade{
  private int math;
  private int science;
  private int eng;

  public Grade(int math, int sci, int eng) {
    this.math = math;
    science = sci; // 얘는 구분이되니까 this 안쓴거다.
    this.eng = eng;
  }
//메소드와 생성자는 가능하면 public으로 해라.
  public int average() {
    return (math + science + eng) / 3;
  }

}

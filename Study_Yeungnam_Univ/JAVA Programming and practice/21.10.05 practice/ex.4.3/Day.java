// 교수님왈 : class 하나당 java 파일 하나 만드는게좋다.

class Day{
  private String work;
  public void setWork(String work) {
    this.work = work;
  }
  public String getWork() {
    return work;
  }
  public void show() {
    if(work != null){ //참조변수만있고 객체만있을때 ????뭔말? 책이랑다르대 교수님이고치셨대
      System.out.println(work+"입니다.");
    }else {
      System.out.println("없습니다.");
    }

  }
}


/* 교재처럼 이렇게 만드는게 아니다.
setWork, getWork이렇게 만들어야된다.
class Day{
  private String work;
  public void set(String work) {
    this.work = work;
  }
  public String get() {
    return work;
  }
}
*/

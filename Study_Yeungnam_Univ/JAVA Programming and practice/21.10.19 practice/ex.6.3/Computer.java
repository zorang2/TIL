public class Computer extends Player{
  public Computer(String name) {
    super(name);
  }

  @Override
  public int turn() {
    //난수 1~3
    select = (int)(Math.random() * 3) + 1;
    return select;
  }

}

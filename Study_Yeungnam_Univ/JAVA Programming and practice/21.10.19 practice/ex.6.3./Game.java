public class Game {
  private Player[] players = new Player[2];

  public Game() {
    players[0] = new Player("철수");
    players[1] = new Computer("컴퓨터");
  }

  public void run() {
    int player1, player2;
    while(true) {
      player1 = players[0].turn();
      player2 = players[1].turn();

      if(player1 == 4 || player2 == 4) break;

      System.out.println(players[0].getName()+" : " +players[0].getString()+", "+players[1].getName()+" : " +players[1].getString());

      int diff = player1 - player2;
      switch(diff) {
        case 0:
          System.out.println("비김");
          break;
        case -1:
        case 2:
          System.out.println(players[1].getName()+"이 이김");
          break;
        case 1:
        case -2:
          System.out.println(players[0].getName()+"이 이김");
          break;
      }
    }
  }
}

import javax.swing.*;

public class Main extends JFrame {
  public Main() {
    setTitle("Bullet Game");
    setDefaultCloseOperation(EXIT_ON_CLOSE);

    GamePanel p = new GamePanel();
    setContentPane( p );
    setSize(300,300);
    setResizable(false);
    setVisible(true);
    p.startGame();
  }

  public static void main(String[] args) {
    new Main();
  }
}



// class Main {
//   public static void main(String[] args) {
//     System.out.println("Hello world!");
//   }
// }

public class Main extends JFrame {
  public Main() {
    super("Lab13-1");
    setDefaultCloseOperation(EXIT_ON_CLOSE);
    setContentPane(new MyPanel());
    setSize(250,250);
    setVisible(true);
  }
  class MyPanel extends JPanle implements Runnable{
    private int x, y;

    public MyPanle() {
     x=100; y=100;
     this.addMouseListener(new MouseAdapter() {
       private Thread th = null;
       @Override
       public void mousePressed(MouseEvent e) {
         if(th == null) {
           th = new Thread(MyPanel.this);
           th.start();
         }
       }
     });
  }

    @Override
    protected void paintComponent(Graphics g){
      super.paintComponent(g);
      g.setColor(Color.MAGENTA);
      g.drawOval(x, y, 50,50);
      }
    @Override
    public void run() {
      while(true){
        //try-catch로 sleep감싸기
        Thread.sleep(400);
        x = (int)(Math.random() * this.getWidth());
        y = (int)(Math.random() * this.getHeigth());
        repaint();
      }
    }
  }

  public static void main(String[] args) {
    new Main();
  }
}

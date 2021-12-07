import javax.swing.*;

public class GamePanel extends JPanel {
  private JLabel baseLabel = new JLabel();
  private JLabel bulletLabel = new JLabel();
  private JLabel targetLabel;
  private Thread targetThread = null;
  
  public GamePanel() {
    setLayout(null);
    baseLabel.setSize(40,40);
    baseLabel.setOpaque(true);
    baseLabel.setBackground(color.BLACK);

    ImageIcon img = new ImageIcon("__MACOSX/._chicken.jpg");
    targetLabel = new JLabel(img);
    targetLabel.setSize( img.getIconWidth(), img.getIconHeight());

    bulletLabel.setSize(10, 10);
    bulletLabel.setOpaque(true);
    bulletLabel.setBackground(Color.RED);

    add(baseLabel);
    add(targetLabel);
    add(bulletLabel);

  }

  public void startGame() {
    baseLabel.setLocation(this.getWidth()/2 - baseLabel.getWidth()/2,
                          this.getHeight() - baseLabel.getHeight());
    bulletLabel.setLocation(this.getWidth()/2 - bulletLabel.getWidth()/2,
                          this.getHeight() - baseLabel.getHeight() - bulletLabel.getHeight());
    targetLabel.setLocation(0,0);
    targetThread = new TargetThread(targetLabel);
    targetThread.start();

    baseLabel.setFocusable(true);
    baseLabel.requestFocus();
    baseLabel.addKeyListener(new KeyAdapter( {
      private Thread bulletThread = null;
      @Override
      public void keyPressed(KeyEvent e){
        if(e.getKeyChar() == '\n') {
          if(bulletThread == null || !bulletThread.isAlive()) {
            bulletThread = new BulletThread(bulletLabel, targetLabel, targetThread);
            bulletThread.start();
          }
        }
      }
    }))

  }

  class TargetThread extends Thread {
    private Jcomponent target;

    public TargetThread(JComponent target) {
      this.target = target;
      target.setLocation(0, 0);
      target.getParent().repaint();
    }

    @Override
    public void run() {
      while(true) {
        int x = target.getX() + 5;
        int y = target.getY();

        if(x > GamePanel.this.getWidth()){
          target.setLocation(0,0);
        } else {
          target.setLocation(x,y);
        }

        target.getParent().repaint();
        try{
          sleep(20)
        } catch (InterruptedException e){
          target.setLocation(0,0)
          target.getParent().repaint();

          try {
            sleep(500);
          } catch (InterruptedException e){

          }
        }

      }
    }

  }

  class BulletThread extends Thread {
    private JComponent bullet;
    private JComponent target;
    private Thread targetThread;

    public BulletThread( JComponent bullet, JComponent target, Thread targetThread) {
      this.bullet = bullet;
      this.target = target;
      this.targetThread = targetThread;
    }

    @Override
    public void run() {
      while(true) {

        if(hit()) {
            targetThread.interrupt();
            bullet.setLocation(bullet.getParent().getWidth()/2 - bullet.getWidth()/2,
                              bullet.getParent().getHeight() - 40 - bullet.getHeight());
            bullet.getParent().repaint();
            return;
        }else{


        int x = bullet.getX();
        int y = bullet.getY() - 5;

        if( y < 0 ){
          bullet.setLocation(bullet.getParent().getWidth()/2 - bullet.getWidth()/2,
                            bullet.getParent().getHeight() - 40 - bullet.getHeight());
          bullet.getParent().repaint();
          return;
        }

        bullet.setLocation(x, y);
        bullet.getParent().repaint();

        try {
          sleep(20);
        } catch (InterruptedException e) { }
        }
      }
    }
  
    private boolean targetContains(int x, int y) {
      if( (target.getX() <= x) && (target.getX()+target.getWidth()-1) >= x && (target.getY() <= y) && (target.getY() + target.getHeight() - 1) >=y)
        return true;
      else
        return false;
    }

    private boolean hit(){
      if (targetContains(bullet.getX(), bullet.getY()) || targetContains(bullet.getX()+bullet.getWidth()-1, bullet.getY()) || targetContains(bullet.getX()_, bullet.getY()+bullet.getHeight()-1 || targetcontains(bullet.getX()+bullet.getWidth()-1, bullet.getY()+bullet.getHeight()-1)))
    }
    return true;
    else
    return false;
  
  }
}

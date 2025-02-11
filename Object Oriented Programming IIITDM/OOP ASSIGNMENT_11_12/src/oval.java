import java.applet.Applet;
import java.awt.*;

public class oval extends Applet{

    public void paint(Graphics g){
        g.setColor(Color.BLACK);
        g.drawLine(512,0,512,720);
        g.drawLine(0,360,1024,360);
        g.setColor(Color.red);
        g.drawOval(725,50,100,250);
        g.setColor(Color.yellow);
        g.fillOval(750,112,50,125);
        g.setColor(Color.green);
        g.fillOval(150,80,200,200);
        g.setColor(Color.black);
        g.drawString("HELLO",240,180);
        g.setColor(Color.BLUE);
        g.fillRect(110,475,300,150);
        g.setColor(Color.white);
        g.fillRect(185,512,150,75);



    }

}
/*
<applet code="oval.class" width="1024" height="720">
</applet>
*/
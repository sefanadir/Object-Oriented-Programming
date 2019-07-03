package javaapplication2;

import javax.swing.JFrame;

public class JavaApplication2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        JFrame window = new JFrame("Connect Four Game");
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.getContentPane().add(new ConnectFour(window));
        window.setBounds(300, 300, 800, 800);
        window.setVisible(true);
    }
}

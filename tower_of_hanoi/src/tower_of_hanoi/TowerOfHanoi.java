/**
 * Author: David Liu
 * 
 * Implementation of the puzzle Tower of Hanoi
 */
package tower_of_hanoi;

import javax.swing.JFrame;

public class TowerOfHanoi {

    public TowerOfHanoi() {
        JFrame frame = new JFrame("Tower of Hanoi");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        frame.getContentPane().add(new TowerOfHanoiPanel());
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
    /**
     * @param args
     */
    public static void main(String[] args) {

        new TowerOfHanoi();
    }

}

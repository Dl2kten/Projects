/**
 * 
 */
package tower_of_hanoi;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 * 
 *
 */
public class TowerOfHanoiPanel extends JPanel {

    private static final long serialVersionUID = -779718677727766024L;
    
    private final int WIDTH = 700, HEIGHT = 750, PANEL_HEIGHT = 125;
    private int num_of_disks;
    private boolean pause;
    private boolean playPressed;
    
    private JLabel title, sub_title;
    private JTextField num_of_disks_field;
    private JButton reset, stop, play;
    private TowerPanel tp;
    
    /**
     * Sets up display of main panel, adds title panel, game panel, and control panel
     */
    public TowerOfHanoiPanel() {
    	tp = new TowerPanel(num_of_disks);
    	
        setLayout(new BorderLayout());
        add(setup_title_panel(), BorderLayout.NORTH);
        add(tp, BorderLayout.CENTER);
        add(setup_control_panel(), BorderLayout.SOUTH);
        
        setPreferredSize(new Dimension(WIDTH, HEIGHT));
        setBackground(new Color(25, 200, 100));
    }

    /**
     * Sets up title panel
     * @return JPanel
     */
    private JPanel setup_title_panel() {
    	title = new JLabel("Tower of Hanoi!!!!");
        title.setFont(new Font("Algerian", Font.BOLD, 60));
        title.setForeground(new Color(50, 200, 25));
        sub_title = new JLabel("Challenge if you dare...");
        sub_title.setFont(new Font("Comic sans", Font.PLAIN, 20));
        sub_title.setForeground(new Color(50, 200, 25));
        
    	JPanel title_panel = new JPanel();
        title_panel.setPreferredSize(new Dimension(WIDTH, PANEL_HEIGHT));
        title_panel.setBackground(new Color(225, 200, 190));
        title_panel.add(title);
        title_panel.add(sub_title);
        
        return title_panel;
    }
    
    /**
     * Set up control panel, takes in number of disks as 
     * set by the user, button to reset puzzle if stuck,
     * button to show solution, button to pause/resume solution
     * @return
     */
    private JPanel setup_control_panel() {
        Listener listener = new Listener();
        
    	num_of_disks_field = new JTextField("Enter # of Disks here", 15);
        num_of_disks_field.setFont(new Font("Helvetica", Font.PLAIN, 20));
        num_of_disks_field.addActionListener(listener);
        
        reset = new JButton("Reset");
        reset.setFont(new Font("Helvetica", Font.BOLD, 20));
        reset.addActionListener(listener);
        
        stop = new JButton("Solution Stop/Resume");
        stop.setFont(new Font("Helvetica", Font.BOLD, 20));
        stop.addActionListener(listener);
        
        play = new JButton("Solution Play");
        play.setFont(new Font("Helvetica", Font.BOLD, 20));
        play.addActionListener(listener);
        
        JPanel control_panel = new JPanel();
        control_panel.setPreferredSize(new Dimension(WIDTH, PANEL_HEIGHT));
        control_panel.setBackground(new Color(180, 225, 190));
        control_panel.add(num_of_disks_field);
        control_panel.add(reset);
        control_panel.add(play);
        control_panel.add(stop);
        
        return control_panel;
    }
    
    /**
     *listener gets info entered into control panel and displays info
     *in game panel
     */
    private class Listener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			Object source = e.getSource();
			
			if(source == num_of_disks_field) { //get number of disks, between 0-10
				 if(!num_of_disks_field.getText().equals("1")
	                        && !num_of_disks_field.getText().equals("2") && !num_of_disks_field.getText().equals("3")
	                        && !num_of_disks_field.getText().equals("4") && !num_of_disks_field.getText().equals("5")
	                        && !num_of_disks_field.getText().equals("6") && !num_of_disks_field.getText().equals("7")
	                        && !num_of_disks_field.getText().equals("8") && !num_of_disks_field.getText().equals("9")
	                        && !num_of_disks_field.getText().equals("10"))
	                    num_of_disks_field.setText("Nums from 1 to 10 please.");
	                else {
	                    num_of_disks = Integer.parseInt(num_of_disks_field.getText());

	                    tp.setdisk_num(num_of_disks);
	                    tp.setReset(true);
	                    tp.setReset2(true);
	                    playPressed = false;
	                    tp.repaint();    
	                }
						
			}
			
			if(source == reset) { //reset puzzle
				tp.setReset(true);
				tp.setReset2(true);
				playPressed = false;
				tp.repaint();
			}
	            
			if(source == play) { //play solution
				if(!playPressed) {
					tp.setReset(true);
					tp.Solve();
					tp.setStop(false);
					tp.repaint();
					playPressed = true;
				} else {
					tp.setPlayMessage(true);
				}    
			}
	        
			if(source == stop) { //stops and resumes solution animation
                if(playPressed) {
                    if(!pause) {
                        tp.setStop(true);
                        pause = true;
                    } else {
                        tp.setStop(false);
                        pause = false;
                        tp.repaint();
                    }    
                } else {
                    tp.setStopMessage(true);
                    tp.repaint();
                }
			
			}
		}
		
    }
}

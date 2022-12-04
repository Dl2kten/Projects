/**
 * 
 */
package tower_of_hanoi;

import java.awt.Color;

import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.JPanel;
import javax.swing.Timer;

/**
 * Game Panel where the logic for game is implemented
 */
public class TowerPanel extends JPanel {
    private static final long serialVersionUID = -7019015821135856435L;
   
    private final int WIDTH = 700, HEIGHT = 500;
    private int xBar = 150, diskWidth = 40, diskHeight = 30, 
            disk_num, diskStart = 420, delay = 750, index, initialBarN, tempBarN,
            destinationBarN, initialBarTop, tempBarTop, 
            destinationBarTop, move, drop, barY, startP,
            bar, barValue, initialBar[], tempBar[], 
            destinationBar[], start[], destination[];
    
    private Boolean canMove, reset, invalid, finished, solutionPlay,
        reset2, stop, playMessage, stopMessage;
    private Disk disks[];
    private Point p, p2, p3;
    private Timer timer;
    
    /**
     * Initializes the variables, sets panel size, adds listeners
     * sets size and color of panel
     * @param n
     */
    public TowerPanel(int n) {
    	disk_num = n;
        index = 0;
        initialBarN = n;//this is to count the disks on each bar
        tempBarN = 0;
        destinationBarN = 0;
        initialBarTop = disk_num - initialBarN;
        tempBarTop = 0; 
        destinationBarTop = 0;
        
        initialBar = new int[disk_num];//if disk 0 dropped on disk 3, bar -
        //would paint disk 0, 1, need to change
        tempBar = new int[disk_num];
		destinationBar = new int[disk_num];
		start = new int[(int) Math.pow(2, disk_num) - 1];
		destination = new int[(int) Math.pow(2, disk_num) - 1];
		bar = 0;
		barValue = 0;//to track previous top bar value
		move = 0;//to track movements
		drop = 0;//to track drops
		barY = 50;
		startP = 0;//to change which bar to drag from
		
		playMessage = false;
		stopMessage = false;
		stop = null;
		reset2 = false;
		solutionPlay = false;
		finished = false;
		invalid = false;
		reset = false;
		canMove = false;
		p = new Point();
		p2 = new Point();
		p3 = new Point();
		
		timer = new Timer(delay, new Listener());
		addMouseListener(new Listener());
		addMouseMotionListener(new Listener());
		
		setPreferredSize(new Dimension(WIDTH, HEIGHT));
		setBackground(Color.white);		    
    }
    
    /**
     * Draws disks during movement and set up
     * @param g
     */
    public void drawDisks(Graphics g) {
    	 if(move == 0) { //move = 0, used as setup value draws the disks at beginning of game
    		 set_up_disks(g);
    	 }
    	 
    	 if(move == 1) {
    		 drag(g);
    	 }
    	 
    	//Drop location, whether it's over one of the 3 bars or not
         if(move == 2) {

             switch(drop) {
             case 0:
                 //Returns disk if not dropped on bars
                 if(startP == 0) {
                     drop = 1;
                     for(int i = 0; i < initialBar.length; i++) {
                         if(i == bar)
                             initialBar[i] = bar;
                     }
                     repaint();
                 }
                 
                 if(startP == 1) {
                     drop = 2;
                     for(int i = 0; i < tempBar.length; i++) {
                         if(i == bar)
                             tempBar[i] = bar;
                     }
                     repaint();
                 }
                 
                 if(startP == 2) {
                     drop = 3;
                     for(int i = 0; i < destinationBar.length; i++) {
                         if(i == bar)
                             destinationBar[i] = bar;
                     }
                     repaint();
                 }
                 break;
                 
             case 1:
                 barValue = initialBarTop;
                 initialBarTop = bar;
                 
                 g.fillRect(xBar + 5 - (disks[initialBarTop].getWidth() / 2), 
                         diskStart - (initialBarN) * (diskHeight + 5),
                         disks[initialBarTop].getWidth(), diskHeight);
                 
                 if(initialBarN != 0) {
                     if (initialBarTop > barValue){
                             drop = 0;
                             initialBarN--;
                             for(int i = 0; i < initialBar.length; i++) {
                                 if(initialBar[i] == initialBarTop)
                                     initialBar[i] = -1;
                             }
                             
                             switch(startP) {
                             case 1:
                                 for(int i = 0; i < tempBar.length; i++) {
                                     if(i == bar)
                                         tempBar[i] = bar;
                                 }
                                 break;
                             case 2:
                                 for(int i = 0; i < destinationBar.length; i++) {
                                     if(i == bar)
                                         destinationBar[i] = bar;
                                 }
                                 break;
                             default:
                                 System.out.println("Huh?");
                             }
                             
                             initialBarTop = barValue;
                             invalid = true;
                             repaint();
                         } else {
                             for(int i = initialBar.length - 1; i > 0; i--) {
                                 if(initialBar[i] != -1) {
                                     g.fillRect(xBar + 5 - (disks[i].getWidth() / 2), 
                                             diskStart, disks[i].getWidth(), diskHeight);
                                     diskStart -= diskHeight + 5;    
                                 }
                             }
                             
                             diskStart = 420;
                         }   
                 }

                 for(int i = tempBar.length - 1; i >= 0; i--) {
                     if(tempBar[i] != -1) {
                         g.fillRect(xBar + 205 - (disks[i].getWidth() / 2), 
                                 diskStart, disks[i].getWidth(), diskHeight);
                         diskStart -= diskHeight + 5;    
                     }
                         
                 }
                 diskStart = 420;

                 for(int i = destinationBar.length - 1; i >= 0; i--) {
                     if(destinationBar[i] != -1) {
                         g.fillRect(xBar + 405 - (disks[i].getWidth() / 2), 
                                 diskStart, disks[i].getWidth(), diskHeight);
                         diskStart -= diskHeight + 5;    
                     }
                         
                 }
                 diskStart = 420;

                 initialBarN++;//changed from having this statement in mouse released
                 break;

             case 2:
                 
                 barValue = tempBarTop;
                 tempBarTop = bar;
                
                 g.fillRect(xBar + 205 - (disks[tempBarTop].getWidth() / 2), 
                         diskStart - (tempBarN) * (diskHeight + 5),
                         disks[tempBarTop].getWidth(), diskHeight);
                 
                 for(int i = initialBar.length - 1; i >= 0; i--) {
                     if(initialBar[i] != -1) {
                         g.fillRect(xBar + 5 - (disks[i].getWidth() / 2), 
                                 diskStart, disks[i].getWidth(), diskHeight);
                         diskStart -= diskHeight + 5;    
                     }
                 }
                 diskStart = 420;

                 if(tempBarN != 0) {
                     if(tempBarTop > barValue) {
                         drop = 0;
                         tempBarN--;
                         for(int i = 0; i < tempBar.length; i++) {
                             if(tempBar[i] == tempBarTop)
                                 tempBar[i] = -1;
                         }
                         
                         switch(startP) {
                         case 0:
                             for(int i = 0; i < initialBar.length; i++) {
                                 if(i == bar)
                                     initialBar[i] = bar;
                             }
                             break;
                         case 2:
                             for(int i = 0; i < destinationBar.length; i++) {
                                 if(i == bar)
                                     destinationBar[i] = bar;
                             }
                             break;
                         default:
                             System.out.println("Huh?");
                         }
                         
                         tempBarTop = barValue;
                         invalid = true;
                         repaint();
                     } else {
                         for(int i = tempBar.length - 1; i > 0; i--) {
                             if(tempBar[i] != -1) {
                                 g.fillRect(xBar + 205 - (disks[i].getWidth() / 2), 
                                         diskStart, disks[i].getWidth(), diskHeight);
                                 diskStart -= diskHeight + 5;    
                             }
                                 
                         }
                         
                         diskStart = 420;
                     }

                 }
                 
                 for(int i = destinationBar.length - 1; i >= 0; i--) {
                     if(destinationBar[i] != -1) {
                         g.fillRect(xBar + 405 - (disks[i].getWidth() / 2), 
                                 diskStart, disks[i].getWidth(), diskHeight);
                         diskStart -= diskHeight + 5;    
                     }
                         
                 }
                 diskStart = 420;
                 
                 tempBarN++;
                 break;

             case 3:
                 barValue = destinationBarTop;
                 destinationBarTop = bar;
                 int correct = 0;
                 
                 g.fillRect(xBar + 405 - (disks[destinationBarTop].getWidth() / 2), 
                         diskStart - (destinationBarN)* (diskHeight + 5),
                         disks[destinationBarTop].getWidth(), diskHeight);
                 
                 for(int i = initialBar.length - 1; i >= 0; i--) {
                     if(initialBar[i] != -1) {
                         g.fillRect(xBar + 5 - (disks[i].getWidth() / 2), 
                                 diskStart, disks[i].getWidth(), diskHeight);
                         diskStart -= diskHeight + 5;    
                     }
                 }
                 diskStart = 420;

                 for(int i = tempBar.length - 1; i >= 0; i--) {
                     if(tempBar[i] != -1) {
                         g.fillRect(xBar + 205 - (disks[i].getWidth() / 2), 
                                 diskStart, disks[i].getWidth(), diskHeight);
                         diskStart -= diskHeight + 5;    
                     }
                         
                 }
                 diskStart = 420;

                if(destinationBarN != 0) {
                    if(destinationBarTop > barValue) {
                        drop = 0;
                        destinationBarN--;
                        for(int i = 0; i < destinationBar.length; i++) {
                            if(destinationBar[i] == destinationBarTop)
                                destinationBar[i] = -1;
                        }
                        
                        switch(startP) {
                        case 0:
                            for(int i = 0; i < initialBar.length; i++) {
                                if(i == bar)
                                    initialBar[i] = bar;
                            }
                            break;
                        case 1:
                            for(int i = 0; i < tempBar.length; i++) {
                                if(i == bar)
                                    tempBar[i] = bar;
                            }
                            break;
                        default:
                            System.out.println("Huh?");
                        }
                        destinationBarTop = barValue;
                        invalid = true;
                        repaint();
                    } else {
                        for(int i = destinationBar.length - 1; i > 0; i--) {
                            if(destinationBar[i] != -1) {
                                g.fillRect(xBar + 405 - (disks[i].getWidth() / 2), 
                                        diskStart, disks[i].getWidth(), diskHeight);
                                diskStart -= diskHeight + 5;    
                            }
                                
                        }
                        
                        diskStart = 420;
                    }
                }

                 for(int i = 0; i < destinationBar.length; i++) {
                    if(destinationBar[i] == i)
                        correct++;
                 }
                 
                 if(correct == disk_num) {
                     finished = true;
                     move = -1;
                     repaint();
                 }
                 
                 destinationBarN++;
                 break;
             default:
                 System.out.println("Huh?");
             } 
         }
    }
    
    /**
     * Responsible for drawing discs while they are being dragged
     * @param g
     */
    private void drag(Graphics g) {
    	 g.fillRect((int)(p.getX()), (int)(p.getY()), disks[bar].getWidth(),
                 disks[bar].getHeight());   
       
         for(int i = initialBar.length - 1; i >= 0; i--) {
             if(initialBar[i] != -1) {
                 g.fillRect(xBar + 5 - (disks[i].getWidth() / 2), 
                         diskStart, disks[i].getWidth(), diskHeight);
                 diskStart -= diskHeight + 5;    
             }
                 
         }
         diskStart = 420;

         for(int i = tempBar.length - 1; i >= 0; i--) {
             if(tempBar[i] != -1) {
                 g.fillRect(xBar + 205 - (disks[i].getWidth() / 2), 
                         diskStart, disks[i].getWidth(), diskHeight);
                 diskStart -= diskHeight + 5;    
             }
                 
         }
         diskStart = 420;

         for(int i = destinationBar.length - 1; i >= 0; i--) {
             if(destinationBar[i] != -1) {
                 g.fillRect(xBar + 405 - (disks[i].getWidth() / 2), 
                         diskStart, disks[i].getWidth(), diskHeight);
                 diskStart -= diskHeight + 5;    
             }
                 
         }
         diskStart = 420;
    }
    
    /**
     * Sets array for disks, and the number of disks on each bar
     */
    private void set_up_disks(Graphics g) {
    	disks = new Disk[disk_num];
        
        //disk 0 is smallest, creates the width and height for each disk, height same for all
        for(int i = 0; i < disk_num; i++) {
            disks[i] = new Disk(diskWidth + i * 25, diskHeight);
        }
        //Sets up the arrays for the bars
        for(int i = 0; i < disk_num; i++) {
            initialBar[i] = i;
        }
        //Sets values to -1 so not to draw the bars
        for(int i = 0; i < disk_num; i++) {
            tempBar[i] = -1;
        }
        
        for(int i = 0; i < disk_num; i++) {
            destinationBar[i] = -1;
        }
        
      //paints the disks
        for(int i = initialBarN - 1; i >= 0; i--) {
            g.fillRect(xBar + 5 - (disks[i].getWidth() / 2), 
                    diskStart, disks[i].getWidth(), diskHeight);
            diskStart -= diskHeight + 5;
        }
        diskStart = 420;
    }
    
    /**
     * Paints the bars on which to place the disks
     */
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        //bottom bar
        g.setColor(new Color(200, 200, 225));
        
        int y_pos = 50, pole_width = 10, pole_height = 400;
        
        //g.fillRect(intx, int y, WIDTH, HEIGHT);
        g.fillRect(0, 450, WIDTH, 20);
        
        //initial bar disks start on
        g.fillRect(xBar, y_pos, pole_width, pole_height);
        
        //intermediate bar
        g.fillRect(xBar + 200, y_pos, pole_width, pole_height);
        
        //destination bar
        g.fillRect(xBar + 400, y_pos, pole_width, pole_height);
        
        if(reset) {
        	reset_function();
        }
        
        if(reset2) {
        	reset2_function();
        }
        
      //End game messages
        if(!finished) {
            g.setFont(new Font("Helvetica", Font.PLAIN, 20));
            g.setColor(new Color(25, 25, 100));
            
            g.drawString("Move all disks from initial bar "
                    + "to destination bar", 0, 20);
            
            g.setFont(new Font("Helvetica", Font.PLAIN, 16));
            
            g.drawString("Initial Bar", xBar - 20, 490);
            g.drawString("Temporary Bar", xBar + 170, 490);
            g.drawString("Destination Bar", xBar + 370, 490);
            
            if(playMessage || stopMessage) {//To specify the effects of play and -
                                            //stop/resume button
                if(playMessage) {
                    g.setFont(new Font("Algerian", Font.BOLD, 16));
                    g.setColor(Color.red);
                    g.drawString("Solution already playing use pause/resume "
                            + "to stop/continue the solution", 0, 40);    
                }
                
                if(stopMessage) {
                    g.setFont(new Font("Algerian", Font.BOLD, 16));
                    g.setColor(Color.red);
                    g.drawString("Press solution play first.", 0, 40); 
                }
            } else {
                if(invalid) {
                    g.setFont(new Font("Algerian", Font.BOLD, 16));
                    g.setColor(Color.red);
                    g.drawString("Disks can only be placed upon larger disks or"
                            + " straight on the bar if no disks are present", 0, 40);
                } else {
                    g.drawString("Disks can only be placed upon larger disks or"
                            + " straight on the bar if no disks are present", 0, 40);
                }      
            }
        } else {
            g.setFont(new Font("Comic sans", Font.ITALIC, 40));
            g.setColor(new Color(10, 150, 20));
            
            if(disk_num == 1) {
                g.drawString("Congratulations.", 100, 150);
                g.drawString("You've accomplished", 
                        100, 200);
                g.drawString("what most toddlers could.", 100, 250);
                g.drawString("Add more disks!!", 100, 300);
            }
            
            if(disk_num == 2) {
                g.drawString("Congratulations.", 100, 150);
                g.drawString("That was well done.", 
                        100, 200);
            }
            
            if(disk_num == 3) {
                g.drawString("Congratulations.", 100, 150);
                g.drawString("That took some logic", 
                        100, 200);
                g.drawString("good job.", 100, 250);
            }
            
            if(disk_num == 4) {
                g.drawString("Congratulations!", 100, 150);
                g.drawString("Impressive.", 
                        100, 200);
            }
            
            if(disk_num == 5) {
                g.drawString("Congratulations!!", 100, 150);
                g.drawString("Who are you...", 
                        100, 200);
            }
            
            if(disk_num >= 6) {
                g.drawString("Congratulations!!!", 100, 150);
                g.drawString("Can't believe you took the", 
                        100, 200);
                g.drawString("time to do it.", 100, 250);
            }
        }
        
        //Section for solving the tower
        if(solutionPlay) {
            move = -1;
            g.setColor(new Color(100, 220, 100));
            
            for(int i = initialBar.length - 1; i >= 0; i--) {
                if(initialBar[i] != -1) {
                    g.fillRect(xBar + 5 - (disks[i].getWidth() / 2), 
                            diskStart, disks[i].getWidth(), diskHeight);
                    diskStart -= diskHeight + 5; 
                }
                    
            }
            
            diskStart = 420;
            
            for(int i = tempBar.length - 1; i >= 0; i--) {
                if(tempBar[i] != -1) {
                    g.fillRect(xBar + 205 - (disks[i].getWidth() / 2), 
                            diskStart, disks[i].getWidth(), diskHeight);
                    diskStart -= diskHeight + 5;  
                }        
            }
            
            diskStart = 420;
            
            for(int i = destinationBar.length - 1; i >= 0; i--) {
                if(destinationBar[i] != -1) {
                    g.fillRect(xBar + 405 - (disks[i].getWidth() / 2), 
                            diskStart, disks[i].getWidth(), diskHeight);
                    diskStart -= diskHeight + 5;  
                }        
            }
            
            diskStart = 420;
        }
        
        if(stop != null) {//To control timer
            if(stop) 
                timer.stop();
            else
                timer.start();
        }
        
        g.setColor(new Color(175, 190, 10));
        
        if(disk_num > 0)
            drawDisks(g);
    }
    
    
    private void reset_function() {
    	index = 0;
        initialBarN = disk_num;//this is to count the disks on each bar
        tempBarN = 0;
        destinationBarN = 0;
        initialBarTop = disk_num - initialBarN;
        tempBarTop = 0; 
        destinationBarTop = 0;
        
        bar = 0;
        barValue = 0;//to track previous top bar value
        move = 0;//to track movements
        drop = 0;//to track drops
        barY = 50;
        startP = 0;//to change which bar to drag from

        playMessage = false;
        stopMessage = false;
        finished = false;
        invalid = false;
        reset = false;
        canMove = false;
    }
    
    
    private void reset2_function() {
    	reset2 = false;
        initialBar = new int[disk_num];//if disk 0 dropped on disk 3, bar -
        //would paint disk 0, 1, need to change
        tempBar = new int[disk_num];
        destinationBar = new int[disk_num];
        start = new int[(int) Math.pow(2, disk_num) - 1];
        destination = new int[(int) Math.pow(2, disk_num) - 1];
        solutionPlay = false;
        stop = null;
        timer.stop();
    }
    
    
    
    private class Listener implements MouseListener, 
    MouseMotionListener, ActionListener {

    @Override
    public void mouseClicked(MouseEvent e) {
       
    }

    @Override
    public void mouseEntered(MouseEvent arg0) {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void mouseExited(MouseEvent arg0) {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void mousePressed(MouseEvent e) {
        p3 = e.getPoint();
        stopMessage = false;
        
        if(initialBarN > 0) {
            if(p3.getX() >= xBar + 5 - disks[initialBarTop].getWidth() / 2
                    && p3.getX() <= xBar + 5 + disks[initialBarTop].getWidth() / 2 
                    && p3.getY() >= diskStart - (initialBarN - 1) * (diskHeight + 5) 
                    && p3.getY() <= diskStart - (initialBarN - 1) * (diskHeight + 5) 
                    + diskHeight) {
                System.out.println("yes");
                canMove = true;//so mouse released doesn't add additional disks without mouse pressed
                invalid = false;
                move = 1;
                startP = 0;
                bar = initialBarTop;
                //Take out the bar from the array
                for(int i = 0; i < initialBar.length; i++) {
                    if(initialBar[i] == bar)
                        initialBar[i] = -1;
                }
                
                for(int i = initialBar.length - 1; i >= 0; i--) {
                    if(initialBar[i] > bar)
                        initialBarTop = initialBar[i];
                        
                }
                initialBarN--; //Is there a better place?
                repaint();
            }    
        }
        
        if(tempBarN > 0) {
            if(p3.getX() >= xBar + 205 - disks[tempBarTop].getWidth() / 2
                    && p3.getX() <= xBar + 205 + disks[tempBarTop].getWidth() / 2 
                    && p3.getY() >= diskStart - (tempBarN - 1) * (diskHeight + 5) 
                    && p3.getY() <= diskStart - (tempBarN - 1) * (diskHeight + 5) 
                    + diskHeight) {
                //System.out.println("yes"); testing coordinates
                canMove = true;
                invalid = false;
                move = 1;
                startP = 1;
                bar = tempBarTop;
                for(int i = 0; i < tempBar.length; i++) {
                    if(tempBar[i] == bar)
                        tempBar[i] = -1;
                }

                for(int i = tempBar.length - 1; i >= 0; i--) {
                    if(tempBar[i] > bar)
                        tempBarTop = tempBar[i];
                }
                tempBarN--; //Is there a better place?
                repaint();
            }
        }
             
        if(destinationBarN > 0) {
            if(p3.getX() >= xBar + 405 - disks[destinationBarTop].getWidth() / 2
                    && p3.getX() <= xBar + 405 + disks[destinationBarTop].getWidth() / 2 
                    && p3.getY() >= diskStart - (destinationBarN - 1) * (diskHeight + 5) 
                    && p3.getY() <= diskStart - (destinationBarN - 1) * (diskHeight + 5) 
                    + diskHeight) {
                //System.out.println("yes"); testing coordinates
                canMove = true;
                invalid = false;
                move = 1;
                startP = 2;
                bar = destinationBarTop;
                for(int i = 0; i < destinationBar.length; i++) {
                    if(destinationBar[i] == bar)
                        destinationBar[i] = -1;
                }

                for(int i = destinationBar.length - 1; i >= 0; i--) {
                    if(destinationBar[i] > bar)
                        destinationBarTop = destinationBar[i];
                }
                
                destinationBarN--; //Is there a better place?
                repaint();
            }
        }
    }

    @Override
    public void mouseReleased(MouseEvent e) {
        p2 = e.getPoint();
        drop = 0;
        
        if(canMove) {
            //If dropped over
            if(p2.getX() > xBar - disks[bar].getWidth()
                    && p2.getX() < xBar + disks[bar].getWidth()
                    && p2.getY() >= barY && p2.getY() <= barY + 400) {
                move = 2;
                drop = 1;
                for(int i = 0; i < initialBar.length; i++) {
                    if(i == bar) 
                        initialBar[i] = bar;
                }
                repaint();
            }
            
            if(p2.getX() > xBar + 200 - disks[bar].getWidth()
                    && p2.getX() < xBar + 200 + disks[bar].getWidth()
                    && p2.getY() >= barY && p2.getY() <= barY + 400) {
                move = 2;
                drop = 2;
                for(int i = 0; i < tempBar.length; i++) {
                    if(i == bar) 
                        tempBar[i] = bar;
                }
                repaint();
            }
            
            if(p2.getX() > xBar + 400 - disks[bar].getWidth()
                    && p2.getX() < xBar + 400 + disks[bar].getWidth()
                    && p2.getY() >= barY && p2.getY() <= barY + 400) {
                move = 2;
                drop = 3;
                for(int i = 0; i < destinationBar.length; i++) {
                    if(i == bar) 
                        destinationBar[i] = bar;
                }
                repaint(); 
            } 
            
            if(drop != 1 && drop != 2 && drop != 3) {
                move = 2;
                drop = 0;
                repaint();
            }
            
            canMove = false;
        }
    }

    @Override
    public void mouseDragged(MouseEvent e) {                
            p = e.getPoint();
            repaint();
    }

    @Override
    public void mouseMoved(MouseEvent arg0) {
        // TODO Auto-generated method stub
        
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(index == (int)(Math.pow(2, disk_num) - 1)) {
            timer.stop();
            stop = null;
        }
        
        if(index < (Math.pow(2, disk_num) - 1)) {
            switch(start[index]) {
            case 1:
                    bar = initialBarTop;
                    //Take out the bar from the array
                    for(int i1 = 0; i1 < initialBar.length; i1++) {
                        if(initialBar[i1] == bar)
                            initialBar[i1] = -1;
                    }
                    
                    for(int i1 = initialBar.length - 1; i1 >= 0; i1--) {
                        if(initialBar[i1] > bar)
                            initialBarTop = initialBar[i1];
                            
                    } 
                
                break;
            case 2:
                    bar = tempBarTop;
                    //Take out the bar from the array
                    for(int i1 = 0; i1 < tempBar.length; i1++) {
                        if(tempBar[i1] == bar)
                            tempBar[i1] = -1;
                    }
                    
                    for(int i1 = tempBar.length - 1; i1 >= 0; i1--) {
                        if(tempBar[i1] > bar)
                            tempBarTop = tempBar[i1];
                            
                    } 
                
                break;
            case 3:
                    bar = destinationBarTop;
                    //Take out the bar from the array
                    for(int i1 = 0; i1 < destinationBar.length; i1++) {
                        if(destinationBar[i1] == bar)
                            destinationBar[i1] = -1;
                    }
                    
                    for(int i1 = destinationBar.length - 1; i1 >= 0; i1--) {
                        if(destinationBar[i1] > bar)
                            destinationBarTop = destinationBar[i1];
                            
                    } 

                break;
            default:
                System.out.println("Huh?");
            }
            
            switch(destination[index]) {
            case 1:
                initialBarTop = bar;
                
                for(int j = 0; j < initialBar.length; j++) {
                    if(j == bar) 
                        initialBar[j] = bar;
                }
                
                break;
            case 2:
                tempBarTop = bar;
                
                for(int j = 0; j < tempBar.length; j++) {
                    if(j == bar) 
                        tempBar[j] = bar;
                }

                break;
            case 3:
                destinationBarTop = bar;
                
                for(int j = 0; j < destinationBar.length; j++) {
                    if(j == bar) 
                        destinationBar[j] = bar;
                }

                break;
            default:
                System.out.println("Huh?");
            }   
        }
            
        index++;
            
        repaint();        
    }
    
}
    
    public void Solve() {
        SolveTower s = new SolveTower(disk_num);
        s.solve();
        for(int i = 0; i < Math.pow(2, disk_num) - 1; i++) {
            System.out.println(s.getFrom()[i] + " "
                    + s.getTo()[i]);
            start[i] = s.getFrom()[i];
            destination[i] = s.getTo()[i];
        }
        solutionPlay = true;
            
    }
    
    public int getdisk_num() {
        return disk_num;
    }

    public void setdisk_num(int disk_num) {
        this.disk_num = disk_num;
    }

    public Boolean getReset() {
        return reset;
    }

    public void setReset(Boolean reset) {
        this.reset = reset;
    }
    
    public Boolean getSolutionPlay() {
        return solutionPlay;
    }

    public void setSolutionPlay(Boolean solutionPlay) {
        this.solutionPlay = solutionPlay;
    }

    public Boolean getReset2() {
        return reset2;
    }

    public void setReset2(Boolean reset2) {
        this.reset2 = reset2;
    }

    public Boolean getStop() {
        return stop;
    }

    public void setStop(Boolean stop) {
        this.stop = stop;
    }

    public Boolean getPlayMessage() {
        return playMessage;
    }

    public void setPlayMessage(Boolean playMessage) {
        this.playMessage = playMessage;
    }

    public Boolean getStopMessage() {
        return stopMessage;
    }

    public void setStopMessage(Boolean stopMessage) {
        this.stopMessage = stopMessage;
    }
}

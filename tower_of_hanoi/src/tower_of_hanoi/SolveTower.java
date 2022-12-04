/**
 * 
 */
package tower_of_hanoi;

/**
 * @author dl2kt
 *
 */
public class SolveTower {

    private int disks, count;
    private int[] from, to;
    
    public SolveTower(int disks) {
        this.disks = disks;
        count = 0;
        from = new int[(int) Math.pow(2, disks) - 1];
        to = new int[(int) Math.pow(2, disks) - 1];
    }
    
    public void solve() {
        if(disks > 0)
            moveTower(disks, 1, 3, 2);
    }
    
    public void moveTower(int diskNum, int start, int destination, 
            int temp) {
        
        if(diskNum == 1)
            moveOneDisk(start, destination);
        else {
            moveTower(diskNum - 1, start, temp, destination);
            moveOneDisk(start, destination);
            moveTower(diskNum - 1, temp, destination, start);
        }
    }
    
    public void moveOneDisk(int start, int destination) {
        from[count] = start;
        to[count] = destination;
        count++;
    }

    public int[] getFrom() {
        return from;
    }

    public void setFrom(int[] from) {
        this.from = from;
    }

    public int[] getTo() {
        return to;
    }

    public void setTo(int[] to) {
        this.to = to;
    }
    
}

/**
 * 
 */
package tower_of_hanoi;

/**
 * 
 *
 */
public class Disk {

    private int width, height;
    
    public Disk(int width, int height) {
        
        this.width = width;
        this.height = height;
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }
}

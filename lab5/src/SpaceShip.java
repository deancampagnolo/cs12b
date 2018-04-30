public class SpaceShip {

    int shields;
    int weapon;
    boolean dead;

    public SpaceShip(){
        dead = false;
    }

    public int getWeapon(){
        return weapon;
    }

    public boolean isDead(){return dead;}

    public void hit(int damage) {
        shields = shields - damage;
        if (shields < 0) {
            System.out.println("BOOM!!!");
            dead = true;
        }
    }
}

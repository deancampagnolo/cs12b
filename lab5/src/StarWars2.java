class StarWars2 {
    /*
     * Fight to the death between two ships.
     * On return one of the ships will be dead.
     * This method must NOT BE MODIFIED.
     */
    private void duel(SpaceShip x, SpaceShip t) {
        while (!x.isDead() && !t.isDead()) {
            x.hit(t.getWeapon());
            if (x.isDead()) {
                System.out.println(x + " is dead");
            } else {
                t.hit(x.getWeapon());
                if (t.isDead()) {
                    System.out.println(t + " is dead");
                }
            }
        }
    }

    /*
     * @param i - the index at which to start searching for the next Tie fighter
     * @param fighters - an array containing both Tie and XWing fighters
     * @return the first Tie fighter in the array at or beyond index i. -1 if
     *         there are no Tie fighters in the range i to the end of the array
     */
    private int nextTie(int i, SpaceShip[] fighters) {
        assert (i >= 0);
        while (i < fighters.length) {
            if (fighters[i] instanceof Tie) {
                return i;
            }
            i++;
        }
        return -1;
    }

    /*
     * @param i - the index at which to start searching for the next XWing fighter
     * @param fighters - an array containing both Tie and XWing fighters
     * @return the first XWing fighter in the array at or beyond index i. -1 if
     *         there are no XWing fighters in the range i to the end of the array
     */
    private int nextXWing(int i, SpaceShip[] fighters) {
        while (i < fighters.length) {
            if (fighters[i] instanceof XWing) {
                return i;
            }
            i++;
        }
        return -1;
    }

    /*
     * Simulate the battle between the XWing and Tie fighters in the given array.
     * @param the array of fighters, in no particular order.
     * The battle should proceed as it does in the StarWars class provided in the
     * reading. Specifically the first XWing in the array will battle the first Tie.
     * The winner of that will battle the next spaceship of the opposing type in the
     * array, and so on.
     */
    void battle(SpaceShip[] fighters) {
        int g = 0;
        int e = 0;
        int goodDeaths = 0;
        int evilDeaths = 0;

        while (nextXWing(g, fighters) != -1 && nextTie(e, fighters) != -1) {
            System.out.println("battling X-Wing #" + g + " versus Tie Fighter #" + e);
            duel(fighters[nextXWing(g, fighters)], fighters[nextTie(e, fighters)]);
            if (fighters[nextXWing(g, fighters)].isDead()) {
                g++;
                goodDeaths++;
            }
            if (fighters[nextTie(e, fighters)].isDead()) {
                e++;
                evilDeaths++;
            }
        }
        int initialGood = 0;
        int initialEvil = 0;
        int finalGood = 0;
        int finalEvil = 0;
        for (int i = 0; i < fighters.length; i++) {
            if (fighters[i] instanceof XWing) {
                initialGood ++;
                if(!fighters[i].isDead()){//if alive
                    finalGood ++;
                }
            } else {
                initialEvil ++;
                if(!fighters[i].isDead()){
                    finalEvil ++;
                }
            }

        }

        System.out.println();
        System.out.println("Battle Report:\t\tX-Wings\t\tTie Fighters");
        System.out.println("------------------------------------------------------");
        System.out.println();
        System.out.println("Initial ships:\t\t" + initialGood + "\t\t" + initialEvil);
        System.out.println();
        System.out.println("Killed ships:\t\t" + goodDeaths + "\t\t" + evilDeaths);
        System.out.println();
        System.out.println("Final ships:\t\t" + finalGood + "\t\t" + finalEvil);
        System.out.println();
        if (finalGood > finalEvil) {
            System.out.println("The rebel alliance is victorious!");
        } else {
            System.out.println("The dark side has conquered!");
        }
        System.out.println();
    }
}
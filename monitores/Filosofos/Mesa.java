package Filosofos;

class Mesa {

    private final int PENSANDO = 0;
    private final int HAMBRE = 1;
    private final int COMIENDO = 2;
    private int sillas;

    public Mesa() {
        sillas = 5;
    }

    public void setSillas(int _sillas) {
        sillas = _sillas;
    }

    public int getSillas() {
        return sillas;
    }

    public synchronized void tomarTenedor(int i) {
        estado("Pensando " + i);
        while () {
        } 
    }
    
    public synchronized void dejarTenedor(int i) {

    }

    public void probar(int i) {
    
    }

    private int getDerecha() {
        return ((i+sillas-1)%sillas);
    }

    private int getIzquierda() {
        return ((i+1)%sillas);
    }
}

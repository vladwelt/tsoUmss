package Filosofos;

class Filosofo extends Thread {

    private final int DELAY=2000;
    Mesa mesa;
    int numero;
    int estado;

    public Filosofo (Mesa _mesa, int _numero) {
        estado = 0;
        mesa = _mesa;
        numero = _numero;
    }

    public int getEstado() {
        return estado;
    }

    public void serEstado(int _estado) {
        estado = _estado;
    }

    public void comiendo() {
        mesa.estado("Comiendo   " + numero);
        try {
            sleep(DELAY);
        } catch (Exception e) {}
    }

    public void run() {
        mesa.tomar_tenedor(numero);
        comiendo();
        mesa.dejar_tenedor(numero);
    }
}

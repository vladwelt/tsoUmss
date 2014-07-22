package Multiprocesador;

class Proceso extends Thread {
    private final int DELAY=2000;
    private int numero;
    private String nombre;
    private Procesador procesador;

    public Proceso(String _nombre, Procesador _procesador) {
        nombre = _nombre;
        procesador = _procesador;
    }
    
    public void setNumero(int _numero) {
        numero = _numero;
    }

    public int setNumero() {
        return numero;
    }

    public void procesando() {
        procesador.estado("Procesando    " + numero);
        try {
            sleep(DELAY);
        } catch (Exception e) {}
    }
    
    public void run() {
        numero=procesador.solicitar_procesador(nombre);
        procesador.tomar_procesador(nombre,numero);
        procesando();
        procesador.salir_procesador(nombre);
    }
}


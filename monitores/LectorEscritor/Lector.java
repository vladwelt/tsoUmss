package LectorEscritor;

class Lector extends Thread {
    private final int DELAY = 5000;
    Documento document;
    public Lector(Documento _documento) {
        document = _documento;
    }

    private void leyendo() {
        document.estado("Leendo..\n");
        try {
            sleep(DELAY);
        } catch (Exception e)
        {}
    }
    
    public void run() {
        document.entrar_lector();
        leyendo();
        document.salir_lector();
    }
}

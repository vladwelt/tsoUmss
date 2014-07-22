package LectorEscritor;

class Escritor extends Thread {
    public final int DELAY = 3000;
    Documento documento;
    public Escritor(Documento _documento) {
        documento = _documento;
    }

    private void escribiendo() {
        documento.estado("Escribiendo...\n");
        try {
            sleep(DELAY);
        } catch(Exception e) {}
    }

    public void run() {
        documento.entrar_escritor();
        escribiendo();
        documento.salir_escritor();
    }
}

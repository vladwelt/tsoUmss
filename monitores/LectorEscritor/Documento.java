package LectorEscritor;

class Documento {
    int escritores;
    int lectores;

    public Documento(){
        escritores = 0;
        lectores = 0;
    }

    public synchronized void entrar_lector() {
        estado("Lector esperando");
        while(escritores>0) {
            try {
                wait();
            } catch (Exception e) {}
        }
        lectores++;
    }

    public synchronized void salir_lector() {
        estado("Lector Termina");
        lectores--;
        notify();
    }

    public synchronized void entrar_escritor() {
        estado("Escritor esperando");
        while(lectores>0 || escritores>0) {
            try {
                wait();
            } catch (Exception e) {}
        }
        escritores++;
    }

    public synchronized void salir_escritor() {
        estado("Escritor termina");
        escritores--;
        notify();
    }

    public void estado(String s) {
        System.out.println(s);
    }
}

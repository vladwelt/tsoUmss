package Multiprocesador;

class Principal {

    public static void main(String[] args) {
        Procesador procesar = new Procesador();
        Proceso proceso1 = new Proceso("Cmd", procesar);
        Proceso proceso2 = new Proceso("Total", procesar);
        Proceso proceso3 = new Proceso("Nuevo", procesar);
        proceso1.start();
        proceso2.start();
        proceso3.start();
    }

}


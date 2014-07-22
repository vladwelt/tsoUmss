package Multiprocesador;

class Procesador 
{
    private int procesos;
    private int proceso_actual;

    public Procesador() {
        procesos = 0;
        proceso_actual = 1;
    }

    public synchronized int solicitar_procesador(String nombre) {
        estado("Solcicitando... " + nombre + "\n Asignando numero :" + procesos);
        procesos++;
        return procesos;
    }

    public synchronized void tomar_procesador(String nombre,int numero) {
        while(numero != proceso_actual) {
            try {
                wait();
            } catch (Exception e) {}
        }
        //proceso_actual++;
        estado(nombre + "usando");
    }

    public synchronized void salir_procesador(String nombre) {
        estado(nombre + "dejando");
        proceso_actual++;
        notify();
    }

    public void estado(String mensaje) {
        System.out.println(mensaje+"\n");
    }
}

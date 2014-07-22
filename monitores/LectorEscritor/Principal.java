package LectorEscritor;

class Principal {
    public static void main(String []args) {
        Documento doc = new Documento();
        Lector le = new Lector(doc);
        Escritor es = new Escritor(doc);
        le.start();
        es.start();
    }
}

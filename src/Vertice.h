class Vertice {
    public:
        void setDato(int data) {
            dato = data;
        }

        void setID(int id) {
            ID = id;
        }

        int getDato() {
            return dato;
        }

        int getID() {
            return ID;
        }

    private:
        int ID, dato;
};
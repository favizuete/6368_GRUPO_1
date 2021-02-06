/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ec.edu.espe.vizuetefUMLQuiz.model;

/**
 *
 * @author Fausto Vizuete ESPE-DCCO
 */
public class A {

    private F f;
    private G g;

    public A() {
        f = new F();
        g = new G();
    }

    public A(F f, G g) {
        this.f = f;
        this.g = g;
    }

    @Override
    public String toString() {
        return "A{" + "f=" + f + ", g=" + g + '}';
    }

    /**
     * @return the f
     */
    public F getF() {
        return f;
    }

    /**
     * @param f the f to set
     */
    public void setF(F f) {
        this.f = f;
    }

    /**
     * @return the g
     */
    public G getG() {
        return g;
    }

    /**
     * @param g the g to set
     */
    public void setG(G g) {
        this.g = g;
    }

}

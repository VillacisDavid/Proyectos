/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Lista;

import javax.swing.JOptionPane;

/**
 *
 * @author david
 */
public class Main {
    public static void main(String[] args){
        Interfaz menu = new Interfaz();
        menu.setVisible(true);
        menu.setTitle("Lista de tareas");
        menu.setResizable(false);
        menu.setLocationRelativeTo(null);
    }
}

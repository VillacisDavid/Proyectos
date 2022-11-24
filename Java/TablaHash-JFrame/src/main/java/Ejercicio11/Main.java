/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Ejercicio11;
import javax.swing.JOptionPane;

/**
 *
 * @author david
 */
public class Main {
    public static void main(String[] args){
        int n= Integer.parseInt(JOptionPane.showInputDialog("Ingrese la cantidad de alumnos ")); 
        Menu Menu = new Menu(n);
        //Muestra el menú.
        Menu.setVisible(true);
        //Centra en la pantalla el menú.
        Menu.setLocationRelativeTo(null);
        
    }
}

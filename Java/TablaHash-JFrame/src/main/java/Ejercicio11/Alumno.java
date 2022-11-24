/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Ejercicio11;

/**
 *
 * @author david
 */
public class Alumno {
    private int Matricula;
    private String Nombre;
    private String Direccion;
    
    public Alumno( int codigo, String Nombre, String Direccion){
        this.Matricula = codigo;
        this.Nombre = Nombre;
        this.Direccion = Direccion;
    }

    public int getMatricula() {
        return Matricula;
    }

    public String getNombre() {
        return Nombre;
    }

    public String getDireccion() {
        return Direccion;
    }
}

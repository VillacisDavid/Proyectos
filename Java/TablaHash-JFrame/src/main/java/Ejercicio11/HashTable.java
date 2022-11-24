/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Ejercicio11;

import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author david
 */
public class HashTable {
    private static int EMPTY_NODE = -1;
    private static int LAZY_DELETED = -2;
    private static int FILLED_NODE = 0;
    private int tableSize;
    int[] Flag;
    int[] matriculas;
    String[] nombres;
    String[] direcciones;
    
    public HashTable(int tSize){
        tableSize = tSize;
        matriculas = new int[tSize+1];
        nombres = new String[tSize+1];
        direcciones = new String[tSize+1];
        Flag = new int[tSize+1];
        for (int i = 0; i < tSize; i++) {
            Flag[i] = EMPTY_NODE;
        }
    }
    
    int ComputeHash(int key, int n){
        int hash;
        int digCentrales;
        if(key<100){
            digCentrales= n; 
        }else{
            String keyString = Integer.toString(key);
            digCentrales = Integer.parseInt(keyString.substring(1, keyString.length()-1));
        }
        
        
        hash = digCentrales*(key*key)+1;
        
        return hash;
    }
    
    boolean InsertNode(Alumno x){
        int newHash;
        int hash = ComputeHash(x.getMatricula(),0);
        int hashValue = hash % tableSize; //indice
        for (int i = 0; i < tableSize; i++) {
            if(Flag[hashValue] == EMPTY_NODE || Flag[hashValue] == LAZY_DELETED){
                Flag[hashValue] = FILLED_NODE;
                matriculas[hashValue] = x.getMatricula();
                nombres[hashValue] = x.getNombre();
                direcciones[hashValue] = x.getDireccion();
                return true;
            }
            newHash = ComputeHash(hash,i);
            hashValue = newHash % tableSize;
        }
        return false;
    }
    
    boolean FindNode(int value){
        int newHash;
        int hash = ComputeHash(value,0);
        int hashValue = hash % tableSize; //indice
        for (int i = 0; i < tableSize; i++) {
            if(Flag[hashValue] == EMPTY_NODE){
                JOptionPane.showMessageDialog(null, "El número de matrícula buscado no se encuentra en la lista");
                return false;
            }
            if(Flag[hashValue] == FILLED_NODE && matriculas[hashValue] == value){
                JOptionPane.showMessageDialog(null, "Encontrado en indice: " + i
                + "\n Matricula: " + matriculas[i] + 
                        "   Nombre: " + nombres[i] +
                        "   Direccion " + direcciones[i]);
                return true;
            }
            newHash = ComputeHash(hash,i);
            hashValue = newHash % tableSize;
        }
        return false;
    }
    
    void llenarTabla(javax.swing.JTable Tabla){
        DefaultTableModel model = (DefaultTableModel) Tabla.getModel();
        Object RowData[] = new Object[4];
        model.setRowCount(0);
        for (int i = 0; i < tableSize; i++) {
            if(Flag[i] == FILLED_NODE){
                RowData[0] = i;
                RowData[1] = matriculas[i];
                RowData[2] = nombres[i];
                RowData[3] = direcciones[i];
                model.addRow(RowData);
            }
        }
    }
    
}
